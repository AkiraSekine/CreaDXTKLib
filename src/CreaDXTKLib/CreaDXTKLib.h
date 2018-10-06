#pragma once

#ifndef ABSTRACT
#define ABSTRACT = 0
#endif // !ABSTRACT

/// <summary>
/// ゲームの設定
/// </summary>
extern void SetUp();

namespace CreaDXTKLib
{
    /// <summary>
    /// 描画関係
    /// </summary>
    namespace Draw{ }

    /// <summary>
    /// 汎用的なクラス
    /// </summary>
    namespace Utility{ }

    /// <summary>
    /// 終了させる
    /// </summary>
    extern void ExitGame();
}