#pragma once

namespace CreaDXTKLib
{
    /// <summary>
    /// シーンの基底クラス
    /// </summary>
    class Scene
    {
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