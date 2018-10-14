#pragma once

#include "../Default/pch.h"

#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// マウス入力
    /// </summary>
    class Mouse final
    {
    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        /// <param name="window">ウィンドウハンドル</param>
        static void Initialize(HWND window);

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
        /// <param name="_button">調べたいボタン</param>
        /// <param name="_mode">チェック方法</param>
        /// <returns>キーがチェック方法の状態か</returns>
        static bool GetInput(MouseButtons _button, CheckMode _mode = CheckMode::Press);

        /// <summary>
        /// マウスの座標を取得
        /// </summary>
        /// <returns>マウスの座標</returns>
        static DirectX::SimpleMath::Vector2 Position();

        /// <summary>
        /// マウスの座標を設定
        /// </summary>
        /// <param name="_position">新しい座標</param>
        static void Position(DirectX::SimpleMath::Vector2 _position);

        /// <summary>
        /// カーソルの移動値を取得
        /// </summary>
        /// <returns>カーソルの移動値</returns>
        static DirectX::SimpleMath::Vector2 GetMoveValue();

        /// <summary>
        /// ホイールの移動値を取得
        /// </summary>
        /// <returns>移動値</returns>
        static int GetWheelValue();

        /// <summary>
        /// カーソルを表示するかを設定
        /// </summary>
        /// <param name="_isVisible">表示するか</param>
        static void CursorVisible(bool _isVisible);

        /// <summary>
        /// カーソルを表示するかを取得
        /// </summary>
        /// <returns>カーソルを表示するか</returns>
        static bool CursorVisible();

    private:

        static const int m_numOfButtons = 5;

        static unsigned char m_buttonState[m_numOfButtons];

        static DirectX::SimpleMath::Vector2 m_moveValue;

        static int m_wheelValue;

        static bool m_isVisible;

        static std::unique_ptr<DirectX::Mouse> m_mouse;

        Mouse();

        static bool IsMouseDown(MouseButtons _button);
    };

} // Input
} // CreaDXTKLib