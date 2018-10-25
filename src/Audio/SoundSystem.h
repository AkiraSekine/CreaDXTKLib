#pragma once

#include "../Default/pch.h"
#include "../Utility/Singleton.h"

namespace CreaDXTKLib
{
namespace Audio
{
    /// <summary>
    /// サウンド関係の処理
    /// </summary>
    class SoundSystem final : public Utility::Singleton<SoundSystem>
    {
        SINGLETON(SoundSystem)

    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize();

        /// <summary>
        /// 更新処理
        /// </summary>
        void Update();

        /// <summary>
        /// 終了処理
        /// </summary>
        void OnEnd();

        /// <summary>
        /// オーディオエンジンの取得
        /// </summary>
        /// <returns>オーディオエンジン</returns>
        DirectX::AudioEngine* GetAudioEngine();

        /// <summary>
        /// オーディオデバイスを再検出させる
        /// </summary>
        void OnNewAudioDevice();

        /// <summary>
        /// サイレントモードかの取得
        /// </summary>
        /// <returns>サイレントモードか</returns>
        bool IsSilent();

    private:

        bool m_isSilent;
        bool m_retryAudio;

        std::unique_ptr<DirectX::AudioEngine> m_audioEngine;
    };
} // Audio
} // CreaDXTKLib