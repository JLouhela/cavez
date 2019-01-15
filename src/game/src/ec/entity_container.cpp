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

#include "entity_container.hpp"
#include "logger/logger.hpp"

Entity_container::Entity_container()
{
    m_container.fill(invalid_entity);
}

Entity& Entity_container::operator[](const std::size_t idx)
{
    return m_container[idx];
}

const Entity& Entity_container::operator[](const std::size_t idx) const
{
    return m_container[idx];
}

Entity& Entity_container::get_new_entity()
{
    const auto idx = find_next_free_index();
    auto& entity = m_container[idx];
    entity.id = m_next_free_id++;
    entity.free = [& container = m_container, idx]() {
        // TODO think about impact to m_next_free_idx
        // TODO free components assigned to the entity
        LOG_WARN << "Freeing an entity does not free components!";
        container[idx] = invalid_entity;
    };
    return entity;
}

std::size_t Entity_container::find_next_free_index()
{
    LOG_WARN << "Find next free index not properly implemented!";
    return m_next_free_index++;
}
