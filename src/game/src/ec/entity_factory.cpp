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

#include "entity_factory.hpp"
#include "assets/texture_id.hpp"
#include "component_id.hpp"
#include "ec/component_container.hpp"
#include "entity.hpp"
#include "entity_container.hpp"
#include "input/input_interface.hpp"
#include "input/input_mapping.hpp"
#include "math/vector.hpp"

Entity_factory::Entity_factory(Entity_container& entity_container,
                               Component_container& component_container,
                               Input_interface& input_interface)
    : m_entity_container{entity_container},
      m_component_container{component_container},
      m_input_interface{input_interface}
{
}

Entity& Entity_factory::create_debug_entity()
{
    auto& entity = m_entity_container.get_new_entity();
    auto& phys_comp = m_component_container.physics_components.get_free_elem();
    entity.add_component({Component_id::physics, phys_comp.first});
    phys_comp.second.get().pos = math::Vector2F{8.f, 8.f};
    phys_comp.second.get().velocity = math::Vector2F{0.f, 0.f};

    auto& render_comp = m_component_container.render_components.get_free_elem();
    render_comp.second.get().texture_rect = {0, 0, 6, 6};
    render_comp.second.get().texture_index = asset::texture::ship_tex;
    entity.add_component({Component_id::render, render_comp.first});

    auto& input_comp = m_component_container.input_components.get_free_elem();
    input_comp.second.get().input_id = m_input_interface.register_listener(
        {input::Key::key_w, input::Key::key_d, input::Key::key_a, input::Key::key_l_shift,
         input::Key::key_q, input::Key::key_s});

    entity.add_component({Component_id::input, input_comp.first});

    return entity;
}
