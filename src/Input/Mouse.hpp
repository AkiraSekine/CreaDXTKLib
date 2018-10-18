#pragma once

#include "../Default/pch.h"

#include "Input.h"

namespace CreaDXTKLib
{
    namespace Utility
    {
        template <class T> class Singleton;
    }

namespace Input
{
    /// <summary>
    /// マウス入力
    /// </summary>
    class Mouse final : public Utility::Singleton<Mouse>
    {
        SINGLETON(Mouse)

    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        /// <param name="window">ウィンドウハンドル</param>
        void Initialize(HWND window);

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
        /// <param name="_button">調べたいボタン</param>
        /// <param name="_mode">チェック方法</param>
        /// <returns>キーがチェック方法の状態か</returns>
        bool GetInput(MouseButtons _button, CheckMode _mode = CheckMode::Press);

        /// <summary>
        /// マウスの座標を取得
        /// </summary>
        /// <returns>マウスの座標</returns>
        DirectX::SimpleMath::Vector2 Position();

        /// <summary>
        /// マウスの座標を設定
        /// </summary>
        /// <param name="_position">新しい座標</param>
        void Position(DirectX::SimpleMath::Vector2 _position);

        /// <summary>
        /// カーソルの移動値を取得
        /// </summary>
        /// <returns>カーソルの移動値</returns>
        DirectX::SimpleMath::Vector2 GetMoveValue();

        /// <summary>
        /// ホイールの移動値を取得
        /// </summary>
        /// <returns>移動値</returns>
        int GetWheelValue();

        /// <summary>
        /// カーソルを表示するかを設定
        /// </summary>
        /// <param name="_isVisible">表示するか</param>
        void CursorVisible(bool _isVisible);

        /// <summary>
        /// カーソルを表示するかを取得
        /// </summary>
        /// <returns>カーソルを表示するか</returns>
        bool CursorVisible();

    private:

        static const int m_numOfButtons = 5;

        unsigned char m_buttonState[m_numOfButtons];

        DirectX::SimpleMath::Vector2 m_moveValue =
            DirectX::SimpleMath::Vector2::Zero;

        int m_wheelValue = 0;

        bool m_isVisible = true;

        std::unique_ptr<DirectX::Mouse> m_mouse;

        bool IsMouseDown(MouseButtons _button);
    };

} // Input
} // CreaDXTKLib