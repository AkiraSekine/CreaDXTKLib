#pragma once

#include "../Default/pch.h"

#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// �}�E�X����
    /// </summary>
    class Mouse final
    {
    public:

        /// <summary>
        /// ����������
        /// </summary>
        /// <param name="window">�E�B���h�E�n���h��</param>
        static void Initialize(HWND window);

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
        /// <param name="_button">���ׂ����{�^��</param>
        /// <param name="_mode">�`�F�b�N���@</param>
        /// <returns>�L�[���`�F�b�N���@�̏�Ԃ�</returns>
        static bool GetInput(MouseButtons _button, CheckMode _mode = CheckMode::Press);

        /// <summary>
        /// �}�E�X�̍��W���擾
        /// </summary>
        /// <returns>�}�E�X�̍��W</returns>
        static DirectX::SimpleMath::Vector2 Position();

        /// <summary>
        /// �}�E�X�̍��W��ݒ�
        /// </summary>
        /// <param name="_position">�V�������W</param>
        static void Position(DirectX::SimpleMath::Vector2 _position);

        /// <summary>
        /// �J�[�\���̈ړ��l���擾
        /// </summary>
        /// <returns>�J�[�\���̈ړ��l</returns>
        static DirectX::SimpleMath::Vector2 GetMoveValue();

        /// <summary>
        /// �z�C�[���̈ړ��l���擾
        /// </summary>
        /// <returns>�ړ��l</returns>
        static int GetWheelValue();

        /// <summary>
        /// �J�[�\����\�����邩��ݒ�
        /// </summary>
        /// <param name="_isVisible">�\�����邩</param>
        static void CursorVisible(bool _isVisible);

        /// <summary>
        /// �J�[�\����\�����邩���擾
        /// </summary>
        /// <returns>�J�[�\����\�����邩</returns>
        static bool CursorVisible();

    private:

        static const int m_numOfButtons = 5;

        static unsigned char m_buttonState[m_numOfButtons];

        static DirectX::SimpleMath::Vector2 m_moveValue;

        static int m_wheelValue;

        static bool m_isVisible;

        static std::unique_ptr<DirectX::Mouse> m_mouse;

        Mouse();

        static bool IsMouseDown(MouseButtons _button);
    };

} // Input
} // CreaDXTKLib