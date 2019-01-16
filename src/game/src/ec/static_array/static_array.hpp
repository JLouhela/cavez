/// Copyright (c) 2019 Joni Louhela
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to
/// deal in the Software without restriction, including without limitation the
/// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
/// sell copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
/// IN THE SOFTWARE.

#ifndef STATIC_ARRAY_HPP
#define STATIC_ARRAY_HPP

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <utility>
#include "logger/logger.hpp"

template <typename T, std::size_t size>
class Static_array
{
public:
    Static_array()
    {
        m_container.fill(std::make_pair(false, T{}));
    }

    T& operator[](const std::size_t idx)
    {
        return m_container[idx].second;
    }

    const T& operator[](const std::size_t idx) const
    {
        return m_container[idx].second;
    }

    inline void free(const std::size_t idx)
    {
        m_container[idx].first = false;
        m_idx_hint = idx;
    }

    std::pair<std::size_t, std::reference_wrapper<T>> get_free_elem()
    {
        // TODO handle overflow
        const auto idx = find_next_free_index();
        m_idx_hint = idx + 1;
        m_container[idx].first = true;
        return std::make_pair(idx, std::ref(m_container[idx].second));
    }

    typename std::array<std::pair<bool, T>, size>::iterator begin()
    {
        return m_container.begin();
    }
    typename std::array<std::pair<bool, T>, size>::const_iterator cbegin()
    {
        return m_container.cbegin();
    }
    typename std::array<std::pair<bool, T>, size>::iterator end()
    {
        return m_container.end();
    }
    typename std::array<std::pair<bool, T>, size>::const_iterator cend()
    {
        return m_container.cend();
    }

private:
    inline std::size_t find_next_free_index()
    {
        auto iter = m_container.begin();
        std::advance(iter, m_idx_hint);
        for (; iter != m_container.end(); ++iter)
        {
            if (iter->first == false)
            {
                return std::distance(m_container.begin(), iter);
            }
        }
        return find_next_free_index_from_begin();
    }
    inline std::size_t find_next_free_index_from_begin()
    {
        for (auto iter = m_container.begin(); iter != m_container.end(); ++iter)
        {
            if (iter->first == false)
            {
                return std::distance(m_container.begin(), iter);
            }
        }
        LOG_ERR << "No free array element!";
        return m_container.size();
    }

    // value.first represent whether the value is in use or not
    std::array<std::pair<bool, T>, size> m_container;
    std::size_t m_idx_hint{0};
};

#endif
