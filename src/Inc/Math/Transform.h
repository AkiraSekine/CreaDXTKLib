#pragma once

#include "Vector2.h"

#include <vector>

namespace CreaDXTKLib
{
namespace Math
{
    /// <summary>
    /// 位置,回転,スケール情報
    /// </summary>
    class Transform2D
    {
    public:

        Transform2D();

        /// <param name="_position">座標</param>
        /// <param name="_parent">親Transform2D</param>
        Transform2D(const Vector2& _position,
            Transform2D * _parent = nullptr);

        /// <param name="_position">座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_parent">親Transform2D</param>
        Transform2D(const Vector2& _position,
            const float& _rotation,
            Transform2D * _parent = nullptr);

        /// <param name="_position">座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_parent">親Transform2D</param>
        Transform2D(const Vector2& _position,
            const float& _rotation,
            const Vector2& _scale,
            Transform2D * _parent = nullptr);

        virtual ~Transform2D();

        /// <summary>
        /// 座標を取得
        /// </summary>
        /// <returns>座標</returns>
        virtual Vector2 Position() const final;
        /// <summary>
        /// 座標を設定
        /// </summary>
        /// <param name="_newPos">新しい座標</param>
        virtual void Position(const Vector2& _newPos) final;
        /// <summary>
        /// 相対座標を取得
        /// </summary>
        /// <returns>相対座標</returns>
        virtual Vector2 LocalPosition() const final;

        /// <summary>
        /// 回転角を取得
        /// </summary>
        /// <returns>回転角</returns>
        virtual float Rotation() const final;
        /// <summary>
        /// 回転角を設定
        /// </summary>
        /// <param name="_newRot">新しい角度</param>
        virtual void Rotation(const float& _newRot) final;
        /// <summary>
        /// 相対角度を取得
        /// </summary>
        /// <returns>相対角度</returns>
        virtual float LocalRotation() const final;

        /// <summary>
        /// 拡大率を取得
        /// </summary>
        /// <returns>拡大率</returns>
        virtual Vector2 Scale() const final;
        /// <summary>
        /// 拡大率を設定
        /// </summary>
        /// <param name="_newScale">新しい拡大率</param>
        virtual void Scale(const Vector2& _newScale) final;

        /// <summary>
        /// 前方向のベクトルを取得
        /// </summary>
        /// <returns>前方向のベクトル</returns>
        virtual Vector2 GetUpVector() const final;
        /// <summary>
        /// 右方向のベクトルを取得
        /// </summary>
        /// <returns>右方向のベクトル</returns>
        virtual Vector2 GetRightVector() const final;

        /// <summary>
        /// 親Transform2Dを設定
        /// </summary>
        /// <param name="_parent">親のTransfom2D</param>
        virtual void Parent(Transform2D * _parent);
        /// <summary>
        /// 親Transform2Dを取得
        /// </summary>
        /// <returns>親Transform2D</returns>
        virtual Transform2D * Parent() const final;
        /// <summary>
        /// 親Transform2Dとの親子関係を解除
        /// </summary>
        virtual void RemoveParent() final;

    protected:

    private:

        Vector2 m_position;
        float m_rotation;
        Vector2 m_scale;
        Vector2 m_localPosition;
        float m_localRotation;

        std::vector<Transform2D *> m_children = std::vector<Transform2D *>();
        Transform2D * m_parent = nullptr;
        unsigned int m_childNum = 0;

        virtual float CorrectionRotation(float _rotation) final;

        void ChildrenCalc();

    };

} // CreaDXTKLib
} // Math