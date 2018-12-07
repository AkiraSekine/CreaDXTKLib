#include "Input/Input.h"

#include "Input/Mouse.hpp"
#include "Input/Keyboard.hpp"
#include "Input/Controller.h"

using namespace std;

namespace CreaDXTKLib
{
namespace Input
{
    void Inputs::Add(const wstring& _name, const DirectX::Keyboard::Keys& _key, const float& _value, const CheckMode& _mode)
    {
        InputSet set;

        // データを保存する
        set.source = InputSet::Keyboard;
        set.keyButton.key = _key;
        set.value = _value;
        set.checkMode = _mode;

        m_inputSets.insert(make_pair(_name, set));
    }

    void Inputs::Add(const wstring& _name, const MouseButtons& _button, const float& _value, const CheckMode& _mode)
    {
        InputSet set;

        // データを保存する
        set.source = InputSet::Mouse;
        set.keyButton.mouseButton = _button;
        set.value = _value;
        set.checkMode = _mode;

        m_inputSets.insert(make_pair(_name, set));
    }

    void Inputs::Add(const std::wstring & _name, const int & _num, const ControllerParts & _parts, const float & _value, const CheckMode & _mode)
    {
        InputSet set;

        // データを保存する
        set.source = InputSet::Controller;
        set.keyButton.parts = _parts;
        set.value = _value;
        set.checkMode = _mode;
        set.num = _num;

        m_inputSets.insert(make_pair(_name, set));
    }

    void Inputs::Add(const std::wstring & _name, const int & _num, const ControllerParts & _parts)
    {
        InputSet set;

        // データを保存する
        set.source = InputSet::Controller;
        set.keyButton.parts = _parts;
        set.num = _num;

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

            switch (set.source)
            {
            case InputSet::Keyboard:

                ret = ((float)Keyboard::Instance().GetInput(set.keyButton.key, set.checkMode) * set.value);

                break;

            case InputSet::Mouse:

                ret = ((float)Mouse::Instance().GetInput(set.keyButton.mouseButton, set.checkMode) * set.value);

                break;

            case InputSet::Controller:

                if (set.keyButton.parts < ControllerParts::LTrigger)
                {
                    ret = ((float)Controller::Instance().GetInput(set.num, set.keyButton.parts, set.checkMode) * set.value);
                }
                else
                {
                    ret = Controller::Instance().GetVelue(set.num, set.keyButton.parts);
                }

                break;
            }

            // 何か入力されていたら値を返す
            if (ret != 0.0f)
            {
                return ret;
            }
        }

        return 0.0f;
    }

} // Input
} // CreaDXTKLib