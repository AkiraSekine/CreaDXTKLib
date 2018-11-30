#pragma once

namespace CreaDXTKLib
{
namespace Math
{
    template<typename T>
    bool Within(const T& _value, const T& _min, const T& _max)
    {
        return (_min >= _value && _value <= _max);
    }

    template<typename T>
    T Clamp(const T& _value, const T& _min, const T& _max)
    {
        if (_value > _max)
        {
            return _max;
        }

        if (_value < _min)
        {
            return _min;
        }

        return _value;
    }

    template<typename T>
    T Circulate(const T& _value, const T& _min, const T& _max)
    {
        while (_value > _max)
        {
            _value -= _max - _min;
        }

        while (_value < _min)
        {
            _value += _max - _min;
        }

        return _value;
    }
} // Math
} // CreaDXTKLib