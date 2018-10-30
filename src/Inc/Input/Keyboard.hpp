#pragma once

#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// キー入力
    /// </summary>
    class Keyboard final : public Utility::Singleton<Keyboard>
    {
        SINGLETON(Keyboard)

    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize();

        /// <summary>
        /// 終了処理
        /// </summary>
        void OnEnd();

        /// <summary>
        /// 更新処理
        /// </summary>
        void Update();

        /// <summary>
        /// 入力の取得
        /// </summary>
        /// <param name="_key">調べたいキー</param>
        /// <param name="_mode">チェック方法</param>
        /// <returns>キーがチェック方法の状態か</returns>
        bool GetInput(Keys _key, CheckMode _mode = CheckMode::Press);

    private:

        static const int m_numOfKeys = 256;

        unsigned char m_keyState[m_numOfKeys];

        std::unique_ptr<DirectX::Keyboard> m_keyboard;
    };
} // Input
} // CreaDXTKLib