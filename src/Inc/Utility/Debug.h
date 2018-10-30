#pragma once

#include <string>

#include "../CreaDXTKLib/CreaDXTKLib.h"

#include "Singleton.h"

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// デバッグクラス
    /// </summary>
    class Debug
    {
    public:

        /// <summary>
        /// <para>Visual Studioの出力ウィンドウに文字列を出力</para>
        /// <para>Debug状態のみ使用可能</para>
        /// </summary>
        /// <param name="str">フォーマット</param>
        static void Log(const std::wstring str, ...);
        /// <summary>
        /// <para>Visual Studioの出力ウィンドウに文字列を出力</para>
        /// <para>Debug状態のみ使用可能</para>
        /// </summary>
        /// <param name="str">フォーマット</param>
        static void Log(const std::string str, ...);

    private:

        Debug(); // インスタンス生成を禁止

    };
} // Utility
} // CreaDXTKLib