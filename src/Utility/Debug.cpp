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

        // フォーマットに合わせて文字列を生成
        va_start(arg, str);
        vswprintf_s(newStr, str, arg);
        va_end(arg);

        // 文字列を出力
        OutputDebugStringW(newStr);

#endif // _MSC_VER
#endif // _DEBUG

    }
} // Utility
} // CreaDXTKLib
