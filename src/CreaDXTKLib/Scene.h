#pragma once

#include "CreaDXTKLib.h"
#include "../Utility/Singleton.h"

namespace CreaDXTKLib
{
    /// <summary>
    /// シーンの基底クラス
    /// </summary>
    class Scene
    {
    private:

    public:

        Scene() { }
        virtual ~Scene() { }
        
        /// <summary>
        /// 更新処理
        /// </summary>
        virtual void Update(float _elapsedTime)
        {
            _elapsedTime;
        }
        /// <summary>
        /// 描画処理
        /// </summary>
        virtual void OnRender() { }
    };
}