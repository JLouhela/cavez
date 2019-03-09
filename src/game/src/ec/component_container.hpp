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

#ifndef COMPONENT_CONTAINER_HPP
#define COMPONENT_CONTAINER_HPP

#include <array>
#include <cstddef>
#include <cstdint>
#include "component_id.hpp"
#include "components/input_component.hpp"
#include "components/physics_component.hpp"
#include "components/render_component.hpp"
#include "components/throttle_component.hpp"
#include "static_array/static_array.hpp"

constexpr std::size_t max_components = 1000;

using Physics_components = Static_array<Physics_component, max_components>;
using Render_components = Static_array<Render_component, max_components>;
using Throttle_components = Static_array<Throttle_component, max_components>;
using Input_components = Static_array<Input_component, 8>;

struct Component_container
{
    Physics_components physics_components;
    Render_components render_components;
    Input_components input_components;
    Throttle_components throttle_components;
};

#endif
