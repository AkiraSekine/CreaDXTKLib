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

        // �N���C�A���g�����̋�`���擾
        GetClientRect(m_windowHandle, &m_windowRect);

        // �T�C�Y���v�Z
        size.x = (float)(m_windowRect.right - m_windowRect.left);
        size.y = (float)(m_windowRect.bottom - m_windowRect.top);

        return size;
    }

    void Window::SetSize(int _width, int _height)
    {
        // �T�C�Y��K�p
        SetWindowPos(m_windowHandle, NULL, 0, 0, _width, _height, SWP_NOMOVE);

        // ��`���v�Z������
        GetSize();
    }

    void Window::SetPosition(Vector2& _position)
    {
        // �ʒu��ݒ�
        SetWindowPos(m_windowHandle,
            NULL,
            (int)_position.x,
            (int)_position.y,
            0,
            0,
            SWP_NOSIZE);

        // ��`���v�Z������
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