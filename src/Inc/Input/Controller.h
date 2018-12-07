#pragma once

#include "DirectXTK/pch.h"

#include "Utility/Singleton.h"
#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    class Controller : public Utility::Singleton<Controller>
    {
        SINGLETON(Controller)

    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize();
        /// <summary>
        /// 更新処理
        /// </summary>
        void Update();
        /// <summary>
        /// 非アクティブ、最小化時処理
        /// </summary>
        void OnSuspend();
        /// <summary>
        /// アクティブ時処理
        /// </summary>
        void OnResume();

        /// <summary>
        /// 入力状態を取得
        /// </summary>
        /// <param name="_num">コントローラー番号</param>
        /// <param name="_parts">コントローラーパーツ</param>
        /// <param name="_checkMode">チェック方法</param>
        /// <returns>パーツがチェック方法の状態か</returns>
        bool GetInput(const int& _num, const ControllerParts& _parts, const CheckMode& _checkMode = CheckMode::Press);

        /// <summary>
        /// 入力の値を取得
        /// </summary>
        /// <param name="_num">コントローラー番号</param>
        /// <param name="_parts">コントローラーパーツ</param>
        /// <returns>入力の値</returns>
        float GetVelue(const int& _num, const ControllerParts& _parts);

        /// <summary>
        /// バイブレーション
        /// </summary>
        /// <param name="_num">コントローラー番号</param>
        /// <param name="_left">左の値</param>
        /// <param name="_right">右の値</param>
        void Vibration(const int& _num, const float& _left, const float& _right);

    private:

        static const char m_maxControllerCount = 4;
        static const char m_numOfButtons = 16;
        static const char m_numOfValues = 6;

        const char m_triggerNum = (char)ControllerParts::LTrigger;

        unsigned char m_buttonStates[m_maxControllerCount][m_numOfButtons];
        float m_values[m_maxControllerCount][m_numOfValues];

        std::unique_ptr<DirectX::GamePad> m_gamePad;

        void SetState(const int& _num, const ControllerParts& _parts, const bool& _state);
    };
} // Input
} // CreaDXTKLib