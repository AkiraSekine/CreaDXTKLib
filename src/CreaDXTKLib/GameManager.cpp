#include "GameManager.h"

#include "Scene.h"
#include "../Draw/Image.h"
#include "../Input/Keyboard.hpp"
#include "../Input/Mouse.hpp"

using namespace Microsoft::WRL;
using namespace CreaDXTKLib::Draw;
using namespace CreaDXTKLib::Input;

namespace CreaDXTKLib
{
    void GameManager::Initialize(ComPtr<ID3D11DeviceContext1> _context, ComPtr<ID3D11Device1>& _device)
    {
        Image::Instance().Initialize(_context, _device);
        Keyboard::Initialize();

        SetUp();
    }

    void GameManager::Update()
    {
        Keyboard::Update();
        Mouse::Update();

        m_nowScene->Update();
    }

    void GameManager::OnRender()
    {
        m_nowScene->OnRender();
    }

    void GameManager::OnEnd()
    {
        Image::Instance().OnEnd();
        Keyboard::OnEnd();
        Mouse::OnEnd();
    }
}