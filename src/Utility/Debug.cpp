#include "Utility/Debug.h"

#include <cstdarg>
#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

using namespace std;

namespace CreaDXTKLib
{
namespace Utility
{
    void Debug::Log(const wstring str, ...)
    {
#if defined(_DEBUG) && defined(_MSC_VER)
        
        va_list arg;
        wchar_t newStr[512];

        // フォーマットに合わせて文字列を生成
        va_start(arg, str);
        vswprintf_s(newStr, str.c_str(), arg);
        va_end(arg);

        // 文字列を出力
        OutputDebugStringW(newStr);

#endif // _DEBUG && _MSC_VER
    }

    void Debug::Log(const std::string str, ...)
    {
#if defined(_DEBUG) && defined(_MSC_VER)
        
        va_list arg;
        char newStr[512];

        // フォーマットに合わせて文字列を生成
        va_start(arg, str);
        sprintf_s(newStr, str.c_str(), arg);
        va_end(arg);

        // 文字列を出力
        OutputDebugStringA(newStr);

#endif // _DEBUG && _MSC_VER
    }
} // Utility
} // CreaDXTKLib
