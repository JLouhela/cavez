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

#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include <cstdint>
#include "math/vector.hpp"

struct Physics_component
{
    math::Vector2 pos{0, 0};
    math::Vector2 velocity{0, 0};
    std::uint16_t rotation{0};  // < rotation given as hundredth of degrees, e.g. 355.5 deg = 35550
    std::int32_t mass{1};
};

#endif
