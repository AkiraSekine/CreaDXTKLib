#pragma once

#include <string>

#include "../CreaDXTKLib/CreaDXTKLib.h"

#include "Singleton.h"

#ifdef _DEBUG
#pragma comment(lib, "Utility_d.lib")
#else
#pragma comment(lib, "Utility.lib")
#endif // _DEBUG

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// �f�o�b�O�N���X
    /// </summary>
    class Debug
    {
    public:

        /// <summary>
        /// <para>Visual Studio�̏o�̓E�B���h�E�ɕ�������o��</para>
        /// <para>Debug��Ԃ̂ݎg�p�\</para>
        /// </summary>
        /// <param name="str">�t�H�[�}�b�g</param>
        static void Log(const std::wstring str, ...);
        /// <summary>
        /// <para>Visual Studio�̏o�̓E�B���h�E�ɕ�������o��</para>
        /// <para>Debug��Ԃ̂ݎg�p�\</para>
        /// </summary>
        /// <param name="str">�t�H�[�}�b�g</param>
        static void Log(const std::string str, ...);

    private:

        Debug(); // �C���X�^���X�������֎~

    };
} // Utility
} // CreaDXTKLib