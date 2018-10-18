﻿#pragma once

#include "../Default/pch.h"
#include "../Utility/Singleton.h"
#include "../Math/Transform.h"

#include <map>
#include <vector>
#include <string>

#if defined(_DEBUG) && defined(_MSVC_LANG)
#pragma comment(lib, "Draw_d.lib")
#elif defined(_MSVC_LANG)
#pragma comment(lib, "Draw.lib")
#endif // _DEBUG && _MSVC_LANG

template<class T> class CreaDXTKLib::Utility::Singleton;
class CreaDXTKLib::Math::Transform2D;

namespace CreaDXTKLib
{
namespace Draw
{
    /// <summary>
    /// 画像描画クラス
    /// </summary>
    class Image final : public Utility::Singleton<Image>
    {
        SINGLETON(Image)

    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize(Microsoft::WRL::ComPtr<ID3D11DeviceContext1> _context, Microsoft::WRL::ComPtr<ID3D11Device1>& _device);

        /// <summary>
        /// 終了処理
        /// </summary>
        void OnEnd();

        /// <summary>
        /// 画像の読み込み
        /// </summary>
        /// <param name="_fileName">ファイル名</param>
        /// <param name="_name">ハンドル名</param>
        void Load(const std::wstring& _fileName, const std::wstring& _name);

        /// <summary>
        /// 読み込んだ画像を破棄する
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        void Erase(const std::wstring& _name);

        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const RECT _rect,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_transform">トランスフォーム</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const Math::Transform2D& _transform,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_transform">トランスフォーム</param>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const Math::Transform2D& _transform,
            const RECT _rect,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_color">加算色</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const DirectX::FXMVECTOR _color);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::FXMVECTOR _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const DirectX::FXMVECTOR _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const RECT _rect,
            const DirectX::FXMVECTOR _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_transform">トランスフォーム</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const Math::Transform2D& _transform,
            const DirectX::FXMVECTOR _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_transform">トランスフォーム</param>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const Math::Transform2D& _transform,
            const RECT _rect,
            const DirectX::FXMVECTOR _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_color">加算色</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const DirectX::XMVECTORF32 _color);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::XMVECTORF32 _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const DirectX::XMVECTORF32 _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_transform">トランスフォーム</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const Math::Transform2D& _transform,
            const DirectX::XMVECTORF32 _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const RECT _rect,
            const DirectX::XMVECTORF32 _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_transform">トランスフォーム</param>
        /// <param name="_rect">描画矩形</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">中心座標</param>
        void Draw(const std::wstring& _name,
            const Math::Transform2D& _transform,
            const RECT _rect,
            const DirectX::XMVECTORF32 _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);

    private:

        struct ImageData
        {
            Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

            DirectX::SimpleMath::Vector2 m_size;
        };

        std::map<std::wstring, ImageData> m_imageData =
            std::map<std::wstring, ImageData>();

        std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
        Microsoft::WRL::ComPtr<ID3D11Device1> m_device;
        std::unique_ptr<DirectX::CommonStates> m_states;
    };
} // Draw
} // CreaDXTKLib