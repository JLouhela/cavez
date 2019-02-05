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

#ifndef GAME_INTERFACE_HPP
#define GAME_INTERFACE_HPP

#include <map>
#include <memory>

struct Game_config
{
    std::int8_t player_count{1};
    struct
    {
        std::int16_t width{800};
        std::int16_t height{600};
    } resolution;
};

class Rendering_interface;
class Game_state_interface;
class Input_interface;

class Game_interface
{
public:
    virtual ~Game_interface() = default;

    // TODO platform independent float?
    virtual void update(float delta_time) = 0;

    // TODO may not work like this,keep as a reminder that interpolation must be
    // handled somehow
    virtual void interpolate(float delta_time, Game_state_interface& game_state) = 0;

    virtual void render(float delta_time) = 0;

    virtual const Game_state_interface& get_state() = 0;
};

std::unique_ptr<Game_interface> make_game(const Game_config& config,
                                          Rendering_interface& rendering_interface,
                                          const Input_interface& input_interface);

#endif
