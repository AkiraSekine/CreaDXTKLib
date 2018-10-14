#pragma once

#include "../Default/pch.h"

#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// キー入力
    /// </summary>
    class Keyboard final
    {
    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        static void Initialize();

        /// <summary>
        /// 終了処理
        /// </summary>
        static void OnEnd();

        /// <summary>
        /// 更新処理
        /// </summary>
        static void Update();

        /// <summary>
        /// 入力の取得
        /// </summary>
        /// <param name="_key">調べたいキー</param>
        /// <param name="_mode">チェック方法</param>
        /// <returns>キーがチェック方法の状態か</returns>
        static bool GetInput(Keys _key, CheckMode _mode = CheckMode::Press);

    private:

        static const int m_numOfKeys = 256;

        static unsigned char m_keyState[m_numOfKeys];

        static std::unique_ptr<DirectX::Keyboard> m_keyboard;

        Keyboard();
    };
} // Input
} // CreaDXTKLib