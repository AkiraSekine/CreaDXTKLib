#pragma once

#include "../Utility/Debug.h"

#include <stdexcept>

namespace CreaDXTKLib
{
    template<class StartScene>
    void SetStartScene()
    {
        GameManager::Instance().StartScene<StartScene>();
    }

    template<class NextScene>
    void SceneTransition()
    {
        GameManager::Instance().SceneTransition<NextScene>();
    }

    template<class StartScene>
    void GameManager::StartScene()
    {
        static bool isInitialize = false;

        if (isInitialize)
        {
            Utility::Debug::Log(L"Do not use.\n");
            throw std::exception("Do not use.\n");
        }

        m_nowScene = new StartScene();
    }

    template<class NextScene>
    void GameManager::SceneTransition()
    {
        delete m_nowScene;
        m_nowScene = nullptr;

        m_nowScene = new NextScene();
    }
}