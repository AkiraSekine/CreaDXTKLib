#include "Transform.h"

#include <cmath>

using namespace std;
using namespace DirectX::SimpleMath;

namespace CreaDXTKLib
{
namespace Math
{
    Transform2D::Transform2D() :
        m_position(Vector2::Zero),
        m_rotation(0.f),
        m_scale(Vector2::One),
        m_localPosition(Vector2::Zero),
        m_localRotation(0.f)
    {
    }

    Transform2D::Transform2D(Vector2 _position, Transform2D * _parent) :
        m_position(_position),
        m_rotation(0.f),
        m_scale(Vector2::One),
        m_parent(_parent)
    {
        if (_parent != nullptr)
        {
            m_childNum = _parent->m_children.size();

            _parent->m_children.push_back(this);

            m_localPosition = m_position - _parent->m_position;
            m_localRotation =
                CorrectionRotation(m_rotation - _parent->m_rotation);
        }
    }

    Transform2D::Transform2D(Vector2 _position,
        float _rotation,
        Transform2D * _parent) :
        m_position(_position),
        m_rotation(CorrectionRotation(_rotation)),
        m_scale(Vector2::One),
        m_parent(_parent)
    {
        if (_parent != nullptr)
        {
            m_childNum = _parent->m_children.size();

            _parent->m_children.push_back(this);

            m_localPosition = m_position - _parent->m_position;
            m_localRotation =
                CorrectionRotation(m_rotation - _parent->m_rotation);
        }
    }

    Transform2D::Transform2D(Vector2 _position,
        float _rotation,
        Vector2 _scale,
        Transform2D * _parent) :
        m_position(_position),
        m_rotation(CorrectionRotation(_rotation)),
        m_scale(_scale),
        m_parent(_parent)
    {
        if (_parent != nullptr)
        {
            m_childNum = _parent->m_children.size();

            _parent->m_children.push_back(this);

            m_localPosition = m_position - _parent->m_position;
            m_localRotation =
                CorrectionRotation(m_rotation - _parent->m_rotation);
        }
    }

    Vector2 Transform2D::Position() const
    {
        return m_position;
    }

    void Transform2D::Position(Vector2 _newPos)
    {
        m_position = _newPos;

        if (m_parent != nullptr)
        {
            m_localPosition = m_position - m_parent->m_position;
        }
        else
        {
            m_localPosition = m_position;
        }

        ChildrenCalc();
    }

    Vector2 Transform2D::LocalPosition() const
    {
        return m_localPosition;
    }

    float Transform2D::Rotation() const
    {
        return m_rotation;
    }

    void Transform2D::Rotation(float _newRot)
    {
        m_rotation = CorrectionRotation(_newRot);

        if (m_parent != nullptr)
        {
            m_localRotation = m_rotation - m_parent->m_rotation;
        }
        else
        {
            m_localRotation = m_rotation;
        }

        m_localRotation = CorrectionRotation(m_localRotation);

        ChildrenCalc();
    }

    float Transform2D::LocalRotation() const
    {
        return m_localRotation;
    }

    Vector2 Transform2D::Scale() const
    {
        return m_scale;
    }

    void Transform2D::Scale(Vector2 _newScale)
    {
        m_scale = _newScale;

        ChildrenCalc();
    }

    Vector2 Transform2D::GetForwardVector() const
    {
        Vector2 forward;

        forward.x = cosf(m_rotation);
        forward.y = sinf(m_rotation);

        return forward;
    }

    void Transform2D::Parent(Transform2D * _parent)
    {
        m_childNum = _parent->m_children.size();
        _parent->m_children.push_back(this);
        m_parent = _parent;

        m_localPosition = m_position - _parent->m_position;
        m_localRotation = CorrectionRotation(m_rotation - _parent->m_rotation);
    }

    Transform2D * Transform2D::Parent() const
    {
        return m_parent;
    }

    void Transform2D::RemoveParent()
    {
        m_parent->m_children.erase(m_parent->m_children.begin() + m_childNum);
        m_parent = nullptr;

        m_localPosition = m_position;
        m_localRotation = m_rotation;
    }

    float Transform2D::CorrectionRotation(float _rotation)
    {
        while (_rotation > (float)M_PI)
        {
            _rotation -= (float)M_PI * 2.f;
        }
        while (_rotation < (float)-M_PI)
        {
            _rotation += (float)M_PI * 2.f;
        }

        return _rotation;
    }

    void Transform2D::ChildrenCalc()
    {
        for (Transform2D * child : m_children)
        {
            float childAng = m_rotation +
                atan2f(child->m_localPosition.y, child->m_localPosition.x);
            float length = child->m_localPosition.Length();

            child->Rotation(m_rotation + child->m_localRotation);

            child->m_position = m_position +
                length * Vector2(cosf(childAng), sinf(childAng));
        }
    }

} // CreaDXTKLib
} // Math