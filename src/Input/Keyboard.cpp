#include "Input/Keyboard.hpp"

using namespace std;

namespace CreaDXTKLib
{
namespace Input
{

    void CreaDXTKLib::Input::Keyboard::Initialize()
    {
        m_keyboard = make_unique<DirectX::Keyboard>();
    }

    void CreaDXTKLib::Input::Keyboard::OnEnd()
    {
        m_keyboard.reset();
    }

    void Keyboard::Update()
    {
        for (int i = 0; i < m_numOfKeys; i++)
        {
            //前フレームの状態を取得
            unsigned char beforeState = m_keyState[i];

            //今フレームの状態をリセット
            m_keyState[i] = 0;

            //キーが押されているかを保存
            m_keyState[i] |= ((m_keyboard->GetState().IsKeyDown((Keys)i)) ?
                (char)CheckMode::Press :
                (char)CheckMode::Release);

            //今フレームで押したかを保存
            if (beforeState & (char)CheckMode::Release &&
                m_keyState[i] & (char)CheckMode::Press)
            {
                m_keyState[i] |= (int)CheckMode::Down;
            }
            //今フレームで離したかを保存
            else if (beforeState & (char)CheckMode::Press &&
                m_keyState[i] & (char)CheckMode::Release)
            {
                m_keyState[i] |= (char)CheckMode::Up;
            }
        }
    }

    bool Keyboard::GetInput(Keys _key, CheckMode _mode)
    {
        // 指定されたキーが指定された状態になっているかを返す
        return (bool)(m_keyState[(int)_key] & (char)_mode);
    }
} // Input
} // CreaDXTKLib
