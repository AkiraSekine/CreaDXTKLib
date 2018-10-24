#include "SoundSystem.h"

using namespace std;
using namespace DirectX;

namespace CreaDXTKLib
{
namespace Audio
{
    void SoundSystem::Initialize()
    {
        AUDIO_ENGINE_FLAGS eflags = AudioEngine_Default;

#ifdef _DEBUG
        eflags = eflags | AudioEngine_Debug;
#endif // _DEBUG

        m_audioEngine = make_unique<AudioEngine>(eflags);
        m_retryAudio = false;
    }

    void SoundSystem::Update()
    {
        if (m_retryAudio)
        {
            m_retryAudio = false;
            if (m_audioEngine->Reset())
            {
            }
        }
        else if (!m_audioEngine->Update())
        {
            if (m_audioEngine->IsCriticalError())
            {
                m_retryAudio = true;
            }
        }
    }

    void SoundSystem::OnEnd()
    {
        if (m_audioEngine)
        {
            m_audioEngine->Suspend();
        }
    }

    AudioEngine* SoundSystem::GetAudioEngine()
    {
        return m_audioEngine.get();
    }

    void SoundSystem::OnNewAudioDevice()
    {
        m_retryAudio = true;
    }

    bool SoundSystem::IsSilent()
    {
        return m_isSilent = !m_audioEngine->IsAudioDevicePresent();
    }

} // Audio
} // CreaDXTKLib