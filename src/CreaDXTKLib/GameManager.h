#pragma once

#include "../Default/pch.h"

#include "../Utility/Singleton.h"

namespace CreaDXTKLib
{
    class Scene;

    /// <summary>
    /// 全体を管理するクラス
    /// </summary>
    class GameManager final : public Utility::Singleton<GameManager>
    {
        SINGLETON(GameManager)

    public:

        /// <summary>
        /// 最初のシーンを設定する
        /// </summary>
        template<class StartScene>
        friend void SetStartScene();

        /// <summary>
        /// シーン遷移
        /// </summary>
        template<class NextScene>
        friend void SceneTransition();

        /// <summary>
        /// 最初のシーンを設定する
        /// </summary>
        template<class StartScene>
        void StartScene();

        /// <summary>
        /// シーン遷移
        /// </summary>
        template<class NextScene>
        void SceneTransition();

        /// <summary>
        /// ライブラリの初期設定
        /// </summary>
        void Initialize(Microsoft::WRL::ComPtr<ID3D11DeviceContext1> _context,
            Microsoft::WRL::ComPtr<ID3D11Device1>& _device);

        /// <summary>
        /// 更新処理
        /// </summary>
        void Update(float _elapsedTime);

        /// <summary>
        /// 描画処理
        /// </summary>
        void OnRender();

        /// <summary>
        /// 終了処理
        /// </summary>
        void OnEnd();

    private:

        Scene * m_nowScene;
    };
} // CreaDXTKLib

// 定義ファイルをインクルード
#include "GameManager.inl"