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
            // 前フレームの状態を取得
            unsigned char beforeState = m_buttonState[i];

            // 今フレームの状態をリセット
            m_buttonState[i] = 0;

            // キーが押されているかを保存
            m_buttonState[i] |= ((IsMouseDown((MouseButtons)i)) ?
                (char)CheckMode::Press :
                (char)CheckMode::Release);

            // 今フレームで押したかを保存
            if (beforeState & (char)CheckMode::Release &&
                m_buttonState[i] & (char)CheckMode::Press)
            {
                m_buttonState[i] |= (int)CheckMode::Down;
            }
            // 今フレームで離したかを保存
            if (beforeState & (char)CheckMode::Press &&
                m_buttonState[i] & (char)CheckMode::Release)
            {
                m_buttonState[i] |= (char)CheckMode::Up;
            }
        }

        // カーソルの移動値を計算
        static Vector2 nowMoveValue = Vector2::Zero;
        Vector2 beforeMoveValue = nowMoveValue;
        
        nowMoveValue = Vector2((float)state.x, (float)state.y);
        m_moveValue = nowMoveValue - beforeMoveValue;

        // ホイールの相対値を計算
        static int nowWheel = 0;
        int beforeWheel = nowWheel;

        nowWheel = state.scrollWheelValue;
        m_wheelValue = nowWheel - beforeWheel;
    }

    bool Mouse::GetInput(MouseButtons _button, CheckMode _mode)
    {
        // 指定ボタンが指定した状態になっているかを返す
        return (bool)(m_buttonState[(char)_button] & (char)_mode);
    }

    Vector2 Mouse::Position()
    {
        // カーソルの座標を取得して返す
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

        // 表示状態(0)か非表示状態(-1)になるまで繰り返す
        while (ShowCursor(_isVisible) != ((_isVisible) ? 0 : -1));
    }

    bool Mouse::CursorVisible()
    {
        return m_isVisible;
    }

    bool Mouse::IsMouseDown(MouseButtons _button)
    {
        DirectX::Mouse::State state = m_mouse->GetState();

        // すべてのボタンの状態を保存
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