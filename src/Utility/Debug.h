#pragma once

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
    /// デバッグクラス
    /// </summary>
    class Debug
    {
    private:

        Debug(); // インスタンス生成を禁止

    public:

        /// <summary>
        /// <para>Visual Studioの出力ウィンドウに文字列を出力</para>
        /// <para>Debug状態のみ使用可能</para>
        /// </summary>
        /// <param name="str">フォーマット</param>
        static void Log(const wchar_t * str, ...);
    };
} // Utility
} // CreaDXTKLib