#pragma once

#include "../Default/pch.h"

#include "../Utility/Singleton.h"

namespace CreaDXTKLib
{
    class Scene;

    /// <summary>
    /// �S�̂��Ǘ�����N���X
    /// </summary>
    class GameManager final : public Utility::Singleton<GameManager>
    {
        SINGLETON(GameManager);

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
        void Initialize(Microsoft::WRL::ComPtr<ID3D11DeviceContext1> _context,
            Microsoft::WRL::ComPtr<ID3D11Device1>& _device);

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

    private:

        Scene * m_nowScene;
    };
}

#include "GameManagerDetail.h"