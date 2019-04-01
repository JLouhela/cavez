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

#include "systems/render_system.hpp"
#include <cstddef>
#include "ec/component_container.hpp"
#include "ec/entity_container.hpp"
#include "math/rect.hpp"
#include "rendering/render_items.hpp"
#include "rendering/rendering_interface.hpp"

namespace
{
std::vector<bool> get_pixels(const Level& level, const math::Rect& world_rect)
{
    std::vector<bool> pixels;
    pixels.reserve(world_rect.w * world_rect.h);
    const auto& env = level.get_environment();
    const std::size_t last_index = world_rect.x + world_rect.w + (level.get_width() * world_rect.h);
    for (std::size_t i = world_rect.x, w_counter = 0; i < last_index; ++i, ++w_counter)
    {
        if (w_counter >= world_rect.w)
        {
            i += level.get_width() - world_rect.w;
            w_counter = 0;
        }
        pixels.emplace_back(env[i] != Environment_type::blank);
    }
    return pixels;
}
}

Render_system::Render_system(Rendering_interface& rendering_interface)
    : m_rendering_interface{rendering_interface}
{
}

void Render_system::render(const Cameras& cameras,
                           const Entity_container& entity_container,
                           const Component_container& component_container)
{
    const auto& phys_comps = component_container.physics_components;
    const auto& rend_comps = component_container.render_components;

    for (const auto& entity : entity_container)
    {
        if (entity.second.has_component(Component_id::physics) &&
            entity.second.has_component(Component_id::render))
        {
            for (const auto& camera : cameras)
            {
                auto& pos =
                    phys_comps[entity.second.get_component_index(Component_id::physics)].pos;
                auto& rot =
                    phys_comps[entity.second.get_component_index(Component_id::physics)].rotation;

                auto& rend_comp =
                    rend_comps[entity.second.get_component_index(Component_id::render)];
                auto& tex_rect = rend_comp.texture_rect;
                const auto screen_rect = camera.get_screen_rect({static_cast<std::int32_t>(pos.x),
                                                                 static_cast<std::int32_t>(pos.y),
                                                                 tex_rect.w, tex_rect.h});
                // Not in screen
                if (!screen_rect.first)
                {
                    continue;
                }
                Render_tex render_tex{rend_comp.texture_index, screen_rect.second, rot};
                // TODO sort by tex id and render later?
                m_rendering_interface.render(render_tex);
            }
        }
    }
}

void Render_system::render(const Cameras& cameras, const Level& level)
{
    // TODO get buffer idx
    // get coordinate rects from camera
    // render ..
}
