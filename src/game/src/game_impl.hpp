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

#ifndef GAME_IMPL_HPP
#define GAME_IMPL_HPP

#include <utility>
#include "camera/cameras.hpp"
#include "game/game_interface.hpp"
#include "game_state_impl.hpp"
#include "systems/system_manager.hpp"

class Rendering_interface;
class Input_interface;

class Game_impl : public Game_interface
{
public:
    explicit Game_impl(const Game_config& config,
                       Rendering_interface& rendering_interface,
                       const Input_interface& input_interface);
    ~Game_impl() override = default;

    void update(float delta_time) override;

    void render(float delta_time) override;

    void interpolate(float delta_time, Game_state_interface& game_state) override;

    const Game_state_interface& get_state() override
    {
        return m_state;
    }

private:
    Game_config m_config;
    System_manager m_system_manager;
    Game_state_impl m_state;
    Cameras m_cameras;
};

#endif
