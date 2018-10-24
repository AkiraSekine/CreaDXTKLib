#pragma once

#include "../Default/pch.h"
#include "../Utility/Singleton.h"
#include "../Math/Vector2.h"

#include <string>
#include <map>

namespace CreaDXTKLib
{
namespace Draw
{
    /// <summary>
    /// テキスト描画クラス
    /// </summary>
    class Text final : public Utility::Singleton<Text>
    {
        SINGLETON(Text)

    public:

        /// <summary>
        /// フォントファイルの読み込み
        /// </summary>
        /// <param name="_key">ハンドル名</param>
        /// <param name="_fileName">ファイル名</param>
        void Load(const std::wstring& _key, const std::wstring& _fileName);

        /// <summary>
        /// テキストの描画
        /// </summary>
        /// <param name="_key">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_text">描画文字列(フォーマット)</param>
        void Draw(const std::wstring& _key, const Math::Vector2& _position, const std::wstring _text, ...);
        /// <summary>
        /// テキストの描画
        /// </summary>
        /// <param name="_key">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_color">色</param>
        /// <param name="_text">描画文字列(フォーマット)</param>
        void Draw(const std::wstring& _key, const Math::Vector2& _position, const DirectX::XMVECTORF32& _color , const std::wstring _text, ...);
        /// <summary>
        /// テキストの描画
        /// </summary>
        /// <param name="_key">ハンドル名</param>
        /// <param name="_position">描画座標</param>
        /// <param name="_color">色</param>
        /// <param name="_text">描画文字列(フォーマット)</param>
        void Draw(const std::wstring& _key, const Math::Vector2& _position, const DirectX::FXMVECTOR& _color , const std::wstring _text, ...);

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize(Microsoft::WRL::ComPtr<ID3D11Device1> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> _context);

        /// <summary>
        /// 終了処理
        /// </summary>
        void OnEnd();

    private:

        Microsoft::WRL::ComPtr<ID3D11Device1> m_device;

        std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

        std::map<std::wstring, DirectX::SpriteFont*> m_fonts = std::map<std::wstring, DirectX::SpriteFont*>();

    };
} // Draw
} // CreaDXTKLib