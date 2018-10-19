#include "Window.h"

#include <string>

using namespace std;
using namespace CreaDXTKLib::Math;

namespace CreaDXTKLib
{
namespace Utility
{
    void Window::SetWindowHandle(HWND _windowHandle)
    {
        m_windowHandle = _windowHandle;
    }

    Vector2 Window::GetSize()
    {
        Vector2 size;

        // クライアント部分の矩形を取得
        GetClientRect(m_windowHandle, &m_windowRect);

        // サイズを計算
        size.x = (float)(m_windowRect.right - m_windowRect.left);
        size.y = (float)(m_windowRect.bottom - m_windowRect.top);

        return size;
    }

    void Window::SetSize(int _width, int _height)
    {
        // サイズを適用
        SetWindowPos(m_windowHandle, NULL, 0, 0, _width, _height, SWP_NOMOVE);

        // 矩形を計算させる
        GetSize();
    }

    void Window::SetPosition(Vector2& _position)
    {
        // 位置を設定
        SetWindowPos(m_windowHandle,
            NULL,
            (int)_position.x,
            (int)_position.y,
            0,
            0,
            SWP_NOSIZE);

        // 矩形を計算させる
        GetSize();
    }

    void Window::SetText(const wstring & _text)
    {
        SetWindowText(m_windowHandle, _text.c_str());
    }

    void Window::SetStyle(long _style)
    {
        SetWindowLong(m_windowHandle, GWL_EXSTYLE, _style);
        ShowWindow(m_windowHandle, SW_SHOW);
    }
} // Utility
} // CreaDXTKLib