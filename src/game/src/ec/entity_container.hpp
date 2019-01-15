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

#ifndef ENTITY_CONTAINER_HPP
#define ENTITY_CONTAINER_HPP

#include <array>
#include <cstddef>
#include <cstdint>
#include "entity.hpp"

constexpr std::size_t max_entities = 1000;

class Entity_container
{
public:
    Entity_container();

    // TODO switch to static_array like component
    Entity& operator[](const std::size_t idx);

    const Entity& operator[](const std::size_t idx) const;

    Entity& get_new_entity();

private:
    std::size_t find_next_free_index();

    Entity_id m_next_free_id{1};
    std::size_t m_next_free_index{0};
    std::array<Entity, max_entities> m_container;
};

#endif
