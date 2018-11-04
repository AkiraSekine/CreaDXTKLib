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
        Left,
        Middle,
        Right,
        Button1,
        Button2
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
        enum struct CheckMode : char
        {
            Down    = 0b0001,    //押した瞬間
            Up      = 0b0010,    //離した瞬間
            Press   = 0b0100,    //押している間
            Release = 0b1000     //離している間
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
            bool isKey;

            union
            {
                DirectX::Keyboard::Keys key;
                MouseButtons mouseButton;
            } keyButton;

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