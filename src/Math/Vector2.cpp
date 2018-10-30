#include "Vector2.h"

#include <cmath>

namespace CreaDXTKLib
{
namespace Math
{
    Vector2 Vector2::zero = Vector2(0.f, 0.f);
    Vector2 Vector2::one = Vector2(1.f, 1.f);

    Vector2::Vector2() :
        x(0.f),
        y(0.f)
    {
    }

    Vector2::Vector2(float _x) :
        x(_x),
        y(0.f)
    {
    }

    Vector2::Vector2(float _x, float _y) :
        x(_x),
        y(_y)
    {
    }

    Vector2::~Vector2()
    {
    }

    float Vector2::Magnitude() const
    {
        return sqrtf((x * x) + (y * y));
    }

    float Vector2::SqrMagnitude() const
    {
        return (x * x) + (y * y);
    }

    Vector2 Vector2::Normalize() const
    {
        Vector2 normalized;
        float mag = 1.f / Magnitude();

        // 値の正規化
        normalized.x = x * mag;
        normalized.y = y * mag;

        return normalized;
    }

    float Vector2::Dot(const Vector2 & _vec) const
    {
        return x * _vec.x + y * _vec.y;
    }

    float Vector2::Cross(const Vector2 & _vec) const
    {
        return x * _vec.y - _vec.x * y;
    }

    Vector2 const Vector2::operator-() const
    {
        return Vector2(-x, -y);
    }

    Vector2 const Vector2::operator+(const Vector2 & _vec) const
    {
        return Vector2(x + _vec.x, y + _vec.y);
    }

    Vector2 const Vector2::operator+(const float & _value) const
    {
        return Vector2(x + _value, y + _value);
    }

    Vector2 const Vector2::operator+(const DirectX::SimpleMath::Vector2 & _vec) const
    {
        return Vector2(x + _vec.x, y + _vec.y);
    }

    Vector2 const Vector2::operator-(const Vector2 & _vec) const
    {
        return Vector2(x - _vec.x, y - _vec.y);
    }

    Vector2 const Vector2::operator-(const float & _value) const
    {
        return Vector2(x - _value, y - _value);
    }

    Vector2 const Vector2::operator-(const DirectX::SimpleMath::Vector2 & _vec) const
    {
        return Vector2(x - _vec.x, y - _vec.y);
    }

    Vector2 const Vector2::operator*(const Vector2 & _vec) const
    {
        return Vector2(x * _vec.x, y * _vec.y);
    }

    Vector2 const Vector2::operator*(const float & _value) const
    {
        return Vector2(x*_value, y*_value);
    }

    Vector2 const Vector2::operator*(const DirectX::SimpleMath::Vector2 & _vec) const
    {
        return Vector2(x * _vec.x, y * _vec.y);
    }

    Vector2 const Vector2::operator/(const Vector2 & _vec) const
    {
        return Vector2(x / _vec.x, y / _vec.y);
    }

    Vector2 const Vector2::operator/(const float & _value) const
    {
        return Vector2(x / _value, y / _value);
    }

    Vector2 const Vector2::operator/(const DirectX::SimpleMath::Vector2 & _vec) const
    {
        return Vector2(x / _vec.x, y / _vec.y);
    }
}
}