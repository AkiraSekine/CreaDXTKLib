#pragma once

#include "../Default/pch.h"

#include <vector>

#ifdef _DEBUG
#pragma comment(lib, "Math_d.lib")
#else
#pragma comment(lib, "Math.lib")
#endif // _DEBUG

namespace CreaDXTKLib
{
namespace Math
{
    class Transform2D
    {
    public:

        Transform2D();

        /// <param name="_position">座標</param>
        /// <param name="_parent">親Transform2D</param>
        Transform2D(DirectX::SimpleMath::Vector2 _position,
            Transform2D * _parent = nullptr);

        /// <param name="_position">座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_parent">親Transform2D</param>
        Transform2D(DirectX::SimpleMath::Vector2 _position,
            float _rotation,
            Transform2D * _parent = nullptr);

        /// <param name="_position">座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_parent">親Transform2D</param>
        Transform2D(DirectX::SimpleMath::Vector2 _position,
            float _rotation,
            DirectX::SimpleMath::Vector2 _scale,
            Transform2D * _parent = nullptr);

        virtual ~Transform2D() { }

        /// <summary>
        /// 座標を取得
        /// </summary>
        /// <returns>座標</returns>
        virtual DirectX::SimpleMath::Vector2 Position() const final;
        /// <summary>
        /// 座標を設定
        /// </summary>
        /// <param name="_newPos">新しい座標</param>
        virtual void Position(DirectX::SimpleMath::Vector2 _newPos) final;
        /// <summary>
        /// 相対座標を取得
        /// </summary>
        /// <returns>相対座標</returns>
        virtual DirectX::SimpleMath::Vector2 LocalPosition() const final;

        /// <summary>
        /// 回転角を取得
        /// </summary>
        /// <returns>回転角</returns>
        virtual float Rotation() const final;
        /// <summary>
        /// 回転角を設定
        /// </summary>
        /// <param name="_newRot">新しい角度</param>
        virtual void Rotation(float _newRot) final;
        /// <summary>
        /// 相対角度を取得
        /// </summary>
        /// <returns>相対角度</returns>
        virtual float LocalRotation() const final;

        /// <summary>
        /// 拡大率を取得
        /// </summary>
        /// <returns>拡大率</returns>
        virtual DirectX::SimpleMath::Vector2 Scale() const final;
        /// <summary>
        /// 拡大率を設定
        /// </summary>
        /// <param name="_newScale">新しい拡大率</param>
        virtual void Scale(DirectX::SimpleMath::Vector2 _newScale) final;

        /// <summary>
        /// 前方向のベクトルを取得
        /// </summary>
        /// <returns>前方向のベクトル</returns>
        virtual DirectX::SimpleMath::Vector2 GetUpVector() const final;
        /// <summary>
        /// 右方向のベクトルを取得
        /// </summary>
        /// <returns>右方向のベクトル</returns>
        virtual DirectX::SimpleMath::Vector2 GetRightVector() const final;

        /// <summary>
        /// 親Transform2Dを設定
        /// </summary>
        /// <param name="_parent">親のTransfom2D</param>
        virtual void Parent(Transform2D * _parent) final;
        /// <summary>
        /// 親Transform2Dを取得
        /// </summary>
        /// <returns>親Transform2D</returns>
        virtual Transform2D * Parent() const final;
        /// <summary>
        /// 親Transform2Dとの親子関係を解除
        /// </summary>
        virtual void RemoveParent() final;

    private:

        DirectX::SimpleMath::Vector2 m_position;
        float m_rotation;
        DirectX::SimpleMath::Vector2 m_scale;
        DirectX::SimpleMath::Vector2 m_localPosition;
        float m_localRotation;

        std::vector<Transform2D *> m_children = std::vector<Transform2D *>();
        Transform2D * m_parent = nullptr;
        unsigned int m_childNum = 0;

        float CorrectionRotation(float _rotation);

        void ChildrenCalc();

    };

} // CreaDXTKLib
} // Math