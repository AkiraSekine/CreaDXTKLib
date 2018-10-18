#pragma once

#include "Vector2.h"

#include <stdio.h>

namespace CreaDXTKLib
{
namespace Math
{
    inline Vector2& Vector2::operator+=(const Vector2& _vec)
    {
        x += _vec.x;
        y += _vec.y;

        return *this;
    }

    inline Vector2& Vector2::operator+=(const float _value)
    {
        x += _value;
        y += _value;

        return *this;
    }

    inline Vector2& Vector2::operator+=(const DirectX::SimpleMath::Vector2& _vec)
    {
        x += _vec.x;
        y += _vec.y;

        return *this;
    }

    inline Vector2& Vector2::operator-=(const Vector2& _vec)
    {
        x -= _vec.x;
        y -= _vec.y;

        return *this;
    }

    inline Vector2& Vector2::operator-=(const float _value)
    {
        x -= _value;
        y -= _value;

        return *this;
    }

    inline Vector2& Vector2::operator-=(const DirectX::SimpleMath::Vector2& _vec)
    {
        x -= _vec.x;
        y -= _vec.y;

        return *this;
    }

    inline Vector2& Vector2::operator*=(const Vector2& _vec)
    {
        x *= _vec.x;
        y *= _vec.y;

        return *this;
    }

    inline Vector2& Vector2::operator*=(const float _value)
    {
        x *= _value;
        y *= _value;

        return *this;
    }

    inline Vector2& Vector2::operator*=(const DirectX::SimpleMath::Vector2& _vec)
    {
        x *= _vec.x;
        y *= _vec.y;

        return *this;
    }

    inline Vector2& Vector2::operator/=(const Vector2& _vec)
    {
        x /= _vec.x;
        y /= _vec.y;

        return *this;
    }

    inline Vector2& Vector2::operator/=(const float _value)
    {
        x /= _value;
        y /= _value;

        return *this;
    }

    inline Vector2& Vector2::operator/=(const DirectX::SimpleMath::Vector2& _vec)
    {
        x /= _vec.x;
        y /= _vec.y;

        return *this;
    }

    inline Vector2::operator std::wstring() const
    {
        const unsigned int size = 48u;
        wchar_t str[size];

        swprintf_s(str, size, L"x:%f y:%f", x, y);

        return std::wstring(str);
    }

    inline Vector2::operator DirectX::SimpleMath::Vector2() const
    {
        DirectX::SimpleMath::Vector2 ret(x, y);

        return ret;
    }
}
}