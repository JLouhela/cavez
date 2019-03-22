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

#ifndef RENDERING_IMPL_HPP
#define RENDERING_IMPL_HPP

#include <cstdint>
#include "rendering/rendering_interface.hpp"

namespace sf
{
class RenderTarget;
}

struct Rendering_target;

class Texture_manager_interface;
class Rendering_impl : public Rendering_interface
{
public:
    Rendering_impl(const Texture_manager_interface& texture_manager,
                   const Rendering_target& rendering_target);
    ~Rendering_impl() override = default;

    void render(const Render_tex& render_tex) override;

private:
    const Texture_manager_interface& m_texture_manager;
    // TODO change to rendertarget
    // Init RenderWindow in main.cpp and pass rendertarget here
    // render Render_tex directly to this target
    sf::RenderTarget& m_render_target;
    // TODO own rendertexture for level rendering
    std::uint8_t m_scale{1};
};

#endif
