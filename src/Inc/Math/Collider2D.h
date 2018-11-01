#pragma once

#include "Vector2.h"

#include <vector>

namespace CreaDXTKLib
{
namespace Math
{
    class CircleCollider;
    class BoxCollider;
    class LineCollider;

    /// <summary>
    /// 2Dの当たり判定
    /// </summary>
    class Collider2D
    {
    public:

        /// <summary>
        /// 形状
        /// </summary>
        enum Shape
        {
            Circle,
            Box,
            Line
        };

        /// <summary>
        /// 形状
        /// </summary>
        Shape m_shape;

        virtual ~Collider2D() { }

        /// <summary>
        /// 当たっているかの取得
        /// </summary>
        /// <returns>当たった相手のコライダー</returns>
        virtual Collider2D* CheckCollision() const final;
        /// <summary>
        /// 当たっているかの取得
        /// </summary>
        /// <returns>当たった相手のコライダー</returns>
        virtual Collider2D* CheckCollision(Collider2D* _collider) const final;

        /// <summary>
        /// 判定対象の追加
        /// </summary>
        /// <param name="_collider">対象</param>
        virtual void AddTarget(Collider2D* _collider);

    protected:

        /// <summary>
        /// ターゲット
        /// </summary>
        std::vector<Collider2D*> m_targets = std::vector<Collider2D*>();

        /// <summary>
        /// CircleColliderとの判定処理
        /// </summary>
        /// <param name="_target">ターゲット</param>
        virtual Collider2D* CheckCircle(CircleCollider* _target) const = 0;
        /// <summary>
        /// BoxColliderとの判定処理
        /// </summary>
        /// <param name="_target">ターゲット</param>
        virtual Collider2D* CheckBox(BoxCollider* _target) const = 0;
        /// <summary>
        /// LineColliderとの判定処理
        /// </summary>
        /// <param name="_target">ターゲット</param>
        virtual Collider2D* CheckLine(LineCollider* _target) const = 0;

    };

    /// <summary>
    /// 線分のコライダー
    /// </summary>
    class LineCollider : public Collider2D
    {
    public:

        /// <summary>
        /// 端点の数
        /// </summary>
        static const unsigned char numOfPoints = 2;

        /// <summary>
        /// 端点の座標
        /// </summary>
        const Vector2* point[numOfPoints];

        /// <param name="_start">始点座標</param>
        /// <param name="_end">終点座標</param>
        LineCollider(const Vector2& _start, const Vector2& _end);

    private:

        virtual Collider2D* CheckCircle(CircleCollider* _target) const;
        virtual Collider2D* CheckBox(BoxCollider* _target) const;
        virtual Collider2D* CheckLine(LineCollider* _target) const;

    };

    /// <summary>
    /// 円形のコライダー
    /// </summary>
    class CircleCollider : public Collider2D
    {
    public:

        /// <summary>
        /// 中心座標
        /// </summary>
        const Vector2* position;
        /// <summary>
        /// 半径
        /// </summary>
        const float* radius;

        /// <param name="_position">中心座標</param>
        /// <param name="_radius">半径</param>
        CircleCollider(const Vector2& _position, const float& _radius);

    private:

        virtual Collider2D* CheckCircle(CircleCollider* _target) const;
        virtual Collider2D* CheckBox(BoxCollider* _target) const;
        virtual Collider2D* CheckLine(LineCollider* _target) const;

    };

    /// <summary>
    /// 矩形のコライダー
    /// </summary>
    class BoxCollider : public Collider2D
    {
    public:

        /// <summary>
        /// 辺の数
        /// </summary>
        static const unsigned char numOfLines = 4;

        /// <summary>
        /// LineCollider4辺分
        /// </summary>
        LineCollider* lines[numOfLines];
        /// <summary>
        /// 中心座標
        /// </summary>
        const Vector2* centerPosition;
        /// <summary>
        /// 矩形サイズ
        /// </summary>
        const Vector2* size;

        /// <param name="_centerPosition">中心座標</param>
        /// <param name="_size">矩形サイズ</param>
        /// <param name="_rotation">回転角</param>
        BoxCollider(const Vector2& _centerPosition, const Vector2& _size, const float& _rotation = 0.0f);

        virtual ~BoxCollider();

        /// <summary>
        /// 判定対象の追加
        /// </summary>
        /// <param name="_collider">対象</param>
        virtual void AddTarget(Collider2D* _collider) override;

        void CalcCorners() const;

    private:

        Vector2* m_corners[numOfLines];
        const float* m_rot;

        virtual Collider2D* CheckCircle(CircleCollider* _target) const;
        virtual Collider2D* CheckBox(BoxCollider* _target) const;
        virtual Collider2D* CheckLine(LineCollider* _target) const;

        bool IsInside(const Vector2& _pos) const;

    };
} // Math
} // CreaDXTKLib