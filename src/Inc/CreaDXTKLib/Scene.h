#pragma once

#include "CreaDXTKLib.h"

#include <string>

namespace CreaDXTKLib
{
    /// <summary>
    /// シーンの基底クラス
    /// </summary>
    class Scene
    {
    public:

        virtual ~Scene();

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) ABSTRACT;
        /// <summary>
        /// 描画処理
        /// </summary>
        virtual void OnRender() ABSTRACT;

        /// <summary>
        /// クラス名を取得
        /// </summary>
        /// <returns>クラス名</returns>
        virtual std::wstring GetSceneName() final;
    };
}