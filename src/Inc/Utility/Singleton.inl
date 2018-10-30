#pragma once

namespace CreaDXTKLib
{
namespace Utility
{
    template<class T>
    inline T & Singleton<T>::Instance()
    {
        // ローカルの静的なインスタンスを生成
        static T instance;

        return instance;
    }
} // Utility
} // CreaDXTKLib