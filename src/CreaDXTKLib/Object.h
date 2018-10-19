#pragma once

#include "../Math/Transform.h"
#include "CreaDXTKLib.h"

#ifndef OBJECT2D

#define OBJECT2D(_CLASS)\
public:\
_CLASS() :\
Object2D()\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const Math::Vector2& _position = Math::Vector2::zero,\
float _rotation = 0.f,\
const Math::Vector2& _scale = Math::Vector2::one,\
Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
Object2D(_imageName, _position, _rotation, _scale, _parent, _objectName)\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const Math::Transform2D& _transform,\
Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
Object2D(_imageName, _transform, _parent, _objectName)\
{ Start(); }\
virtual ~_CLASS() override\
{ End(); }

#endif // !OBJECT2D

namespace CreaDXTKLib
{
    namespace Math
    {
        class Transform2D;
    }

    class Object2D : public Math::Transform2D
    {
    public:

        Object2D();
        /// <param name="_imageName">画像のハンドル名</param>
        /// <param name="_position">座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_parent">親Transform2D</param>
        /// <param name="_objectName">オブジェクト名</param>
        Object2D(const std::wstring& _imageName,
            const Math::Vector2& _position = Math::Vector2::zero,
            float _rotation = 0.f,
            const Math::Vector2& _scale = Math::Vector2::one,
            Math::Transform2D* _parent = nullptr,
            const std::wstring& _objectName = L"Object");
        /// <param name="_transform">Transform2D</param>
        /// <param name="_parent">親transform2D</param>
        /// <param name="_objectName">オブジェクト名</param>
        Object2D(const std::wstring& _imageName,
            const Math::Transform2D& _transform,
            Math::Transform2D* _parent = nullptr,
            const std::wstring& _objectName = L"Object");

        virtual ~Object2D();

        /// <summary>
        /// 開始処理
        /// </summary>
        virtual void Start() ABSTRACT;
        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) ABSTRACT;
        /// <summary>
        /// 終了処理
        /// </summary>
        virtual void End() ABSTRACT;

        /// <summary>
        /// オブジェクトを描画
        /// </summary>
        /// <param name="_color">加算色</param>
        virtual void Draw(DirectX::FXMVECTOR& _color = DirectX::Colors::White);
        /// <summary>
        /// オブジェクトを描画
        /// </summary>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        virtual void Draw(const RECT& _rect,
            DirectX::FXMVECTOR& _color = DirectX::Colors::White);
        /// <summary>
        /// オブジェクトを描画
        /// </summary>
        /// <param name="_color">加算色</param>
        virtual void Draw(DirectX::XMVECTORF32& _color);
        /// <summary>
        /// オブジェクトを描画
        /// </summary>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        virtual void Draw(const RECT& _rect, DirectX::XMVECTORF32& _color);

        /// <summary>
        /// アクティブ状態を設定
        /// </summary>
        /// <param name="_isActive">アクティブ状態か</param>
        virtual void SetActive(bool _isActive) final;

        /// <summary>
        /// オブジェクト名を取得
        /// </summary>
        /// <returns>オブジェクト名</returns>
        virtual std::wstring ObjectName() final;
        /// <summary>
        /// オブジェクト名を設定
        /// </summary>
        /// <param name="_objectName">オブジェクト名</param>
        virtual void ObjectName(const std::wstring& _objectName) final;

        virtual operator bool() const;

    protected:

        /// <summary>
        /// アクティブ状態か
        /// </summary>
        bool m_isActive = true;

        /// <summary>
        /// オブジェクト名
        /// </summary>
        std::wstring m_objectName;

    private:

        std::wstring m_imageHandle;

        bool CheckParentIsActive();
    };
}