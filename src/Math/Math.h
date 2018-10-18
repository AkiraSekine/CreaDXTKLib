#pragma once

#include "Vector2.h"

namespace CreaDXTKLib
{
namespace Math
{
    extern const float Deg2Rad;
    extern const float Rad2Deg;

    const Vector2 operator+(const float _value, const Vector2& _vec);
    const Vector2 operator-(const float _value, const Vector2& _vec);
    const Vector2 operator*(const float _value, const Vector2& _vec);
    const Vector2 operator/(const float _value, const Vector2& _vec);
}
}