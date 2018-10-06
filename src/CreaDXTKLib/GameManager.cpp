#include "GameManager.h"

#include "Scene.h"

namespace CreaDXTKLib
{
    void GameManager::Initialize()
    {
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