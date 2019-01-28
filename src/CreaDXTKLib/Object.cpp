#include "CreaDXTKLib/Object.h"

#include "CreaDXTKLib/GameManager.h"
#include "Draw/Image.h"

using namespace std;
using namespace DirectX;
using namespace CreaDXTKLib;
using namespace CreaDXTKLib::Math;
using namespace CreaDXTKLib::Draw;

namespace CreaDXTKLib
{
    Object2D::Object2D() :
        m_imageHandle(L""),
        Transform2D(),
        m_objectName(L"Object")
    {
        id = GameManager::Instance().AddObject(this);
    }

    Object2D::Object2D(const wstring& _imageName,
        const Vector2& _position,
        const float& _rotation,
        const Vector2& _scale,
        Transform2D* _parent,
        const wstring& _objectName) :
         m_imageHandle(_imageName),
        Transform2D(_position, _rotation, _scale, _parent),
       m_objectName(_objectName)
    {
        id = GameManager::Instance().AddObject(this);
    }

    Object2D::Object2D(const wstring& _imageName,
        const Transform2D& _transform,
        Transform2D* _parent,
        const wstring& _objectName) :
        m_imageHandle(_imageName),
        Transform2D(_transform.Position(), _transform.Rotation(), _transform.Scale(), _parent),
        m_objectName(_objectName)
    {
        id = GameManager::Instance().AddObject(this);
    }

    Object2D::~Object2D()
    {
        Destroy();
    }

    void Object2D::Draw(const FXMVECTOR & _color) const
    {
        // 親に非アクティブの状態が無ければ描画する
        if (CheckParentIsActive() && m_isActive)
        {
            Vector2 pivot = GetImageSize() * 0.5f;
            Image::Instance().Draw(m_imageHandle, *this, _color, pivot);
        }
    }

    void Object2D::Draw(const RECT & _rect, const FXMVECTOR & _color) const
    {
        // 親に非アクティブの状態が無ければ描画する
        if (CheckParentIsActive() && m_isActive)
        {
            Vector2 pivot = GetImageSize() * 0.5f;
            Image::Instance().Draw(m_imageHandle, *this, _rect, _color, pivot);
        }
    }

    void Object2D::Draw(const CreaDXTKLib::Math::Vector2 _pivot, const DirectX::FXMVECTOR & _color) const
    {
        // 親に非アクティブの状態が無ければ描画する
        if(CheckParentIsActive() && m_isActive)
        {
            Image::Instance().Draw(m_imageHandle, *this, _color, _pivot);
        }
    }

    void Object2D::Draw(const RECT & _rect, const CreaDXTKLib::Math::Vector2 _pivot, const DirectX::FXMVECTOR & _color) const
    {
        // 親に非アクティブの状態が無ければ描画する
        if(CheckParentIsActive() && m_isActive)
        {
            Image::Instance().Draw(m_imageHandle, *this, _rect, _color, _pivot);
        }
    }

    void Object2D::SetActive(const bool& _isActive)
    {
        // 非アクティブ状態になったらOnDisableを呼ぶ
        if (m_isActive && !_isActive)
        {
            OnDisable();
        }
        // アクティブ状態になったらOnEnableを呼ぶ
        if (!m_isActive && _isActive)
        {
            OnEnable();
        }

        m_isActive = _isActive;
    }

    void Object2D::Destroy()
    {
        m_isActive = false;
        m_isDestroy = true;
    }

    bool Object2D::IsDestroy()
    {
        return m_isDestroy;
    }

    Vector2 Object2D::GetImageSize() const
    {
        return Image::Instance().GetImageSize(m_imageHandle);
    }

    std::wstring Object2D::GetImageHandle() const
    {
        return m_imageHandle;
    }

    wstring Object2D::ObjectName() const
    {
        return m_objectName;
    }

    void Object2D::ObjectName(const wstring & _objectName)
    {
        m_objectName = _objectName;
    }

    Object2D::operator bool() const
    {
        return m_isActive;
    }

    bool Object2D::CheckParentIsActive() const
    {
        Transform2D* parent = Parent();

        // 親があれば親のアクティブ状態を返す
        if (parent != nullptr)
        {
            return dynamic_cast<Object2D*>(parent)->CheckParentIsActive();
        }

        return m_isActive;
    }
}