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

#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "camera/cameras.hpp"
#include "math/vector.hpp"
#include "systems/camera_follow_system.hpp"
#include "systems/collider_update_system.hpp"
#include "systems/input_system.hpp"
#include "systems/physics_system.hpp"
#include "systems/render_system.hpp"
#include "systems/terrain_collision_detect_system.hpp"
#include "systems/throttle_system.hpp"

#include <cstdint>
#include <vector>

struct Component_container;
class Entity_container;
class Rendering_interface;
class Input_interface;
class Level;

class System_manager
{
public:
    System_manager(Rendering_interface& rendering_interface,
                   const Input_interface& input_interface);

    void set_world_bounds(const math::Vector2I& bounds);

    void update(float delta_time,
                Cameras& cameras,
                Entity_container& entities,
                Component_container& component_container,
                Level& level);

    void render(Cameras& cameras,
                const Level& level,
                const Entity_container& entity_container,
                const Component_container& component_container);

private:
    Input_system m_input_system;
    Render_system m_render_system;
    Throttle_system m_throttle_system;
    Physics_system m_physics_system;
    Camera_follow_system m_camera_follow_system;
    Terrain_collision_detect_system m_terrain_collision_detect_system;
    Collider_update_system m_collider_update_system;
};

#endif
