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

#include "systems/terrain_collision_detect_system.hpp"
#include "level/environment_types.hpp"
#include "level/level.hpp"
#include "math/bresenham.hpp"
#include "math/vector.hpp"

namespace
{
std::vector<math::Vector2I> collides_with_terrain(const Level& level,
                                                  const std::vector<math::Vector2I>& ray)
{
    const auto level_width = level.get_width();
    const auto level_height = level.get_height();
    const auto& env = level.get_environment();
    std::vector<math::Vector2I> res;

    for (const auto& coord : ray)
    {
        if (coord.x < 0 || coord.x >= static_cast<std::int32_t>(level_width) || coord.y < 0 ||
            coord.y >= static_cast<std::int32_t>(level_height))
        {
            continue;
        }
        if (env[coord.x + (coord.y * level_width)] != Environment_type::blank)
        {
            res.emplace_back(coord);
        }
    }
    return res;
}

// TODO handle object wrapping screen
std::vector<std::vector<math::Vector2I>> get_lines(const math::Vector2F& from,
                                                   const math::Vector2F& to)
{
    return {math::bresenham::get_line(from, to)};
}
}  // namespace

std::vector<Terrain_collision_event> Terrain_collision_detect_system::update(
    float delta_time,
    Entity_container& entity_container,
    Component_container& component_container,
    const Level& level)
{
    const auto& phys_comps = component_container.physics_components;
    const auto& col_comps = component_container.collider_components;

    std::vector<Terrain_collision_event> res;
    for (const auto& entity : entity_container)
    {
        if (entity.second.has_component(Component_id::physics) &&
            entity.second.has_component(Component_id::collider))
        {
            const auto& prev_pos =
                col_comps[entity.second.get_component_index(Component_id::collider)].prev_pos;
            const auto& cur_pos =
                phys_comps[entity.second.get_component_index(Component_id::physics)].pos;
            // TODO handle screen wrap
            // from -> to is not sufficient as ship can warp
            const auto rays = get_lines(prev_pos, cur_pos);
            for (const auto& ray : rays)
            {
                const auto collisions = collides_with_terrain(level, ray);
                for (const auto& c : collisions)
                {
                    LOG_DEBUG << "Collision";
                    res.emplace_back(Terrain_collision_event{entity.second.get_id(), c.x, c.y});
                }
            }
        }
    }
    return res;
}
