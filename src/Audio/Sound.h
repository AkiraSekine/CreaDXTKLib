#pragma once

#include "../Utility/Singleton.h"
#include "../Default/pch.h"

#include <map>

namespace CreaDXTKLib
{
namespace Audio
{
    /// <summary>
    /// 音声クラス
    /// </summary>
    class Sound final : public Utility::Singleton<Sound>
    {
        SINGLETON(Sound)

    public:

        /// <summary>
        /// 音声ファイルの読み込み
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_fileName">ファイル名</param>
        /// <param name="_isLoop">ループ再生するか</param>
        void Load(const std::wstring& _name, const std::wstring& _fileName, bool _isLoop = false);

        /// <summary>
        /// 再生
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        void Play(const std::wstring& _name);
        /// <summary>
        /// 一時停止
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        void Pause(const std::wstring& _name);
        /// <summary>
        /// 停止
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        void Stop(const std::wstring& _name);

        /// <summary>
        /// ループ再生するかを設定
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_isLoop">ループ再生をさせるか</param>
        void IsLoop(const std::wstring& _name, bool _isLoop);
        /// <summary>
        /// ループ再生するかを取得
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <returns>ループ再生するか</returns>
        bool IsLoop(const std::wstring& _name);

        /// <summary>
        /// <para>ボリュームを設定</para>
        /// <para>0.0f～1.0f</para>
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_volume">ボリューム</param>
        void Volume(const std::wstring& _name, float _volume);
        /// <summary>
        /// ボリュームを取得
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <returns>ボリューム</returns>
        float Volume(const std::wstring& _name);

        /// <summary>
        /// <para>パンを設定</para>
        /// <para>-1.0f～1.0f</para>
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_pan">パン</param>
        void Pan(const std::wstring& _name, float _pan);
        /// <summary>
        /// パンを取得
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <returns>パン</returns>
        float Pan(const std::wstring& _name);

        /// <summary>
        /// <para>ピッチを設定</para>
        /// <para>-1.0f～1.0f</para>
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <param name="_pitch">ピッチ</param>
        void Pitch(const std::wstring& _name, float _pitch);
        /// <summary>
        /// ピッチを取得
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <returns>ピッチ</returns>
        float Pitch(const std::wstring& _name);

        /// <summary>
        /// 再生中かの取得
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        /// <returns>再生中か</returns>
        bool IsPlaying(const std::wstring& _name);

        /// <summary>
        /// 読み込んだファイルを破棄
        /// </summary>
        /// <param name="_name">ハンドル名</param>
        void Destroy(const std::wstring& _name);

        /// <summary>
        /// 更新処理
        /// </summary>
        void Update();
        /// <summary>
        /// 終了処理
        /// </summary>
        void OnEnd();

    private:

        struct SoundData
        {
            bool isLoop;
            float volume;
            float pan;
            float pitch;
            std::unique_ptr<DirectX::SoundEffect> file;
            std::unique_ptr<DirectX::SoundEffectInstance> soundFile;
        };

        std::map<std::wstring, SoundData> m_soundDatas = std::map<std::wstring, SoundData>();
    };
} // Audio
} // CreaDXTKLib