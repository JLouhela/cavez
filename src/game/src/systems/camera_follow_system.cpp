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

#include "systems/camera_follow_system.hpp"
#include "ec/entity_container.hpp"
#include "logger/logger.hpp"

#include <algorithm>
#include <cstdint>

void Camera_follow_system::update(float delta_time,
                                  Cameras& cameras,
                                  Entity_container& entity_container,
                                  Component_container& component_container)

{
    const auto& input_comps = component_container.input_components;
    for (const auto& entity : entity_container)
    {
        if (entity.second.has_component(Component_id::camera_follow) &&
            entity.second.has_component(Component_id::physics))
        {
            const auto& phys_comp =
                component_container
                    .physics_components[entity.second.get_component_index(Component_id::physics)];
            const auto& cam_comp =
                component_container.camera_follow_components[entity.second.get_component_index(
                    Component_id::camera_follow)];

            auto camera_it = std::find_if(cameras.begin(),
                                          cameras.end(), [id = cam_comp.camera_id](auto& camera) {
                                              return camera.get_id() == id;
                                          });
            if (camera_it == cameras.end())
            {
                LOG_WARN << "No camera with id : " << cam_comp.camera_id;
                continue;
            }
            camera_it->center_position(math::vector_cast<std::int32_t>(phys_comp.pos));
        }
    }
}
