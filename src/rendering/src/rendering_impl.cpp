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

#include "rendering_impl.hpp"
#include <memory>
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include "assets/texture_manager_interface.hpp"
#include "image_renderer.hpp"
#include "logger/logger.hpp"
#include "rendering/rendering_target.hpp"

Rendering_impl::Rendering_impl(const asset::Texture_manager_interface& texture_manager,
                               const Rendering_target& rendering_target)
    : m_texture_manager{texture_manager},
      m_render_target{rendering_target.render_target.get()},
      m_scale{rendering_target.scale}
{
    LOG_DEBUG << "Rendering impl created";
}

void Rendering_impl::render(const Render_tex& render_tex)
{
    // TODO consider caching sprites if throttles, should be cheap though
    sf::Sprite sprite;
    sprite.setTexture(m_texture_manager.get_texture(render_tex.texture_id));
    // TODO scale should be set to view, refactor
    sprite.setScale({static_cast<float>(m_scale), static_cast<float>(m_scale)});

    // TODO set texture rect to render target
    // sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
    sprite.setOrigin(static_cast<float>(render_tex.screen_rect.w / 2.f),
                     static_cast<float>(render_tex.screen_rect.h / 2.f));

    sprite.setPosition(static_cast<float>(render_tex.screen_rect.x),
                       static_cast<float>(render_tex.screen_rect.y));
    sprite.setRotation(render_tex.rotation);

    // Draw it
    m_render_target.draw(sprite);
}

std::int32_t Rendering_impl::init_render_buffer(const asset::Image& image)
{
    const auto idx = static_cast<std::int32_t>(m_render_buffers.size());
    Render_buffer buffer{idx, std::make_unique<sf::RenderTexture>()};
    if (!buffer.render_tex->create(image.get_width(), image.get_height()))
    {
        LOG_ERR << "Could not create render texture for render buffer";
        return -1;
    }
    render_to_target(image, *buffer.render_tex);
    m_render_buffers.emplace_back(std::move(buffer));
    return buffer.idx;
}

void Rendering_impl::update_render_buffer(std::int32_t buffer_idx,
                                          const std::vector<Render_buffer_update>& updates)
{
}

void Rendering_impl::render(std::int32_t buffer_idx,
                            const math::Rect& buffer_rect,
                            const math::Rect& screen_rect)
{
}

std::unique_ptr<Rendering_interface> make_rendering(
    const asset::Texture_manager_interface& texture_manager,
    const Rendering_target& rendering_target)
{
    return std::make_unique<Rendering_impl>(texture_manager, rendering_target);
}
