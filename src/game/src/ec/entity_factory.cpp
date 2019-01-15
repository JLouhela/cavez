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

#include <tuple>
#include "component_container.hpp"
#include "component_id.hpp"
#include "entity_container.hpp"
#include "math/vector.hpp"

namespace factory
{
Entity& create_debug_entity(Entity_container& entity_container,
                            Component_container& component_container)
{
    auto& entity = entity_container.get_new_entity();
    auto& phys_comp = component_container.physics_components.get_free_elem();
    entity.components.emplace_back(Component_id::physics, phys_comp.first);
    phys_comp.second.get().pos = math::Vector2{10, 10};
    phys_comp.second.get().velocity = math::Vector2{1, 1};
    return entity;
}
}  // namespace factory
