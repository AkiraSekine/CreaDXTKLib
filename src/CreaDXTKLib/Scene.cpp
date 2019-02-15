#include "CreaDXTKLib/Scene.h"

#include "CreaDXTKLib/GameManager.h"

#include <cstdlib>

using namespace std;

using namespace CreaDXTKLib;

namespace CreaDXTKLib
{
    Scene::~Scene()
    {
        GameManager::Instance().DestroyAllObject();
    }

    wstring Scene::GetSceneName()
    {
        // "class "�̃T�C�Y���擾
        string classStr = "class ";
        const unsigned int charSize = classStr.length();

        // �N���X���̕�������擾
        string multiName = typeid(*this).name();

        // "class "�̕������폜
        multiName.erase(0u, charSize);

        // multiName�̃T�C�Y�Ń��C�h������̕ϐ����쐬
        wchar_t* wideName = new wchar_t[multiName.length() * MB_CUR_MAX + 1];

        // �}���`�������烏�C�h�����ɕϊ�
        mbstowcs_s(nullptr,
            wideName,
            multiName.length() * MB_CUR_MAX + 1,
            multiName.c_str(),
            multiName.length() * MB_CUR_MAX + 1);

        wstring ret = wideName;

        delete[] wideName;

        return ret;
    }
}