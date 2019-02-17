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

#include "game_impl.hpp"
#include <memory>
#include "camera/camera.hpp"
#include "ec/component_id.hpp"
#include "logger/logger.hpp"

namespace
{
Cameras create_cameras(const Game_config& config)
{
    // TODO Allow multiple cameras
    // TODO read world size from level
    Cameras cameras;
    cameras.emplace_back(
        math::Rect{0, 0, config.resolution.width, config.resolution.height},
        math::Rect{0, 0, config.resolution.width * 2, config.resolution.height * 2},
        config.resolution.scale);
    return cameras;
}
}  // namespace

Game_impl::Game_impl(const Game_config& config,
                     Rendering_interface& rendering_interface,
                     Input_interface& input_interface)
    : m_config{config},
      m_system_manager{rendering_interface, input_interface},
      m_state{input_interface},
      m_cameras{create_cameras(config)}
{
    LOG_DEBUG << "Game running";
    // TODO game state manager which wraps up level + game state and handles
    // init
}

void Game_impl::update(float delta_time)
{
    m_system_manager.update(delta_time, m_state.get_entities(), m_state.get_components());
}

void Game_impl::render(float delta_time)
{
    m_system_manager.render(m_cameras, m_state.get_entities(), m_state.get_components());
}

void Game_impl::interpolate(float delta_time, Game_state_interface& game_state)
{
    // TBD
    LOG_WARN << "Interpolation not implemented";
}

std::unique_ptr<Game_interface> make_game(const Game_config& config,
                                          Rendering_interface& rendering_interface,
                                          Input_interface& input_interface)
{
    return std::make_unique<Game_impl>(config, rendering_interface, input_interface);
}
