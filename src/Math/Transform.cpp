#include "../Inc/Math/Transform.h"

#include <cmath>

using namespace std;

namespace CreaDXTKLib
{
namespace Math
{
    Transform2D::Transform2D() :
        m_position(Vector2::zero),
        m_rotation(0.f),
        m_scale(Vector2::one),
        m_localPosition(Vector2::zero),
        m_localRotation(0.f)
    {
    }

    Transform2D::Transform2D(Vector2 _position, Transform2D * _parent) :
        m_position(_position),
        m_rotation(0.f),
        m_scale(Vector2::one),
        m_parent(_parent),
        m_localPosition(_position),
        m_localRotation(0.f)
    {
        // �e������΃��[�J���l���v�Z����
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
        m_scale(Vector2::one),
        m_parent(_parent),
        m_localPosition(_position),
        m_localRotation(m_rotation)
    {
        // �e������΃��[�J���l���v�Z����
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
        m_parent(_parent),
        m_localPosition(_position),
        m_localRotation(m_rotation)
    {
        // �e������΃��[�J���l���v�Z����
        if (_parent != nullptr)
        {
            m_childNum = _parent->m_children.size();

            _parent->m_children.push_back(this);

            m_localPosition = m_position - _parent->m_position;
            m_localRotation =
                CorrectionRotation(m_rotation - _parent->m_rotation);
        }
    }

    Transform2D::~Transform2D()
    {
        if (m_parent == nullptr)
        {
            return;
        }
        
        RemoveParent();
    }

    Vector2 Transform2D::Position() const
    {
        return m_position;
    }

    void Transform2D::Position(Vector2 _newPos)
    {
        m_position = _newPos;

        // �e������΃��[�J���l���v�Z����
        if (m_parent != nullptr)
        {
            m_localPosition = m_position - m_parent->m_position;
        }
        else
        {
            m_localPosition = m_position;
        }

        // �q�̒l���v�Z����
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

        // �e������΃��[�J���l���v�Z����
        if (m_parent != nullptr)
        {
            m_localRotation = m_rotation - m_parent->m_rotation;
        }
        else
        {
            m_localRotation = m_rotation;
        }

        m_localRotation = CorrectionRotation(m_localRotation);

        // �q�̒l���v�Z����
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
    }

    Vector2 Transform2D::GetUpVector() const
    {
        Vector2 up;

        // ������̃x�N�g�����v�Z
        up.x = cosf(m_rotation - (float)M_PI_2);
        up.y = sinf(m_rotation - (float)M_PI_2);

        return up;
    }

    Vector2 Transform2D::GetRightVector() const
    {
        Vector2 right;

        // �E�����̃x�N�g�����v�Z
        right.x = cosf(m_rotation);
        right.y = sinf(m_rotation);

        return right;
    }

    void Transform2D::Parent(Transform2D * _parent)
    {
        // ���Ԗڂ̎q���擾
        m_childNum = _parent->m_children.size();
        // �e�Ɏq�Ƃ��ēo�^
        _parent->m_children.push_back(this);
        // �e��ۑ�
        m_parent = _parent;

        // ���[�J���l���v�Z
        m_localPosition = m_position - _parent->m_position;
        m_localRotation = CorrectionRotation(m_rotation - _parent->m_rotation);
    }

    Transform2D * Transform2D::Parent() const
    {
        return m_parent;
    }

    void Transform2D::RemoveParent()
    {
        // �e�q�֌W������
        m_parent->m_children.erase(m_parent->m_children.begin() + m_childNum);
        m_parent = nullptr;

        // ���[�J���l�Ƀ��[���h�l������
        m_localPosition = m_position;
        m_localRotation = m_rotation;
    }

    float Transform2D::CorrectionRotation(float _rotation)
    {
        // �p�x�� -180���`180���ɂȂ�悤�ɕ␳
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
            // �q�̕������v�Z
            float childAng = m_rotation +
                atan2f(child->m_localPosition.y, child->m_localPosition.x);
            // �q�Ƃ̋������擾
            float length = child->m_localPosition.Magnitude();

            // �l���w��
            child->Rotation(m_rotation + child->m_localRotation);

            child->m_position = m_position +
                Vector2(cosf(childAng), sinf(childAng)) * length;
        }
    }

} // CreaDXTKLib
} // Math