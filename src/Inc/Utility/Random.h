#pragma once

#include <random>

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// 乱数生成クラス
    /// </summary>
    class Random
    {
    public:

        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        Random(const int& _min, const int& _max);
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        /// <param name="_seed">シード値</param>
        Random(const int& _min, const int& _max, const int& _seed);
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        Random(const float& _min, const float& _max);
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        /// <param name="_seed">シード値</param>
        Random(const float& _min, const float& _max, const int& _seed);
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        /// <param name="_mean">平均値</param>
        /// <param name="_stddev">標準偏差</param>
        Random(const float& _min, const float& _max, const float& _mean, const float& _stddev);
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        /// <param name="_mean">平均値</param>
        /// <param name="_stddev">標準偏差</param>
        /// <param name="_seed">シード値</param>
        Random(const float& _min, const float& _max, const float& _mean, const float& _stddev, const int& _seed);

        /// <summary>
        /// 乱数を整数型で取得
        /// </summary>
        /// <returns>乱数</returns>
        int GetInt();
        /// <summary>
        /// 乱数を実数型で取得
        /// </summary>
        /// <returns>乱数</returns>
        float GetReal();
        /// <summary>
        /// 乱数を標準偏差で取得
        /// </summary>
        /// <returns>乱数</returns>
        float GetNormal();

        /// <summary>
        /// シード値を取得
        /// </summary>
        /// <returns>シード値</returns>
        int GetSeed() const;

    private:

        /// <summary>
        /// 乱数生成器
        /// </summary>
        union Generator
        {
            Generator() { }
            ~Generator() { }

            std::uniform_int_distribution<> intDist;
            std::uniform_real_distribution<> realDist;
            std::normal_distribution<> normalDist;
        };

        /// <summary>
        /// 整数型の制限値
        /// </summary>
        struct IntLimit
        {
            int min;
            int max;
        };

        /// <summary>
        /// 実数型の制限値
        /// </summary>
        struct RealLimit
        {
            float min;
            float max;
        };

        /// <summary>
        /// 制限値
        /// </summary>
        union Limit
        {
            Limit() { }
            ~Limit() { }

            IntLimit intLimit;
            RealLimit realLimit;
        };
        
        Generator m_randGen;

        Limit m_limit;

        std::mt19937 m_engine;

        int m_seed;

    };
} // Utility
} // CreaDXTKLib