#include "Input.h"

#include "Mouse.hpp"
#include "Keyboard.hpp"

using namespace std;

namespace CreaDXTKLib
{
namespace Input
{
    multimap<wstring, Inputs::InputSet> Inputs::m_inputSets =
        multimap<wstring, Inputs::InputSet>();

    void Inputs::Add(const wstring _name, DirectX::Keyboard::Keys _key, float _value, CheckMode _mode)
    {
        InputSet set;

        set.isKey = true;
        set.keyButton.key = _key;
        set.value = _value;
        set.checkMode = _mode;

        m_inputSets.insert(make_pair(_name, set));
    }

    void Inputs::Add(const wstring _name, MouseButtons _button, float _value, CheckMode _mode)
    {
        InputSet set;

        set.isKey = false;
        set.keyButton.mouseButton = _button;
        set.value = _value;
        set.checkMode = _mode;

        m_inputSets.insert(make_pair(_name, set));
    }

    float Inputs::GetValue(const wstring _name)
    {
        float ret = 0.f;
        using it = decltype(m_inputSets)::iterator;
        pair<it, it> datas = m_inputSets.equal_range(_name);

        for (it i = datas.first; i != datas.second; i++)
        {
            InputSet set = i->second;

            if (set.isKey)
            {
                ret = ((float)Keyboard::GetInput(set.keyButton.key, set.checkMode) * set.value);
            }
            else
            {
                ret = ((float)Mouse::GetInput(set.keyButton.mouseButton, set.checkMode) * set.value);
            }

            if (ret != 0.f)
            {
                return ret;
            }
        }

        return 0.f;
    }

} // Input
} // CreaDXTKLib