#include "Input/Input.h"

#include "Input/Mouse.hpp"
#include "Input/Keyboard.hpp"

using namespace std;

namespace CreaDXTKLib
{
namespace Input
{
    void Inputs::Add(const wstring& _name, const DirectX::Keyboard::Keys& _key, const float& _value, const CheckMode& _mode)
    {
        InputSet set;

        // データを保存する
        set.isKey = true;
        set.keyButton.key = _key;
        set.value = _value;
        set.checkMode = _mode;

        m_inputSets.insert(make_pair(_name, set));
    }

    void Inputs::Add(const wstring& _name, const MouseButtons& _button, const float& _value, const CheckMode& _mode)
    {
        InputSet set;

        // データを保存する
        set.isKey = false;
        set.keyButton.mouseButton = _button;
        set.value = _value;
        set.checkMode = _mode;

        m_inputSets.insert(make_pair(_name, set));
    }

    void Inputs::Erase(const std::wstring & _name)
    {
        m_inputSets.erase(_name);
    }

    float Inputs::GetValue(const wstring& _name)
    {
        float ret = 0.f;

        // _nameで指定されたデータを全て取得する
        using it = decltype(m_inputSets)::iterator;
        pair<it, it> datas = m_inputSets.equal_range(_name);

        for (it i = datas.first; i != datas.second; i++)
        {
            InputSet set = i->second;

            // キー入力かマウス入力かで処理を分けて入力状態を取得する
            if (set.isKey)
            {
                ret = ((float)Keyboard::Instance().GetInput(set.keyButton.key, set.checkMode) * set.value);
            }
            else
            {
                ret = ((float)Mouse::Instance().GetInput(set.keyButton.mouseButton, set.checkMode) * set.value);
            }

            // 何か入力されていたら値を返す
            if (ret != 0.f)
            {
                return ret;
            }
        }

        return 0.f;
    }

} // Input
} // CreaDXTKLib