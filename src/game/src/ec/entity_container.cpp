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

#include "component_container.hpp"
#include "entity_container.hpp"
#include "logger/logger.hpp"

// TODO set up for each entity, along with free
namespace
{
void free_component(Component_container& component_container,
                    const Component_id id,
                    const std::size_t index)
{
    switch (id)
    {
    case Component_id::physics:
        component_container.physics_components.free(index);
        break;
    case Component_id::render:
        component_container.render_components.free(index);
        break;
    default:
        LOG_WARN << "Unhandled free_component type : "
                 << static_cast<std::underlying_type<Component_id>::type>(id);
    }
}
}  // namespace

Entity_container::Entity_container(Component_container& component_container)
{
    std::size_t index = 0;
    for (auto& entity : m_container)
    {
        entity.second.free = [& container = m_container, index]() { container.free(index); };
        entity.second.free_component = [&component_container](const Component_id id,
                                                              const std::size_t index) {
            free_component(component_container, id, index);
        };
    }
}

Entity& Entity_container::get_new_entity()
{
    const auto res = m_container.get_free_elem();
    auto& entity = res.second.get();
    entity.id = m_next_free_id++;
    return entity;
}
