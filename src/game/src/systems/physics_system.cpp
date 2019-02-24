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

#include "systems/physics_system.hpp"

#include <algorithm>
#include <cstdint>

namespace
{
void cap_velocity(math::Vector2F& velocity)
{
    static constexpr float max_speed = 200.f;
    velocity.x = std::min(velocity.x, max_speed);
    velocity.y = std::min(velocity.y, max_speed);
}
}  // namespace

Physics_system::Physics_system(std::int32_t world_width, std::int32_t world_height)
    : m_world_width{world_width}, m_world_height{world_height}
{
}

void Physics_system::update(float delta_time, Component_container& component_container)
{
    static constexpr float gravity = 100.0f;
    for (auto& component : component_container.physics_components)
    {
        if (!component.first)
        {
            continue;
        }
        component.second.velocity += component.second.force / component.second.mass * delta_time;
        component.second.velocity += math::Vector2F{0, gravity * delta_time};
        cap_velocity(component.second.velocity);
        component.second.pos += (component.second.velocity * delta_time);
        if (component.second.pos.y > m_world_height)
        {
            component.second.pos.y -= m_world_height;
        }
        else if (component.second.pos.y < 0)
        {
            component.second.pos.y += m_world_height;
        }
        if (component.second.pos.x > m_world_width)
        {
            component.second.pos.x -= m_world_width;
        }
        else if (component.second.pos.x < 0)
        {
            component.second.pos.x += m_world_width;
        }
    }
}
