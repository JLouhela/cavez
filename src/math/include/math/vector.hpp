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

#ifndef MATH_VECTOR_HPP
#define MATH_VECTOR_HPP

#include <cstdint>

namespace math
{
template <typename T>
struct Vector2
{
    T x{0};
    T y{0};
};

using Vector2I = Vector2<std::int32_t>;
using Vector2F = Vector2<float>;

// TODO think if implicit cast possible
template <typename U>
Vector2<U> vector_cast(const Vector2I& other)
{
    return {static_cast<U>(other.x), static_cast<U>(other.y)};
}

template <typename U>
Vector2<U> vector_cast(const Vector2F& other)
{
    return {static_cast<U>(other.x), static_cast<U>(other.y)};
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const std::int32_t rhs)
{
    return Vector2<T>{lhs.x + static_cast<T>(rhs), lhs.y + static_cast<T>(rhs)};
}

template <typename T>
Vector2<T>& operator+=(Vector2<T>& lhs, const std::int32_t rhs)
{
    lhs.x += static_cast<T>(rhs);
    lhs.y += static_cast<T>(rhs);
    return lhs;
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const float rhs)
{
    return Vector2<T>{lhs.x + static_cast<T>(rhs), lhs.y + static_cast<T>(rhs)};
}

template <typename T>
Vector2<T>& operator+=(Vector2<T>& lhs, const float rhs)
{
    lhs.x += static_cast<T>(rhs);
    lhs.y += static_cast<T>(rhs);
    return lhs;
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>{lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T>
Vector2<T>& operator+=(Vector2<T>& lhs, const Vector2<T>& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, const std::int32_t rhs)
{
    return Vector2<T>{lhs.x * static_cast<T>(rhs), lhs.y * static_cast<T>(rhs)};
}

template <typename T>
Vector2<T>& operator*=(Vector2<T>& lhs, const std::int32_t rhs)
{
    lhs.x *= static_cast<T>(rhs);
    lhs.y *= static_cast<T>(rhs);
    return lhs;
}

template <typename T>
Vector2<T> operator/(const Vector2<T>& lhs, const std::int32_t rhs)
{
    return Vector2<T>{lhs.x / static_cast<T>(rhs), lhs.y / static_cast<T>(rhs)};
}

template <typename T>
Vector2<T>& operator/=(Vector2<T>& lhs, const std::int32_t rhs)
{
    lhs.x /= static_cast<T>(rhs);
    lhs.y /= static_cast<T>(rhs);
    return lhs;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, const float rhs)
{
    return Vector2<T>{lhs.x * static_cast<T>(rhs), lhs.y * static_cast<T>(rhs)};
}

template <typename T>
Vector2<T>& operator*=(Vector2<T>& lhs, const float rhs)
{
    lhs.x *= static_cast<T>(rhs);
    lhs.y *= static_cast<T>(rhs);
    return lhs;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>{lhs.x * rhs.x, lhs.y * rhs.y};
}

template <typename T>
Vector2<T>& operator*=(Vector2<T>& lhs, const Vector2<T>& rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    return lhs;
}

}  // namespace math

#endif
