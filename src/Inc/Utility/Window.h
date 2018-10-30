#pragma once

#include "Singleton.h"
#include "../Math/Vector2.h"

#include <Windows.h>

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// ウィンドウ関係
    /// </summary>
    class Window final : public Singleton<Window>
    {
        SINGLETON(Window)

    public:

        /// <summary>
        /// 背景色
        /// </summary>
        DirectX::XMVECTORF32 backGroundColor = DirectX::Colors::CornflowerBlue;

        /// <summary>
        /// ウィンドウハンドルを設定
        /// </summary>
        /// <param name="_windowHandle">ウィンドウハンドル</param>
        void SetWindowHandle(HWND _windowHandle);

        /// <summary>
        /// ウィンドウサイズを取得
        /// </summary>
        /// <returns>ウィンドウサイズ</returns>
        Math::Vector2 GetSize();
        /// <summary>
        /// ウィンドウサイズを設定
        /// </summary>
        /// <param name="_width">幅</param>
        /// <param name="_height">高さ</param>
        void SetSize(int _width, int _height);

        /// <summary>
        /// ウィンドウの位置を設定
        /// </summary>
        /// <param name="_position">位置</param>
        void SetPosition(Math::Vector2& _position);

        /// <summary>
        /// ウィンドウ名を設定
        /// </summary>
        /// <param name="_text">ウィンドウ名</param>
        void SetText(const std::wstring& _text);

        /// <summary>
        /// ウィンドウスタイルを設定
        /// </summary>
        /// <param name="_style">
        /// <para>スタイル情報</para>
        /// <para>https://msdn.microsoft.com/ja-jp/library/cc410714.aspx</para>
        /// <para>のdwExStyleの項目を参照</para>
        /// </param>
        void SetStyle(long _style);

    private:

        HWND m_windowHandle;
        RECT m_windowRect;

    };
} // Utility
} // CreaDXTKLib