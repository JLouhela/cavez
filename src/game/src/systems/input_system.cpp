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

#include "systems/input_system.hpp"
#include "ec/entity_container.hpp"

Input_system::Input_system(const Input_interface& input_interface)
    : m_input_interface{input_interface}
{
}

void Input_system::update(Entity_container& entity_container,
                          Component_container& component_container)
{
    // First update input components
    for (auto& input_component : component_container.input_components)
    {
        input_component.second.input_state =
            m_input_interface.get_state(input_component.second.input_id);
    }

    // Then update entities
    auto& phys_comps = component_container.physics_components;
    const auto& input_comps = component_container.input_components;

    for (const auto& entity : entity_container)
    {
        if (entity.second.has_component(Component_id::input) &&
            entity.second.has_component(Component_id::physics))
        {
            const auto& input_state =
                input_comps[entity.second.get_component_index(Component_id::input)].input_state;
            auto& rotation =
                phys_comps[entity.second.get_component_index(Component_id::physics)].rotation;

            if (input_state.throttle)
            {
                // TODO: add throttling component
                LOG_INFO << "THROTTLE!";
            }
            if (input_state.rotate_cw)
            {
                // TODO obviously the rotation rate should be in some component
                rotation = (rotation + 30) % 36000;
            }
            else if (input_state.rotate_ccw)
            {
                rotation = (rotation == 0) ? 35970 : rotation - 30;
            }
        }
    }
}
