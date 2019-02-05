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

#ifndef INPUT_KEY_HPP
#define INPUT_KEY_HPP

#include <cstdint>

namespace input
{
enum class Key : std::int16_t
{
    key_unknown = -1,
    key_a = 0,
    key_b,
    key_c,
    key_d,
    key_e,
    key_f,
    key_g,
    key_h,
    key_i,
    key_j,
    key_k,
    key_l,
    key_m,
    key_n,
    key_o,
    key_p,
    key_q,
    key_r,
    key_s,
    key_t,
    key_u,
    key_v,
    key_w,
    key_x,
    key_y,
    key_z,
    key_num0,
    key_num1,
    key_num2,
    key_num3,
    key_num4,
    key_num5,
    key_num6,
    key_num7,
    key_num8,
    key_num9,
    key_escape,
    key_l_control,
    key_l_shift,
    key_l_alt,
    key_l_system,
    key_r_control,
    key_r_shift,
    key_r_alt,
    key_r_system,
    key_menu,
    key_l_bracket,
    key_r_bracket,
    key_semicolon,
    key_comma,
    key_period,
    key_quote,
    key_slash,
    key_backslash,
    key_tilde,
    key_equal,
    key_hyphen,
    key_space,
    key_enter,
    key_backspace,
    key_tab,
    key_page_up,
    key_page_down,
    key_end,
    key_home,
    key_insert,
    key_delete,
    key_add,
    key_subtract,
    key_multiply,
    key_divide,
    key_left,
    key_right,
    key_up,
    key_down,
    key_numpad0,
    key_numpad1,
    key_numpad2,
    key_numpad3,
    key_numpad4,
    key_numpad5,
    key_numpad6,
    key_numpad7,
    key_numpad8,
    key_numpad9,
    key_f1,
    key_f2,
    key_f3,
    key_f4,
    key_f5,
    key_f6,
    key_f7,
    key_f8,
    key_f9,
    key_f10,
    key_f11,
    key_f12,
    key_f13,
    key_f14,
    key_f15,
    key_pause,
    key_count
};
}

#endif
