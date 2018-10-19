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

        GetClientRect(m_windowHandle, &m_windowRect);

        size.x = (float)(m_windowRect.right - m_windowRect.left);
        size.y = (float)(m_windowRect.bottom - m_windowRect.top);

        return size;
    }

    void Window::SetSize(int _width, int _height)
    {
        SetWindowPos(m_windowHandle, NULL, 0, 0, _width, _height, SWP_NOMOVE);

        GetSize();
    }

    void Window::SetPosition(Vector2& _position)
    {
        SetWindowPos(m_windowHandle,
            NULL,
            (int)_position.x,
            (int)_position.y,
            0,
            0,
            SWP_NOSIZE);

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
}
}