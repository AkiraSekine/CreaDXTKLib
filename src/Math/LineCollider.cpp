#include "../Inc/Math/Collider2D.h"

namespace CreaDXTKLib
{
namespace Math
{
    LineCollider::LineCollider(const Vector2& _start, const Vector2& _end) :
        lineVec(_end - _start)
    {
        point[0] = &_start;
        point[1] = &_end;

        m_shape = Line;
    }

    Collider2D * LineCollider::CheckCircle(CircleCollider * _target) const
    {
        // �[�_���~�ɓ������Ă��邩�̔���
        for (unsigned char i = 0u; i < numOfPoints; i++)
        {
            float distance;

            // �[�_�Ɖ~�̒��S�����~�̔��a�ȉ��̋����Ȃ瓖�����Ă���
            distance = (_target->position - *point[i]).SqrMagnitude();

            if (distance <= _target->radius * _target->radius)
            {
                return (Collider2D*)_target;
            }
        }

        Vector2 circleStart = _target->position - *point[0];
        float lineMag = 1.f / lineVec.Magnitude();

        // �����Ɖ~�̒��S�Ƃ̍ŒZ�������~�̔��a�ȉ����̔���
        if (circleStart.Cross(lineVec) * lineMag <= _target->radius)
        {
            Vector2 circleEnd = *point[1] - _target->position;

            // �~�̒��S�Ɛ����̍ŒZ�����̈ʒu�������̓����ł���Γ������Ă���
            if (circleStart.Dot(lineVec)*lineMag * circleEnd.Dot(lineVec)*lineMag > 0.f)
            {
                return (Collider2D*)_target;
            }
        }

        return nullptr;
    }

    Collider2D * LineCollider::CheckBox(BoxCollider * _target) const
    {
        // ��`�̕ӂƌ������Ă���Γ������Ă���
        for (unsigned char i = 0u; i < BoxCollider::numOfLines; i++)
        {
            Collider2D* result =
                _target->lines[i]->CheckCollision((Collider2D*)this);

            if ((bool)result)
            {
                return result;
            }
        }

        // �[�_����`�̓����ɓ����Ă���Γ������Ă���
        for (unsigned char i = 0; i < BoxCollider::numOfLines; i++)
        {
            bool in = false;

            for (unsigned char j = 0u; j < numOfPoints; j++)
            {
                // �[�_�ƕӂ̎n�_�̃x�N�g�����v�Z
                Vector2 vec = *point[j] - *_target->lines[i]->point[0];
                // �ӂ̃x�N�g���ƒ[�_�ƕӂ̎n�_�̃x�N�g�����O�ς���
                float check = _target->lines[i]->lineVec.Cross(vec);

                // �}�C�i�X�̒l�Ȃ瓖�����Ă���
                if (check <= 0)
                {
                    in = true;

                    break;
                }
            }

            // 1�ł��v���X�̒l�Ȃ瓖�����Ă��Ȃ�
            if (!in)
            {
                return nullptr;
            }
        }

        return (Collider2D*)_target;
    }

    Collider2D * LineCollider::CheckLine(LineCollider * _target) const
    {
        // 2�̐����̃x�N�g���̊O��
        float twoVec = 1.f / lineVec.Cross(_target->lineVec);
        // �n�_����^�[�Q�b�g�̎n�_�ւ̃x�N�g��
        Vector2 vec = *_target->point[0] - *point[0];

        // ��_�ւ̃x�N�g��
        float check1 = vec.Cross(lineVec) * twoVec;
        float check2 = vec.Cross(_target->lineVec) * twoVec;

        // 2�̐����̌�_�ւ̃x�N�g���� 0�`1 �Ȃ�������Ă���
        if (check1 >= 0 && check1 <= 1 &&
            check2 >= 0 && check2 <= 1)
        {
            return _target;
        }

        return nullptr;
    }
} // Math
} // CreaDXTKLib