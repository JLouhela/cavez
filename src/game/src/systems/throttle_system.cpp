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

#include "systems/throttle_system.hpp"
#include "math/angle_utils.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>

namespace
{
void cap_force(math::Vector2F& force)
{
    static constexpr float max_force = 1500.f;
    force.x = std::clamp(force.x, -max_force, max_force);
    force.y = std::clamp(force.y, -max_force, max_force);
}
}  // namespace

void Throttle_system::update(float delta_time,
                             Entity_container& entity_container,
                             Component_container& component_container)
{
    for (const auto& entity : entity_container)
    {
        if (entity.second.has_component(Component_id::throttle) &&
            entity.second.has_component(Component_id::physics))
        {
            auto& physics_comps = component_container.physics_components;
            auto& force =
                physics_comps[entity.second.get_component_index(Component_id::physics)].force;

            auto& throttle_comps = component_container.throttle_components;
            if (throttle_comps[entity.second.get_component_index(Component_id::throttle)]
                    .throttling == true)
            {
                auto& rotation =
                    physics_comps[entity.second.get_component_index(Component_id::physics)]
                        .rotation;

                static constexpr float thrust_modifier = 10000;
                const float thrust_speed =
                    throttle_comps[entity.second.get_component_index(Component_id::throttle)]
                        .thrust_force *
                    thrust_modifier;
                force +=
                    {std::sin(math::angle_utils::deg_to_rad(rotation)) * thrust_speed * delta_time,
                     std::cos(math::angle_utils::deg_to_rad(rotation + 180.f)) * thrust_speed *
                         delta_time};
                cap_force(force);
            }
        }
    }
}
