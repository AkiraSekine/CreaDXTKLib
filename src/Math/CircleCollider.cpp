#include "../Inc/Math/Collider2D.h"

namespace CreaDXTKLib
{
namespace Math
{
    CircleCollider::CircleCollider(const Vector2& _position, const float& _radius) :
        position(&_position),
        radius(&_radius)
    {
        m_shape = Circle;
    }

    Collider2D * CircleCollider::CheckCircle(CircleCollider* _target) const
    {
        // ���S���W����^�[�Q�b�g�̒��S���W�ւ̃x�N�g��
        Vector2 distanceVector = *_target->position - *position;

        // ����̍Œ�����
        float distance = (*radius + *_target->radius) * (*radius  + *_target->radius);

        // ��_�Ԃ̋���������̍Œ������ȉ��Ȃ瓖�����Ă���
        if (distanceVector.SqrMagnitude() <= distance)
        {
            return (Collider2D*)_target;
        }

        return nullptr;
    }

    Collider2D * CircleCollider::CheckBox(BoxCollider* _target) const
    {
        bool check = (_target->CheckCollision((Collider2D*)this) != nullptr);

        return (check ? (Collider2D*)_target : nullptr);
    }

    Collider2D * CircleCollider::CheckLine(LineCollider* _target) const
    {
    bool check = (_target->CheckCollision((Collider2D*)this) != nullptr);

        return (check ? (Collider2D*)_target : nullptr);
    }
} // Math
} // CreaDXTKLib