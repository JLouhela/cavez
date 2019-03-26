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
#include "systems/input_system.hpp"
#include "systems/physics_system.hpp"
#include "systems/render_system.hpp"
#include "systems/throttle_system.hpp"

#include <cstdint>
#include <vector>

struct Component_container;
class Entity_container;
class Rendering_interface;
class Input_interface;
class Level;

struct System_manager_config
{
    std::int32_t world_width{0};
    std::int32_t world_height{0};
};

class System_manager
{
public:
    System_manager(const System_manager_config& cfg,
                   Rendering_interface& rendering_interface,
                   const Input_interface& input_interface);

    void update(float delta_time,
                Entity_container& entities,
                Component_container& component_container);

    void render(Cameras& cameras,
                const Level& level,
                const Entity_container& entity_container,
                const Component_container& component_container);

private:
    Input_system m_input_system;
    Render_system m_render_system;
    Throttle_system m_throttle_system;
    Physics_system m_physics_system;
    System_manager_config m_config;
};

#endif
