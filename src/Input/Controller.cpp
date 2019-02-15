#include "Input/Controller.h"

#include <stdexcept>

#include "CreaDXTKLib/CreaDXTKLib.h"
#include "Utility/Debug.h"

using namespace std;

using namespace DirectX;

namespace CreaDXTKLib
{
namespace Input
{
    void Controller::Initialize()
    {
        m_gamePad = make_unique<GamePad>();

        for (int i = 0; i < m_maxControllerCount; i++)
        {
            for (int j = 0; j < m_numOfButtons; j++)
            {
                m_buttonStates[i][j] = 0;
            }

            for (int j = 0; j < m_numOfValues; j++)
            {
                m_values[i][j] = 0.0f;
            }
        }
    }

    void Controller::Update()
    {
        for (int i = 0; i < m_maxControllerCount; i++)
        {
            GamePad::State state = m_gamePad->GetState(i);

            if (!state.IsConnected())
            {
                continue;
            }

            SetState(i, ControllerParts::A, state.buttons.a);
            SetState(i, ControllerParts::B, state.buttons.b);
            SetState(i, ControllerParts::X, state.buttons.x);
            SetState(i, ControllerParts::Y, state.buttons.y);
            SetState(i, ControllerParts::LShoulder, state.buttons.leftShoulder);
            SetState(i, ControllerParts::RShoulder, state.buttons.rightShoulder);
            SetState(i, ControllerParts::Up, state.dpad.up);
            SetState(i, ControllerParts::Down, state.dpad.down);
            SetState(i, ControllerParts::Left, state.dpad.left);
            SetState(i, ControllerParts::Right, state.dpad.right);
            SetState(i, ControllerParts::Start, state.buttons.start);
            SetState(i, ControllerParts::Menu, state.buttons.menu);
            SetState(i, ControllerParts::Back, state.buttons.back);
            SetState(i, ControllerParts::View, state.buttons.view);
            SetState(i, ControllerParts::LStick, state.buttons.leftStick);
            SetState(i, ControllerParts::RStick, state.buttons.rightStick);

            m_values[i][(char)ControllerParts::LTrigger - m_triggerNum] = state.triggers.left;
            m_values[i][(char)ControllerParts::RTrigger - m_triggerNum] = state.triggers.right;
            m_values[i][(char)ControllerParts::LStickX - m_triggerNum] = state.thumbSticks.leftX;
            m_values[i][(char)ControllerParts::LStickY - m_triggerNum] = state.thumbSticks.leftY;
            m_values[i][(char)ControllerParts::RStickX - m_triggerNum] = state.thumbSticks.rightX;
            m_values[i][(char)ControllerParts::RStickY - m_triggerNum] = state.thumbSticks.rightY;
        }
    }

    void Controller::OnSuspend()
    {
        m_gamePad->Suspend();
    }

    void Controller::OnResume()
    {
        m_gamePad->Resume();
    }

    bool Controller::GetInput(const int& _num, const ControllerParts & _parts, const CheckMode & _checkMode)
    {
        if (_parts >= ControllerParts::LTrigger)
        {
            throw invalid_argument("");
        }

        return m_buttonStates[_num][(char)_parts] & (unsigned char)_checkMode;
    }

    float Controller::GetVelue(const int& _num, const ControllerParts & _parts)
    {
        if (_parts < ControllerParts::LTrigger)
        {
            throw invalid_argument("");
        }

        return m_values[_num][(char)_parts - m_triggerNum];
    }

    void Controller::Vibration(const int & _num, const float & _left, const float & _right)
    {
        m_gamePad->SetVibration(_num, _left, _right);
    }

    void Controller::SetState(const int& _num, const ControllerParts & _parts, const bool & _state)
    {
        // 前フレームの状態を取得
        unsigned char beforeState = m_buttonStates[_num][(char)_parts];

        // 今フレームの状態をリセット
        m_buttonStates[_num][(char)_parts] = 0;

        // 入力があるかを保存
        m_buttonStates[_num][(char)_parts] |=
            (_state ?
            (unsigned char)CheckMode::Press :
            (unsigned char)CheckMode::Release);

        //今フレームで押したかを保存
        if (beforeState & (char)CheckMode::Release &&
            m_buttonStates[_num][(char)_parts] & (char)CheckMode::Press)
        {
            m_buttonStates[_num][(char)_parts] |= (int)CheckMode::Down;
        }
        //今フレームで離したかを保存
        else if (beforeState & (char)CheckMode::Press &&
            m_buttonStates[_num][(char)_parts] & (char)CheckMode::Release)
        {
            m_buttonStates[_num][(char)_parts] |= (char)CheckMode::Up;
        }
    }
} // Input
} // CreaDXTKLib