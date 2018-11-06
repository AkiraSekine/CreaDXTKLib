#pragma once

#include "../Math/Transform.h"
#include "CreaDXTKLib.h"

namespace CreaDXTKLib
{
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
            const float& _rotation = 0.f,
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
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) ABSTRACT;

        /// <summary>
        /// オブジェクトを描画
        /// </summary>
        /// <param name="_color">加算色</param>
        virtual void Draw(const DirectX::FXMVECTOR& _color = DirectX::Colors::White) const final;
        /// <summary>
        /// オブジェクトを描画
        /// </summary>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        virtual void Draw(const RECT& _rect,
            const DirectX::FXMVECTOR& _color = DirectX::Colors::White) const final;

        /// <summary>
        /// アクティブ状態を設定
        /// </summary>
        /// <param name="_isActive">アクティブ状態か</param>
        virtual void SetActive(const bool& _isActive) final;

        /// <summary>
        /// オブジェクト名を取得
        /// </summary>
        /// <returns>オブジェクト名</returns>
        virtual std::wstring ObjectName() const final;
        /// <summary>
        /// オブジェクト名を設定
        /// </summary>
        /// <param name="_objectName">オブジェクト名</param>
        virtual void ObjectName(const std::wstring& _objectName) final;

        virtual operator bool() const;

    protected:

        /// <summary>
        /// オブジェクト名
        /// </summary>
        std::wstring m_objectName;

        /// <summary>
        /// 開始処理
        /// </summary>
        virtual void Start() { }

        /// <summary>
        /// 終了処理
        /// </summary>
        virtual void OnDestroy() { }

        /// <summary>
        /// アクティブ状態になった時に呼ばれる
        /// </summary>
        virtual void OnEnable() { }

        /// <summary>
        /// 非アクティブ状態になった時に呼ばれる
        /// </summary>
        virtual void OnDisable() { }

    private:

        bool m_isActive = true;

        std::wstring m_imageHandle;

        bool CheckParentIsActive() const;
    };
}

#ifndef OBJECT2D

/// <summary>
/// オブジェクトの設定
/// </summary>
/// <param name="_CLASS">Object2Dを基底としたクラス</param>
#define OBJECT2D(_CLASS)\
public:\
_CLASS() :\
CreaDXTKLib::Object2D()\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Vector2& _position = CreaDXTKLib::Math::Vector2::zero,\
const float& _rotation = 0.f,\
const CreaDXTKLib::Math::Vector2& _scale = CreaDXTKLib::Math::Vector2::one,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
CreaDXTKLib::Object2D(_imageName, _position, _rotation, _scale, _parent, _objectName)\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Transform2D& _transform,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
CreaDXTKLib::Object2D(_imageName, _transform, _parent, _objectName)\
{ Start(); }\
virtual ~_CLASS() override\
{ OnDestroy(); }

#endif // !OBJECT2D

#ifndef OBJECT2D_PARENT

/// <summary>
/// オブジェクトの設定
/// </summary>
/// <param name="_CLASS">クラス名</param>
/// <param name="_PARENT">基底クラス</param>
#define OBJECT2D_PARENT(_CLASS, _PARENT)\
public:\
_CLASS() :\
_PARENT()\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Vector2& _position = CreaDXTKLib::Math::Vector2::zero,\
float _rotation = 0.f,\
const CreaDXTKLib::Math::Vector2& _scale = CreaDXTKLib::Math::Vector2::one,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
_PARENT(_imageName, _position, _rotation, _scale, _parent, _objectName)\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Transform2D& _transform,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
_PARENT(_imageName, _transform, _parent, _objectName)\
{ Start(); }\
virtual ~_CLASS() override\
{ OnDestroy(); }

#endif // !OBJECT2D_PARENT