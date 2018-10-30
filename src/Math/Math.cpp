#include "Math/Math.h"

#include <cmath>

namespace CreaDXTKLib
{
namespace Math
{
    const float Deg2Rad = (float)M_PI / 180.f;
    const float Rad2Deg = 180.f / (float)M_PI;

    const Vector2 operator+(const float _value, const Vector2 & _vec)
    {
        return Vector2(_value + _vec.x, _value + _vec.y);
    }

    const Vector2 operator-(const float _value, const Vector2 & _vec)
    {
        return Vector2(_value - _vec.x, _value - _vec.y);
    }

    const Vector2 operator*(const float _value, const Vector2 & _vec)
    {
        return Vector2(_value * _vec.x, _value * _vec.y);
    }

    const Vector2 operator/(const float _value, const Vector2 & _vec)
    {
        return Vector2(_value / _vec.x, _value / _vec.y);
    }
}
}