#include "Debug.h"

#include <cstdarg>
#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

namespace CreaDXTKLib
{
namespace Utility
{
    void Debug::Log(const wchar_t * str, ...)
    {
#ifdef _DEBUG
#ifdef _MSC_VER
        
        va_list arg;
        wchar_t newStr[512];

        // �t�H�[�}�b�g�ɍ��킹�ĕ�����𐶐�
        va_start(arg, str);
        vswprintf_s(newStr, str, arg);
        va_end(arg);

        // ��������o��
        OutputDebugStringW(newStr);

#endif // _MSC_VER
#endif // _DEBUG

    }
} // Utility
} // CreaDXTKLib
