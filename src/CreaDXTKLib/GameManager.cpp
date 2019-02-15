#include "CreaDXTKLib/GameManager.h"

#include "CreaDXTKLib/Scene.h"
#include "CreaDXTKLib/Object.h"
#include "Draw/Image.h"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"
#include "Input/Controller.h"
#include "Audio/SoundSystem.h"

#include <algorithm>

using namespace std;

using namespace Microsoft::WRL;

using namespace CreaDXTKLib::Draw;
using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Audio;

namespace CreaDXTKLib
{
    void GameManager::Initialize(ComPtr<ID3D11DeviceContext1>& _context, ComPtr<ID3D11Device1>& _device)
    {
        m_isSceneTransition = false;

        Image::Instance().Initialize(_context, _device);
        Keyboard::Instance().Initialize();
        Controller::Instance().Initialize();
        SoundSystem::Instance().Initialize();

        SetUp();
    }

    void GameManager::Update(float _elapsedTime)
    {
        if (m_isSceneTransition)
        {
            m_isSceneTransition = false;
        }

        Keyboard::Instance().Update();
        Mouse::Instance().Update();
        Controller::Instance().Update();
        SoundSystem::Instance().Update();

        // シーンの更新処理
        m_nowScene->Update(_elapsedTime);

        // シーンが遷移される状態なら更新処理を止める
        if (m_isSceneTransition)
        {
            return;
        }

        // オブジェクトの更新処理
        for (size_t i = 0; i < m_objects.size(); i++)
        {
            // オブジェクトがアクティブの状態のみ実行
            if ((bool)*m_objects.at(i))
            {
                m_objects.at(i)->Update(_elapsedTime);
            }

            // 常に実行
            m_objects.at(i)->AlwaysUpdate(_elapsedTime);

        }

        // LateUpdateの実行
        for (size_t i = 0; i < m_objects.size(); i++)
        {
            // オブジェクトがアクティブ状態のみ実行
            if ((bool)*m_objects.at(i))
            {
                m_objects.at(i)->LateUpdate(_elapsedTime);
            }
        }

        // 削除するオブジェクトの番号
        vector<int> destroyNumber;

        // 削除するべきオブジェクトの番号を格納
        for (Object2D* object : m_objects)
        {
            if (object->IsDestroy())
            {
                destroyNumber.push_back(object->id);
            }
        }

        int count = 0;

        // 格納した番号のオブジェクトを破棄
        for_each(destroyNumber.begin(), destroyNumber.end(), [&](int _num)
            {
                EraseObject(_num);

                count++;

                for (auto i = destroyNumber.begin() + count; i != destroyNumber.end(); i++)
                {
                    int* subNum = &*i;

                    *subNum--;
                }
            });
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
        // 削除するオブジェクトより後の番号を詰める
        for (auto i = m_objects.begin() + _id; i != m_objects.end(); i++)
        {
            Object2D* obj = *i;

            obj->id--;
        }

        // オブジェクトを破棄
        delete m_objects.at(_id);
        m_objects.erase(m_objects.begin() + _id);
    }

    void GameManager::DestroyAllObject()
    {
        for (auto object : m_objects)
        {
            delete object;
        }

        m_objects.clear();
    }
}