#pragma once

#include "Vector2.h"

namespace CreaDXTKLib
{
namespace Math
{
    /// <summary>
    /// デグリーからラジアンに変換
    /// </summary>
    extern const float Deg2Rad;
    /// <summary>
    /// ラジアンからデグリーに変換
    /// </summary>
    extern const float Rad2Deg;

    /// <summary>
    /// 値が範囲内に入っているか
    /// </summary>
    /// <param name="_value">チェックする値</param>
    /// <param name="_min">最小値</param>
    /// <param name="_max">最大値</param>
    template <typename T>
    extern inline bool Within(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// 値を範囲内に収める
    /// </summary>
    /// <param name="_value">チェックする値</param>
    /// <param name="_min">最小値</param>
    /// <param name="_max">最大値</param>
    /// <returns>範囲内の値</returns>
    template <typename T>
    extern inline T Clamp(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// 値をループさせる
    /// </summary>
    /// <param name="_value">チェックする値</param>
    /// <param name="_min">最小値</param>
    /// <param name="_max">最大値</param>
    /// <returns>ループした値</returns>
    template <typename T>
    extern inline T Circulate(const T& _value, const T& _min, const T& _max);

    const Vector2 operator+(const float _value, const Vector2& _vec);
    const Vector2 operator-(const float _value, const Vector2& _vec);
    const Vector2 operator*(const float _value, const Vector2& _vec);
    const Vector2 operator/(const float _value, const Vector2& _vec);
} // Math
} // CreaDXTKLib

#include "Math.inl"