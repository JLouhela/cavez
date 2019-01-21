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

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <utility>
#include <vector>
#include "component_id.hpp"

#include <unordered_map>

using Entity_id = std::int32_t;
constexpr Entity_id invalid_entity_id = -1;

using Component_index = std::pair<Component_id, std::size_t>;
using Bit_mask = std::uint32_t;

class Entity
{
public:
    void set_id(Entity_id id)
    {
        m_id = id;
    }

    Entity_id get_id() const
    {
        return m_id;
    }

    void delete_entity();

    bool add_component(Component_index index);

    // Remove component and free the memory for reuse.
    void remove_component(const Component_id id);

    // Attention: no access checking, first check with has_component before getting index.
    std::size_t get_component_index(const Component_id id);

    // Function for freeing the allocated entity for new use
    // Called on delete
    void set_free_function(std::function<void()> func)
    {
        m_free = func;
    }

    // Function for freeing the allocated component for new use.
    // Called on remove_component
    void set_free_component_function(std::function<void(Component_id, std::size_t index)> func)
    {
        m_free_component = func;
    }

    bool has_component(Component_id id) const;

private:
    Entity_id m_id{invalid_entity_id};
    std::unordered_map<Component_id, std::size_t> m_components;
    Bit_mask m_components_mask;

    // Free the allocated entity for new use
    // Private use only
    std::function<void()> m_free{nullptr};
    // Free the allocated component for new use
    // Private use only
    std::function<void(Component_id, std::size_t index)> m_free_component{nullptr};
};

#endif
