#include "GameManager.h"

#include "Scene.h"
#include "../Draw/Image.h"

using namespace Microsoft::WRL;
using namespace CreaDXTKLib::Draw;

namespace CreaDXTKLib
{
    void GameManager::Initialize(ComPtr<ID3D11DeviceContext1> _context, ComPtr<ID3D11Device1>& _device)
    {
        Image::Initialize(_context, _device);

        SetUp();
    }

    void GameManager::Update()
    {
        m_nowScene->Update();
    }

    void GameManager::OnRender()
    {
        m_nowScene->OnRender();
    }

    void GameManager::OnEnd()
    {
    }
}