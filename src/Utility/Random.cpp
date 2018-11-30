#include "Utility/Random.h"

#include "Math/Math.h"

using namespace std;
using namespace CreaDXTKLib::Math;

namespace CreaDXTKLib
{
namespace Utility
{
    Random::Random(const int & _min, const int & _max)
    {
        m_limit.intLimit.min = _min;
        m_limit.intLimit.max = _max;

        random_device seed;

        m_seed = seed();

        m_engine = mt19937(m_seed);

        m_randGen.intDist = uniform_int_distribution<>(_min, _max);
    }

    Random::Random(const int & _min, const int & _max, const int & _seed) :
        m_seed(_seed)
    {
        m_limit.intLimit.min = _min;
        m_limit.intLimit.max = _max;

        m_engine = mt19937(m_seed);

        m_randGen.intDist = uniform_int_distribution<>(_min, _max);
    }

    Random::Random(const float & _min, const float & _max)
    {
        m_limit.realLimit.min = _min;
        m_limit.realLimit.max = _max;

        random_device seed;

        m_seed = seed();

        m_engine = mt19937(m_seed);

        m_randGen.realDist = uniform_real_distribution<>(_min, _max);
    }

    Random::Random(const float & _min, const float & _max, const int & _seed) :
        m_seed(_seed)
    {
        m_limit.realLimit.min = _min;
        m_limit.realLimit.max = _max;

        m_engine = mt19937(m_seed);

        m_randGen.intDist = uniform_int_distribution<>(_min, _max);
    }

    Random::Random(const float & _min, const float & _max, const float & _mean, const float & _stddev)
    {
        m_limit.realLimit.min = _min;
        m_limit.realLimit.max = _max;

        random_device seed;

        m_seed = seed();

        m_engine = mt19937(m_seed);

        m_randGen.normalDist = normal_distribution<>(_mean, _stddev);
    }

    Random::Random(const float & _min, const float & _max, const float & _mean, const float & _stddev, const int & _seed) :
        m_seed(_seed)
    {
        m_limit.realLimit.min = _min;
        m_limit.realLimit.max = _max;

        m_engine = mt19937(m_seed);

        m_randGen.normalDist = normal_distribution<>(_mean, _stddev);
    }

    int Random::GetSeed() const
    {
        return m_seed;
    }

    int Random::GetInt()
    {
        return m_randGen.intDist(m_engine);
    }

    float Random::GetReal()
    {
        return m_randGen.realDist(m_engine);
    }

    float Random::GetNormal()
    {
        float ret = m_randGen.normalDist(m_engine);

        ret = Clamp<float>(ret, m_limit.realLimit.min, m_limit.realLimit.max);

        return ret;
    }
} // Utility
} // CreaDXTKLib