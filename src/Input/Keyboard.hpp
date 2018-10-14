#pragma once

#include "../Default/pch.h"

#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// �L�[����
    /// </summary>
    class Keyboard final
    {
    public:

        /// <summary>
        /// ����������
        /// </summary>
        static void Initialize();

        /// <summary>
        /// �I������
        /// </summary>
        static void OnEnd();

        /// <summary>
        /// �X�V����
        /// </summary>
        static void Update();

        /// <summary>
        /// ���͂̎擾
        /// </summary>
        /// <param name="_key">���ׂ����L�[</param>
        /// <param name="_mode">�`�F�b�N���@</param>
        /// <returns>�L�[���`�F�b�N���@�̏�Ԃ�</returns>
        static bool GetInput(Keys _key, CheckMode _mode = CheckMode::Press);

    private:

        static const int m_numOfKeys = 256;

        static unsigned char m_keyState[m_numOfKeys];

        static std::unique_ptr<DirectX::Keyboard> m_keyboard;

        Keyboard();
    };
} // Input
} // CreaDXTKLib