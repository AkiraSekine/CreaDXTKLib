#include "CreaDXTKLib/GameManager.h"

#include "CreaDXTKLib/Scene.h"
#include "CreaDXTKLib/Object.h"
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

        for (auto obj = m_objects.begin(); obj != m_objects.end(); obj++)
        {
            Object2D* object = *obj;

            if ((bool)object)
            {
                object->Update(_elapsedTime);
            }

            object->AlwaysUpdate(_elapsedTime);
        }

        for (auto obj = m_objects.begin(); obj != m_objects.end(); obj++)
        {
            Object2D* object = *obj;

            if ((bool)object)
            {
                object->LateUpdate(_elapsedTime);
            }
        }
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

    int GameManager::AddObject(Object2D * _object)
    {
        m_objects.push_back(_object);

        return m_objects.size() - 1;
    }

    void GameManager::EraseObject(const int & _id)
    {
        m_objects.erase(m_objects.begin() + _id);

        for (auto i = m_objects.begin() + _id; i != m_objects.end(); i++)
        {
            Object2D* object = *i;

            object->id--;
        }
    }
}