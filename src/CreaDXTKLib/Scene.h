#pragma once

namespace CreaDXTKLib
{
    /// <summary>
    /// �V�[���̊��N���X
    /// </summary>
    class Scene
    {
    public:

        Scene() { }
        virtual ~Scene() { }
        
        /// <summary>
        /// �X�V����
        /// </summary>
        virtual void Update(float _elapsedTime)
        {
            _elapsedTime;
        }
        /// <summary>
        /// �`�揈��
        /// </summary>
        virtual void OnRender() { }
    };
}