#include "CreaDXTKLib/GameManager.h"

#include "CreaDXTKLib/Scene.h"
#include "Draw/Image.h"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"
#include "Input/Controller.h"
#include "Audio/SoundSystem.h"

using namespace Microsoft::WRL;
using namespace CreaDXTKLib::Draw;
using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Audio;

namespace CreaDXTKLib
{
    void GameManager::Initialize(ComPtr<ID3D11DeviceContext1>& _context, ComPtr<ID3D11Device1>& _device)
    {
        Image::Instance().Initialize(_context, _device);
        Keyboard::Instance().Initialize();
        Controller::Instance().Initialize();
        SoundSystem::Instance().Initialize();

        SetUp();
    }

    void GameManager::Update(float _elapsedTime)
    {
        Keyboard::Instance().Update();
        Mouse::Instance().Update();
        Controller::Instance().Update();
        SoundSystem::Instance().Update();

        m_nowScene->Update(_elapsedTime);
    }

    void GameManager::OnRender()
    {
        m_nowScene->OnRender();
    }

    void GameManager::OnEnd()
    {
        Image::Instance().OnEnd();
        Keyboard::Instance().OnEnd();
        Mouse::Instance().OnEnd();
    }
}