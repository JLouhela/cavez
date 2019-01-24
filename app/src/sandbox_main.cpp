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

#include <chrono>
#include <iostream>
#include <thread>
#include "SFML/Graphics/RenderWindow.hpp"
#include "assets/texture_manager_interface.hpp"
#include "game/game_interface.hpp"
#include "rendering/rendering_interface.hpp"

using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow render_window{sf::VideoMode{800, 600}, "Cavez sandbox"};
    auto texture_manager = make_texture_manager();
    auto renderer = make_rendering(*texture_manager, render_window);
    auto game = make_game(Game_config{}, *renderer);
    // For real main: https://gafferongames.com/post/fix_your_timestep/
    // -> game should support interpolation besides simple update
    auto prev_time = std::chrono::system_clock::now();
    while (render_window.isOpen())
    {
        auto time_now = std::chrono::system_clock::now();
        auto delta_time =
            std::chrono::duration_cast<std::chrono::duration<float>>(time_now - prev_time);
        game->update(delta_time.count());

        render_window.clear(sf::Color::Black);
        game->render(delta_time.count());
        render_window.display();

        prev_time = time_now;
    }
    return 0;
}
