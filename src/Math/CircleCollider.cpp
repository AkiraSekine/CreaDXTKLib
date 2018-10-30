#include "../Inc/Math/Collider2D.h"

namespace CreaDXTKLib
{
namespace Math
{
    CircleCollider::CircleCollider(const Vector2& _position, const float& _radius) :
        position(_position),
        radius(_radius)
    {
        m_shape = Circle;
    }

    Collider2D * CircleCollider::CheckCircle(CircleCollider* _target) const
    {
        // ���S���W����^�[�Q�b�g�̒��S���W�ւ̃x�N�g��
        Vector2 distanceVector = _target->position - position;

        // ����̍Œ�����
        float distance = radius * radius + _target->radius * _target->radius;

        // ��_�Ԃ̋���������̍Œ������ȉ��Ȃ瓖�����Ă���
        if (distanceVector.SqrMagnitude() <= distance)
        {
            return (Collider2D*)_target;
        }

        return nullptr;
    }

    Collider2D * CircleCollider::CheckBox(BoxCollider* _target) const
    {
        // ��`�̑S�Ă̕ӂƓ������Ă���Γ������Ă���
        for (unsigned char i = 0u; i < BoxCollider::numOfLines; i++)
        {
            Collider2D* check = CheckLine(_target->lines[i]);

            if ((bool)check)
            {
                return (Collider2D*)_target;
            }
        }

        // ���S���W����`�̓����ɓ����Ă���Γ������Ă���
        for (unsigned char i = 0u; i < BoxCollider::numOfLines; i++)
        {
            bool in = false;

            // �[�_�ƕӂ̎n�_�̃x�N�g�����v�Z
            Vector2 vec = position - *_target->lines[i]->point[0];
            // �ӂ̃x�N�g���ƒ[�_�ƕӂ̎n�_�̃x�N�g�����O�ς���
            float check = _target->lines[i]->lineVec.Cross(vec);

            // 1�ł��v���X�̒l�Ȃ瓖�����Ă��Ȃ�
            if (check > 0)
            {
                return nullptr;
            }
        }

        return (Collider2D*)_target;
    }

    Collider2D * CircleCollider::CheckLine(LineCollider* _target) const
    {
        return _target->CheckCollision((Collider2D*)this);
    }
} // Math
} // CreaDXTKLib