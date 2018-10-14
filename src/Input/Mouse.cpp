#include "Mouse.hpp"

using namespace std;
using namespace DirectX::SimpleMath;

namespace CreaDXTKLib
{
namespace Input
{
    unsigned char Mouse::m_buttonState[Mouse::m_numOfButtons];
    Vector2 Mouse::m_moveValue = Vector2::Zero;
    int Mouse::m_wheelValue = 0;
    bool Mouse::m_isVisible = true;
    unique_ptr<DirectX::Mouse> Mouse::m_mouse;

    void Mouse::Initialize(HWND window)
    {
        m_mouse = make_unique<DirectX::Mouse>();
        m_mouse->SetWindow(window);
    }

    void Mouse::OnEnd()
    {
        m_mouse.reset();
    }

    void Mouse::Update()
    {
        DirectX::Mouse::State state = m_mouse->GetState();

        for (int i = 0; i < m_numOfButtons; i++)
        {
            // �O�t���[���̏�Ԃ��擾
            unsigned char beforeState = m_buttonState[i];

            // ���t���[���̏�Ԃ����Z�b�g
            m_buttonState[i] = 0;

            // �L�[��������Ă��邩��ۑ�
            m_buttonState[i] |= ((IsMouseDown((MouseButtons)i)) ?
                (char)CheckMode::Press :
                (char)CheckMode::Release);

            // ���t���[���ŉ���������ۑ�
            if (beforeState & (char)CheckMode::Release &&
                m_buttonState[i] & (char)CheckMode::Press)
            {
                m_buttonState[i] |= (int)CheckMode::Down;
            }
            // ���t���[���ŗ���������ۑ�
            if (beforeState & (char)CheckMode::Press &&
                m_buttonState[i] & (char)CheckMode::Release)
            {
                m_buttonState[i] |= (char)CheckMode::Up;
            }
        }

        // �J�[�\���̈ړ��l���v�Z
        static Vector2 nowMoveValue = Vector2::Zero;
        Vector2 beforeMoveValue = nowMoveValue;
        
        nowMoveValue = Vector2((float)state.x, (float)state.y);
        m_moveValue = nowMoveValue - beforeMoveValue;

        // �z�C�[���̑��Βl���v�Z
        static int nowWheel = 0;
        int beforeWheel = nowWheel;

        nowWheel = state.scrollWheelValue;
        m_wheelValue = nowWheel - beforeWheel;
    }

    bool Mouse::GetInput(MouseButtons _button, CheckMode _mode)
    {
        // �w��{�^�����w�肵����ԂɂȂ��Ă��邩��Ԃ�
        return (bool)(m_buttonState[(char)_button] & (char)_mode);
    }

    Vector2 Mouse::Position()
    {
        // �J�[�\���̍��W���擾���ĕԂ�
        DirectX::Mouse::State state = m_mouse->GetState();

        return Vector2((float)state.x, (float)state.y);
    }

    void Mouse::Position(Vector2 _position)
    {

    }

    Vector2 Mouse::GetMoveValue()
    {
        return m_moveValue;
    }

    int Mouse::GetWheelValue()
    {
        return m_wheelValue;
    }

    void Mouse::CursorVisible(bool _isVisible)
    {
        m_isVisible = _isVisible;

        // �\�����(0)����\�����(-1)�ɂȂ�܂ŌJ��Ԃ�
        while (ShowCursor(_isVisible) != ((_isVisible) ? 0 : -1));
    }

    bool Mouse::CursorVisible()
    {
        return m_isVisible;
    }

    bool Mouse::IsMouseDown(MouseButtons _button)
    {
        DirectX::Mouse::State state = m_mouse->GetState();

        // ���ׂẴ{�^���̏�Ԃ�ۑ�
        bool ret[] = {
            state.leftButton,
            state.middleButton,
            state.rightButton,
            state.xButton1,
            state.xButton2 };

        return ret[(char)_button];
    }

} // Input
} // CreaDXTKLib