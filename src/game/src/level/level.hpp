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

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <cstdint>
#include <vector>
#include "assets/texture_id.hpp"
#include "level/environment_types.hpp"

class Level
{
public:
    Level() = default;
    Level(std::vector<Environment_type> environment,
          std::uint32_t width,
          std::uint32_t height,
          std::int32_t buffer_idx);

    const std::vector<Environment_type> get_environment() const
    {
        return m_environment;
    }

    std::uint32_t get_width() const
    {
        return m_width;
    }

    std::uint32_t get_height() const
    {
        return m_height;
    }

    std::int32_t get_buffer_index() const
    {
        return m_buffer_idx;
    }

private:
    std::vector<Environment_type> m_environment;
    std::uint32_t m_width;
    std::uint32_t m_height;
    std::int32_t m_buffer_idx{-1};
};

#endif
