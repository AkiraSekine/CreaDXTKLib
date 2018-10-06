#pragma once

#include "CreaDXTKLib.h"
#include "../Utility/Singleton.h"

namespace CreaDXTKLib
{
    /// <summary>
    /// �V�[���̊��N���X
    /// </summary>
    class Scene
    {
    private:

    public:

        Scene() { }
        virtual ~Scene() { }
        
        /// <summary>
        /// �X�V����
        /// </summary>
        virtual void Update() { }
        /// <summary>
        /// �`�揈��
        /// </summary>
        virtual void OnRender() { }
    };
}