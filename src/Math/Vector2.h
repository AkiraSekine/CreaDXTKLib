#pragma once

#include "../Default/pch.h"

#include <string>

namespace CreaDXTKLib
{
namespace Math
{
    /// <summary>
    /// 2Dベクトル
    /// </summary>
    class Vector2
    {
    public:

        /// <summary>
        /// x方向の大きさ
        /// </summary>
        float x;
        /// <summary>
        /// y方向の大きさ
        /// </summary>
        float y;

        /// <summary>
        /// Vector2(0.0f, 0.0f)
        /// </summary>
        static Vector2 zero;
        /// <summary>
        /// Vector2(1.0f, 1.0f)
        /// </summary>
        static Vector2 one;

        Vector2();
        Vector2(float _x);
        Vector2(float _x, float _y);
        virtual ~Vector2();

        /// <summary>
        /// ベクトルの大きさを計算
        /// </summary>
        /// <returns>ベクトルの大きさ</returns>
        virtual float Magnitude();
        /// <summary>
        /// ベクトルの大きさの2乗を計算
        /// </summary>
        /// <returns>ベクトルの大きさの2乗</returns>
        virtual float SqrMagnitude();

        /// <summary>
        /// 正規化した値を計算
        /// </summary>
        /// <returns>正規値</returns>
        virtual Vector2 Normalize();

        /// <summary>
        /// 内積を計算
        /// </summary>
        /// <param name="_vec">ベクトル</param>
        /// <returns>内積</returns>
        virtual float Dot(Vector2& _vec);
        /// <summary>
        /// 外積を計算
        /// </summary>
        /// <param name="_vec">ベクトル</param>
        /// <returns>外積</returns>
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