#include "Sound.h"
#include "SoundSystem.h"
#include "../Utility/Debug.h"

using namespace std;
using namespace DirectX;

namespace CreaDXTKLib
{
namespace Audio
{
    void Sound::Load(const wstring& _name, const wstring& _fileName, bool _isLoop)
    {
        // 新しいサウンドデータを作成
        m_soundDatas.insert(make_pair(_name, SoundData()));

        SoundData& set = m_soundDatas.at(_name);
        
        // 初期値の設定
        set.isLoop = _isLoop;
        set.volume = 1.f;
        set.pan = 0.f;
        set.pitch = 1.f;

        // ファイルの読み込み
        set.file = make_unique<SoundEffect>(SoundSystem::Instance().GetAudioEngine(), _fileName.c_str());
        set.soundFile = set.file->CreateInstance();
    }

    void Sound::Play(const wstring& _name)
    {
        SoundData& data = m_soundDatas.at(_name);
        data.soundFile->Play(data.isLoop);
    }

    void Sound::Pause(const wstring& _name)
    {
        m_soundDatas.at(_name).soundFile->Pause();
    }

    void Sound::Stop(const std::wstring & _name)
    {
        m_soundDatas.at(_name).soundFile->Stop();
    }

    void Sound::IsLoop(const wstring& _name, bool _isLoop)
    {
        m_soundDatas.at(_name).isLoop = _isLoop;
    }

    bool Sound::IsLoop(const wstring& _name)
    {
        return m_soundDatas.at(_name).isLoop;
    }

    void Sound::Volume(const wstring& _name, float _volume)
    {
        SoundData& data = m_soundDatas.at(_name);

        data.volume = _volume;
        data.soundFile->SetVolume(_volume);
    }

    float Sound::Volume(const wstring& _name)
    {
        return m_soundDatas.at(_name).volume;
    }

    void Sound::Pan(const wstring& _name, float _pan)
    {
        SoundData& data = m_soundDatas.at(_name);

        data.pan = _pan;
        data.soundFile->SetPan(_pan);
    }

    float Sound::Pan(const wstring& _name)
    {
        return m_soundDatas.at(_name).pan;
    }

    void Sound::Pitch(const wstring& _name, float _pitch)
    {
        SoundData& data = m_soundDatas.at(_name);

        data.pitch = _pitch;
        data.soundFile->SetPitch(_pitch);
    }

    float Sound::Pitch(const wstring& _name)
    {
        return m_soundDatas.at(_name).pitch;
    }

    bool Sound::IsPlaying(const std::wstring & _name)
    {
        return m_soundDatas.at(_name).soundFile->GetState() == SoundState::PLAYING;
    }

    void Sound::Destroy(const std::wstring & _name)
    {
        SoundData& data = m_soundDatas.at(_name);

        // 読み込んだファイルを破棄
        data.file.reset();
        data.soundFile.reset();
        
        m_soundDatas.erase(_name);
    }

    void Sound::Update()
    {
        for (auto i = m_soundDatas.begin(); i != m_soundDatas.end(); i++)
        {
            // ループの設定なら再生する
            if (i->second.isLoop)
            {
                i->second.soundFile->Play(true);
            }
        }
    }

    void Sound::OnEnd()
    {
        // 読み込んだすべてのサウンドを破棄
        for (auto i = m_soundDatas.begin(); i != m_soundDatas.end(); i++)
        {
            i->second.file.reset();
            i->second.soundFile.reset();
        }

        m_soundDatas.clear();
    }

} // Audio
} // CreaDXTKLib