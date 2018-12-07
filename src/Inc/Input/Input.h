#pragma once

#include "../DirectXTK/pch.h"
#include "../Utility/Singleton.h"

#include <map>

template<class T> class CreaDXTKLib::Utility::Singleton;

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// キー
    /// </summary>
    using Keys = DirectX::Keyboard::Keys;

    /// <summary>
    /// マウスボタン
    /// </summary>
    enum struct MouseButtons : char
    {
        Left,    // 左クリック
        Middle,  // 中央ボタン
        Right,   // 右クリック
        Button1, // 戻るボタン
        Button2  // 進むボタン
    };

    /// <summary>
    /// コントローラパーツ
    /// </summary>
    enum struct ControllerParts : char
    {
        A,          // Aボタン
        B,          // Bボタン
        X,          // Xボタン
        Y,          // Yボタン
        LShoulder,  // 左ショルダー
        RShoulder,  // 右ショルダー
        Up,         // 十字上ボタン
        Down,       // 十字下ボタン
        Left,       // 十字左ボタン
        Right,      // 十字右ボタン
        Start,      // スタートボタン
        Menu,       // メニューボタン
        Back,       // 戻るボタン
        View,       // ビューボタン
        LStick,     // 左スティックボタン
        RStick,     // 右スティックボタン
        LTrigger,   // 左トリガー
        RTrigger,   // 右トリガー
        LStickX,    // 左スティックX方向
        LStickY,    // 左スティックY方向
        RStickX,    // 右スティックX方向
        RStickY     // 右スティックY方向
    };

    /// <summary>
    /// 入力関係
    /// </summary>
    class Inputs final : public Utility::Singleton<Inputs>
    {
        SINGLETON(Inputs)

    public:

        /// <summary>
        /// チェック方法
        /// </summary>
        enum struct CheckMode : unsigned char
        {
            Down    = 0b0001,    // 押した瞬間
            Up      = 0b0010,    // 離した瞬間
            Press   = 0b0100,    // 押している間
            Release = 0b1000     // 離している間
        };

        /// <summary>
        /// 入力設定を追加
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_key">キー</param>
        /// <param name="_value">値</param>
        /// <param name="_mode">チェック方法</param>
        void Add(const std::wstring& _name,
            const DirectX::Keyboard::Keys& _key,
            const float& _value,
            const CheckMode& _mode);
        /// <summary>
        /// 入力設定を追加
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_button">マウスボタン</param>
        /// <param name="_value">値</param>
        /// <param name="_mode">チェック方法</param>
        void Add(const std::wstring& _name,
            const MouseButtons& _button,
            const float& _value,
            const CheckMode& _mode);
        /// <summary>
        /// 入力設定を追加
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_num">コントローラ番号</param>
        /// <param name="_parts">コントローラパーツ</param>
        /// <param name="_value">値</param>
        /// <param name="_mode">チェック方法</param>
        void Add(const std::wstring& _name,
            const int& _num,
            const ControllerParts& _parts,
            const float& _value,
            const CheckMode& _mode);
        /// <summary>
        /// 入力設定を追加
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_num">コントローラ番号</param>
        /// <param name="_parts">コントローラパーツ</param>
        void Add(const std::wstring& _name,
            const int& _num,
            const ControllerParts& _parts);

        /// <summary>
        /// 入力設定を削除
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        void Erase(const std::wstring& _name);

        /// <summary>
        /// 入力の取得
        /// </summary>
        /// <param name="_name">名前</param>
        /// <returns>値</returns>
        float GetValue(const std::wstring& _name);

    private:

        struct InputSet
        {
            enum
            {
                Keyboard,
                Mouse,
                Controller
            } source;

            union
            {
                DirectX::Keyboard::Keys key;
                MouseButtons mouseButton;
                ControllerParts parts;
            } keyButton;

            int num;
            float value;
            CheckMode checkMode;
        };

        std::multimap<std::wstring, InputSet> m_inputSets =
            std::multimap<std::wstring, InputSet>();
    };

    /// <summary>
    /// チェック方法
    /// </summary>
    using CheckMode = Inputs::CheckMode;

} // Input
} // CreaDXTKLib