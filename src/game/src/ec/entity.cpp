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
    auto iter = std::find_if(components.begin(), components.end(),
                             [id](const Component_index& component) {
                                 return component.first == id;
                             });
    if (iter == components.end())
    {
        return;
    }
    free_component(id, iter->second);
    components.erase(iter);
}

std::size_t Entity::get_component_index(const Component_id id)
{
    auto iter = std::find_if(components.begin(), components.end(),
                             [id](const Component_index& component) {
                                 return component.first == id;
                             });
    return iter == components.end() ? -1 : iter->second;
}

void Entity::delete_entity()
{
    for (const auto& component : components)
    {
        free_component(component.first, component.second);
    }
    components.clear();
    free();
}
