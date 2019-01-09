#include "Utility/Window.h"
#include "Utility/Debug.h"

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

    void Window::SetSize(const int& _width, const int& _height)
    {
        Vector2 clientSize = GetSize();
        RECT windowRect;
        Vector2 windowSize;
        Vector2 frameSize;

        // �E�B���h�E�̘g�̃T�C�Y���v�Z
        GetWindowRect(m_windowHandle, &windowRect);

        windowSize.x = (float)(windowRect.right - windowRect.left);
        windowSize.y = (float)(windowRect.bottom - windowRect.top);

        frameSize = windowSize - clientSize;

        // �T�C�Y��K�p
        SetWindowPos(m_windowHandle, NULL, CW_USEDEFAULT, CW_USEDEFAULT, frameSize.x + _width, frameSize.y + _height, SWP_NOMOVE);

        ShowWindow(m_windowHandle, SW_SHOW);
        UpdateWindow(m_windowHandle);

        // ��`���v�Z������
        GetSize();
    }

    void Window::SetSize(const Math::Vector2 & _size)
    {
        Vector2 clientSize = GetSize();
        RECT windowRect;
        Vector2 windowSize;
        Vector2 frameSize;

        // �E�B���h�E�̘g�̃T�C�Y���v�Z
        GetWindowRect(m_windowHandle, &windowRect);

        windowSize.x = (float)(windowRect.right - windowRect.left);
        windowSize.y = (float)(windowRect.bottom - windowRect.top);

        frameSize = windowSize - clientSize;

        // �T�C�Y��K�p
        SetWindowPos(m_windowHandle, NULL, CW_USEDEFAULT, CW_USEDEFAULT, frameSize.x + _size.x, frameSize.y + _size.y, SWP_NOMOVE);

        ShowWindow(m_windowHandle, SW_SHOW);
        UpdateWindow(m_windowHandle);

        // ��`���v�Z������
        GetSize();
    }

    void Window::SetPosition(const int & _x, const int & _y)
    {
        // �ʒu��ݒ�
        SetWindowPos(m_windowHandle,
            NULL,
            (int)_x,
            (int)_y,
            0,
            0,
            SWP_NOSIZE);

        // ��`���v�Z������
        GetSize();
    }

    void Window::SetPosition(const Vector2& _position)
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
        SetWindowLong(m_windowHandle, GWL_STYLE, _style);
        ShowWindow(m_windowHandle, SW_SHOW);
    }
} // Utility
} // CreaDXTKLib