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
#include "assets/texture_manager_interface.hpp"
#include "logger/logger.hpp"
#include "rendering/rendering_target.hpp"

Rendering_impl::Rendering_impl(const Texture_manager_interface& texture_manager,
                               Rendering_target& rendering_target)
    : m_texture_manager{texture_manager}, m_render_target{rendering_target.render_target.get()}
{
    LOG_DEBUG << "Rendering impl created";
}

void Rendering_impl::render(const Render_tex& render_tex)
{
    // TODO consider caching sprites if throttles, should be cheap though
    sf::Sprite sprite;
    sprite.setTexture(m_texture_manager.get_texture(render_tex.texture_id));
    // TODO set texture rect to render target
    // sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
    sprite.setOrigin(static_cast<float>(render_tex.screen_rect.w / 2.f),
                     static_cast<float>(render_tex.screen_rect.h / 2.f));

    sprite.setPosition(static_cast<float>(render_tex.screen_rect.x),
                       static_cast<float>(render_tex.screen_rect.y));
    sprite.setRotation(static_cast<float>(render_tex.rotation) / 100.0f);

    // TODO setup scale for everything
    // sprite.setScale({3, 3});
    // Draw it
    m_render_target.draw(sprite);
}

std::unique_ptr<Rendering_interface> make_rendering(
    const Texture_manager_interface& texture_manager, Rendering_target& rendering_target)
{
    return std::make_unique<Rendering_impl>(texture_manager, rendering_target);
}
