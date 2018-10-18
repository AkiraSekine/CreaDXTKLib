#pragma once

#include "../Default/pch.h"

#include <string>

namespace CreaDXTKLib
{
namespace Math
{
    /// <summary>
    /// 2DƒxƒNƒgƒ‹
    /// </summary>
    class Vector2
    {
    public:

        float x, y;

        static Vector2 zero;
        static Vector2 one;

        Vector2();
        Vector2(float _x);
        Vector2(float _x, float _y);
        virtual ~Vector2();

        virtual float Magnitude();
        virtual float SqrMagnitude();

        virtual Vector2 Normalize();

        virtual float Dot(Vector2& _vec);
        virtual float Cross(Vector2& _vec);

        virtual const Vector2 operator-() const;
        virtual const Vector2 operator+(const Vector2& _vec) const;
        virtual const Vector2 operator+(const float& _value) const;
        virtual const Vector2 operator+(const DirectX::SimpleMath::Vector2& _vec) const;
        virtual const Vector2 operator-(const Vector2& _vec) const;
        virtual const Vector2 operator-(const float& _value) const;
        virtual const Vector2 operator-(const DirectX::SimpleMath::Vector2& _vec) const;
        virtual const Vector2 operator*(const Vector2& _vec) const;
        virtual const Vector2 operator*(const float& _value) const;
        virtual const Vector2 operator*(const DirectX::SimpleMath::Vector2& _vec) const;
        virtual const Vector2 operator/(const Vector2& _vec) const;
        virtual const Vector2 operator/(const float& _value) const;
        virtual const Vector2 operator/(const DirectX::SimpleMath::Vector2& _vec) const;

        virtual inline Vector2& operator+=(const Vector2& _vec);
        virtual inline Vector2& operator+=(const float _value);
        virtual inline Vector2& operator+=(const DirectX::SimpleMath::Vector2& _vec);
        virtual inline Vector2& operator-=(const Vector2& _vec);
        virtual inline Vector2& operator-=(const float _value);
        virtual inline Vector2& operator-=(const DirectX::SimpleMath::Vector2& _vec);
        virtual inline Vector2& operator*=(const Vector2& _vec);
        virtual inline Vector2& operator*=(const float _value);
        virtual inline Vector2& operator*=(const DirectX::SimpleMath::Vector2& _vec);
        virtual inline Vector2& operator/=(const Vector2& _vec);
        virtual inline Vector2& operator/=(const float _value);
        virtual inline Vector2& operator/=(const DirectX::SimpleMath::Vector2& _vec);

        virtual inline operator std::wstring () const;
        virtual inline operator DirectX::SimpleMath::Vector2 () const;

    protected:

    private:

    };
}
}

#include "Vector2.inl"