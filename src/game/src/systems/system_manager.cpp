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

#include "ec/component_container.hpp"
#include "ec/entity_container.hpp"
#include "system_manager.hpp"

System_manager::System_manager(Rendering_interface& rendering_interface)
    : m_render_system(rendering_interface)
{
}

void System_manager::update(float delta_time, const Component_container& component_container)
{
}

void System_manager::render(const Entity_container& entities,
                            const Component_container& component_container)
{
    const auto& phys_comp = component_container.physics_components;
    const auto& rend_comp = component_container.render_components;

    for (const auto& entity : entities)
    {
        if (entity.second.has_component(Component_id::physics) &&
            entity.second.has_component(Component_id::render))
        {
        }
    }
    // TODO for each entity
    // if has rend and phys comp => create rend struct
    // sort by texture id?
}
