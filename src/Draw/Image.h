#pragma once

#include "../Default/pch.h"

#include <map>
#include <vector>
#include <string>

#ifdef _DEBUG
#pragma comment(lib, "Draw_d.lib")
#else
#pragma comment(lib, "Draw.lib")
#endif // _DEBUG

namespace CreaDXTKLib
{
namespace Draw
{
    /// <summary>
    /// 画像描画クラス
    /// </summary>
    class Image final
    {
    private:

        struct ImageData
        {
            Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

            DirectX::SimpleMath::Vector2 m_size;
        };

        static std::map<std::wstring, ImageData> m_imageData;

        static std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
        static Microsoft::WRL::ComPtr<ID3D11Device1> m_device;
        static std::unique_ptr<DirectX::CommonStates> m_states;

        Image();

    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        static void Initialize(Microsoft::WRL::ComPtr<ID3D11DeviceContext1> _context, Microsoft::WRL::ComPtr<ID3D11Device1>& _device);

        /// <summary>
        /// 終了処理
        /// </summary>
        static void OnEnd();

        /// <summary>
        /// 画像の読み込み
        /// </summary>
        /// <param name="_fileName">ファイル名</param>
        /// <param name="_name">ハンドル名</param>
        static void Load(std::wstring _fileName, std::wstring _name);

        /// <summary>
        /// 読み込んだ画像を破棄する
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        static void Erase(std::wstring _name);

        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_color">加算色</param>
        static void Draw(const std::wstring _name,
            const DirectX::SimpleMath::Vector2 _position);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">回転の中心座標</param>
        static void Draw(const std::wstring _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_scale">拡大率</param>
        /// <param name="_color">加算色</param>
        static void Draw(const std::wstring _name,
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
        /// <param name="_color">加算色</param>
        static void Draw(const std::wstring _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const RECT _rect,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_color">加算色</param>
        static void Draw(const std::wstring _name,
            const DirectX::SimpleMath::Vector2 _position,
            const DirectX::FXMVECTOR _color);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">回転の中心座標</param>
        static void Draw(const std::wstring _name,
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
        static void Draw(const std::wstring _name,
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
        static void Draw(const std::wstring _name,
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
        /// <param name="_position">描画座標</param>
        /// <param name="_color">加算色</param>
        static void Draw(const std::wstring _name,
            const DirectX::SimpleMath::Vector2 _position,
            const DirectX::XMVECTORF32 _color);
        /// <summary>
        /// 画像の描画
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_rotation">回転角</param>
        /// <param name="_color">加算色</param>
        /// <param name="_pivot">回転の中心座標</param>
        static void Draw(const std::wstring _name,
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
        static void Draw(const std::wstring _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
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
        static void Draw(const std::wstring _name,
            const DirectX::SimpleMath::Vector2 _position,
            const float _rotation,
            const DirectX::SimpleMath::Vector2 _scale,
            const RECT _rect,
            const DirectX::XMVECTORF32 _color,
            const DirectX::SimpleMath::Vector2 _pivot = DirectX::SimpleMath::Vector2::Zero);
    };
} // Draw
} // CreaDXTKLib