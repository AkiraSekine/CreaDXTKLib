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
        // "class "のサイズを取得
        string classStr = "class ";
        const unsigned int charSize = classStr.length();

        // クラス名の文字列を取得
        string multiName = typeid(*this).name();

        // "class "の部分を削除
        multiName.erase(0u, charSize);

        // multiNameのサイズでワイド文字列の変数を作成
        wchar_t* wideName = new wchar_t[multiName.length() * MB_CUR_MAX + 1];

        // マルチ文字からワイド文字に変換
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