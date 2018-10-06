#pragma once

#include "../Utility/Singleton.h"

namespace CreaDXTKLib
{
    class Scene;

    /// <summary>
    /// �S�̂��Ǘ�����N���X
    /// </summary>
    struct GameManager final : public Utility::Singleton<GameManager>
    {
        SINGLETON(GameManager);

    private:

        Scene * m_nowScene;

    public:

        /// <summary>
        /// �ŏ��̃V�[����ݒ肷��
        /// </summary>
        template<class StartScene>
        friend void SetStartScene();

        /// <summary>
        /// �V�[���J��
        /// </summary>
        template<class NextScene>
        friend void SceneTransition();

        /// <summary>
        /// �ŏ��̃V�[����ݒ肷��
        /// </summary>
        template<class StartScene>
        void StartScene();

        /// <summary>
        /// �V�[���J��
        /// </summary>
        template<class NextScene>
        void SceneTransition();

        /// <summary>
        /// ���C�u�����̏����ݒ�
        /// </summary>
        void Initialize();

        /// <summary>
        /// �X�V����
        /// </summary>
        void Update();

        /// <summary>
        /// �`�揈��
        /// </summary>
        void OnRender();

        /// <summary>
        /// �I������
        /// </summary>
        void OnEnd();
    };
}

#include "GameManagerDetail.h"