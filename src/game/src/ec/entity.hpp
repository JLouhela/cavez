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

using Entity_id = std::int32_t;
constexpr Entity_id invalid_entity_id = -1;

using Component_index = std::pair<Component_id, std::size_t>;

// TODO judge whether this should be a class
struct Entity
{
    Entity_id id{invalid_entity_id};
    std::vector<Component_index> components;

    // Free the allocated entity for new use
    // Private use only
    std::function<void()> free{nullptr};
    // Free the allocated component for new use
    // Private use only
    std::function<void(Component_id, std::size_t index)> free_component{nullptr};

    // Delete entity: call free for each component and free the enetity
    void delete_entity();
    // Remove component, invoke free_component for it also
    void remove_component(const Component_id id);
    std::size_t get_component_index(const Component_id id);
};

#endif
