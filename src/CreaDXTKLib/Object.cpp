#include "Object.h"

#include "../Draw/Image.h"

using namespace std;
using namespace DirectX;
using namespace CreaDXTKLib::Math;
using namespace CreaDXTKLib::Draw;

namespace CreaDXTKLib
{
    Object2D::Object2D() :
        m_imageHandle(L""),
        Transform2D(),
        m_objectName(L"Object")
    {
    }

    Object2D::Object2D(const wstring& _imageName,
        const Vector2& _position,
        float _rotation,
        const Vector2& _scale,
        Transform2D* _parent,
        const wstring& _objectName) :
         m_imageHandle(_imageName),
        Transform2D(_position, _rotation, _scale, _parent),
       m_objectName(_objectName)
    {
    }

    Object2D::Object2D(const wstring& _imageName,
        const Transform2D& _transform,
        Transform2D* _parent,
        const wstring& _objectName) :
        m_imageHandle(_imageName),
        Transform2D(_transform.Position(), _transform.Rotation(), _transform.Scale(), _parent),
        m_objectName(_objectName)
    {
    }

    Object2D::~Object2D()
    {
    }

    void Object2D::Draw(FXMVECTOR & _color)
    {
        // 親に非アクティブの状態が無ければ描画する
        if (CheckParentIsActive())
        {
            Image::Instance().Draw(m_imageHandle, *this, _color);
        }
    }

    void Object2D::Draw(const RECT & _rect, FXMVECTOR & _color)
    {
        // 親に非アクティブの状態が無ければ描画する
        if (CheckParentIsActive())
        {
            Image::Instance().Draw(m_imageHandle, *this, _rect, _color);
        }
    }

    void Object2D::Draw(XMVECTORF32 & _color)
    {
        // 親に非アクティブの状態が無ければ描画する
        if (CheckParentIsActive())
        {
            Image::Instance().Draw(m_imageHandle, *this, _color);
        }
    }

    void Object2D::Draw(const RECT & _rect, XMVECTORF32 & _color)
    {
        // 親に非アクティブの状態が無ければ描画する
        if (CheckParentIsActive())
        {
            Image::Instance().Draw(m_imageHandle, *this, _rect, _color);
        }
    }

    void Object2D::SetActive(bool _isActive)
    {
        m_isActive = _isActive;
    }

    wstring Object2D::ObjectName()
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

    bool Object2D::CheckParentIsActive()
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