#pragma once

#ifndef ABSTRACT
#define ABSTRACT = 0
#endif // !ABSTRACT

#if defined(_DEBUG) && defined(_MSVC_LANG)

#pragma comment(lib, "Draw_d.lib")
#pragma comment(lib, "Input_d.lib")
#pragma comment(lib, "Math_d.lib")
#pragma comment(lib, "Utility_d.lib")

#elif defined(_MSVC_LANG)

#pragma comment(lib, "Draw.lib")
#pragma comment(lib, "Input.lib")
#pragma comment(lib, "Math.lib")
#pragma comment(lib, "Utility.lib")

#endif

/// <summary>
/// ゲームの設定
/// </summary>
extern void SetUp();

namespace CreaDXTKLib
{
    /// <summary>
    /// 描画関係
    /// </summary>
    namespace Draw { }

    /// <summary>
    /// 入力関係
    /// </summary>
    namespace Input { }

    /// <summary>
    /// 汎用的なクラス
    /// </summary>
    namespace Utility { }

    /// <summary>
    /// 数学関係
    /// </summary>
    namespace Math { }

    /// <summary>
    /// 終了させる
    /// </summary>
    extern void ExitGame();
}