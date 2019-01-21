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

#include "entity.hpp"

void Entity::remove_component(const Component_id id)
{
    auto iter =
        std::find_if(m_components.begin(), m_components.end(),
                     [id](const Component_index& component) { return component.first == id; });
    if (iter == m_components.end())
    {
        return;
    }
    m_free_component(id, iter->second);
    m_components.erase(iter);
    m_components_mask &= ~(1U << static_cast<decltype(m_components_mask)>(id));
}

std::size_t Entity::get_component_index(const Component_id id)
{
    auto iter =
        std::find_if(m_components.begin(), m_components.end(),
                     [id](const Component_index& component) { return component.first == id; });
    return iter->second;
}

void Entity::delete_entity()
{
    for (const auto& component : m_components)
    {
        m_free_component(component.first, component.second);
    }
    m_components.clear();
    m_free();
}

bool Entity::add_component(const Component_index index)
{
    auto iter = std::find_if(
        m_components.begin(), m_components.end(),
        [id = index.first](const Component_index& component) { return component.first == id; });

    if (iter != m_components.end())
    {
        return false;
    }

    m_components[index.first] = index.second;
    m_components_mask |= 1U << static_cast<decltype(m_components_mask)>(index.first);
    return false;
}

bool Entity::has_component(Component_id id) const
{
    return m_components_mask && (1U << static_cast<decltype(m_components_mask)>(id));
}
