#pragma once

#ifndef ABSTRACT
#define ABSTRACT = 0
#endif // !ABSTRACT

/// <summary>
/// �Q�[���̐ݒ�
/// </summary>
extern void SetUp();

namespace CreaDXTKLib
{
    /// <summary>
    /// �`��֌W
    /// </summary>
    namespace Draw { }

    /// <summary>
    /// ���͊֌W
    /// </summary>
    namespace Input { }

    /// <summary>
    /// �ėp�I�ȃN���X
    /// </summary>
    namespace Utility { }

    /// <summary>
    /// ���w�֌W
    /// </summary>
    namespace Math { }

    /// <summary>
    /// �I��������
    /// </summary>
    extern void ExitGame();
}