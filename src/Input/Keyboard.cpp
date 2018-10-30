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
            //�O�t���[���̏�Ԃ��擾
            unsigned char beforeState = m_keyState[i];

            //���t���[���̏�Ԃ����Z�b�g
            m_keyState[i] = 0;

            //�L�[��������Ă��邩��ۑ�
            m_keyState[i] |= ((m_keyboard->GetState().IsKeyDown((Keys)i)) ?
                (char)CheckMode::Press :
                (char)CheckMode::Release);

            //���t���[���ŉ���������ۑ�
            if (beforeState & (char)CheckMode::Release &&
                m_keyState[i] & (char)CheckMode::Press)
            {
                m_keyState[i] |= (int)CheckMode::Down;
            }
            //���t���[���ŗ���������ۑ�
            else if (beforeState & (char)CheckMode::Press &&
                m_keyState[i] & (char)CheckMode::Release)
            {
                m_keyState[i] |= (char)CheckMode::Up;
            }
        }
    }

    bool Keyboard::GetInput(Keys _key, CheckMode _mode)
    {
        // �w�肳�ꂽ�L�[���w�肳�ꂽ��ԂɂȂ��Ă��邩��Ԃ�
        return (bool)(m_keyState[(int)_key] & (char)_mode);
    }
} // Input
} // CreaDXTKLib
