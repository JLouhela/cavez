/// Copyright (c) 2019 Joni Louhela
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to
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

#ifndef RENDERING_INTERFACE_HPP
#define RENDERING_INTERFACE_HPP

#include <memory>
#include "assets/image.hpp"
#include "rendering/render_items.hpp"
#include "math/rect.hpp"
#include "math/vector.hpp"

namespace asset
{
class Texture_manager_interface;
}

struct Rendering_target;
class Rendering_interface
{
public:
    virtual ~Rendering_interface() = default;

    // TODO consider rendering inot framebuffer and finally render_frame to screen
    virtual void render(const Render_tex& render_tex) = 0;

    virtual std::int32_t init_render_buffer(const asset::Image& image) = 0;

    virtual void free_render_buffer(std::int32_t buffer_idx) = 0;

    virtual void update_render_buffer(std::int32_t buffer_idx,
                                      const std::vector<Render_buffer_update>& updates) = 0;

    virtual void render(std::int32_t buffer_idx,
                        const math::Rect& buffer_rect,
                        const math::Vector2I& screen_topleft) = 0;
};

std::unique_ptr<Rendering_interface> make_rendering(
    const asset::Texture_manager_interface& texture_manager,
    const Rendering_target& rendering_target);

#endif
