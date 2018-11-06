#pragma once

#ifndef SINGLETON

/// <summary>
/// シングルトンの設定
/// </summary>
/// <param name="_Class_">Singletonを基底としたクラス</param>
#define SINGLETON(_Class_) \
public: \
friend class CreaDXTKLib::Utility::Singleton<_Class_>; \
protected: \
inline _Class_() { } \
inline ~_Class_() { }

#endif // !SINGLETON

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// シングルトンの基底クラス
    /// </summary>
    template<class T>
    class Singleton
    {
    public:

        /// <summary>
        /// インスタンスを取得
        /// </summary>
        /// <returns>インスタンス</returns>
        static T & Instance();

    protected:

        inline Singleton() { } // 外部でのインスタンス生成を禁止
        inline virtual ~Singleton() { }

    private:

        inline Singleton(const Singleton&) { } // コピーコンストラクタの使用禁止

        inline void operator = (const Singleton& obj) { } // 代入演算子の使用禁止

    };

} // Utility
} // CreaDXTKLib

// 定義ファイルをインクルード
#include "Singleton.inl"