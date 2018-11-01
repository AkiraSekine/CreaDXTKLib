#include "../Inc/Math/Collider2D.h"

namespace CreaDXTKLib
{
namespace Math
{
    LineCollider::LineCollider(const Vector2& _start, const Vector2& _end)
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
            distance = (*_target->position - *point[i]).SqrMagnitude();

            if (distance <= *_target->radius * *_target->radius)
            {
                return (Collider2D*)_target;
            }
        }

        Vector2 circleStart = *_target->position - *point[0];
        Vector2 lineVec = *point[1] - *point[0];
        float lineMag = 1.f / lineVec.Magnitude();

        // �����Ɖ~�̒��S�Ƃ̍ŒZ�������~�̔��a�ȉ����̔���
        if (abs(circleStart.Cross(lineVec) * lineMag) <= *_target->radius)
        {
            Vector2 circleEnd = *point[1] - *_target->position;

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
        // �^�[�Q�b�g�̃R���C�_�[�ŏՓ˂����o
        bool check = (_target->CheckCollision((Collider2D*)this) != nullptr);
        
        return (check ? (Collider2D*)_target : nullptr);
    }

    Collider2D * LineCollider::CheckLine(LineCollider * _target) const
    {
        // �����̃x�N�g��
        Vector2 lineVec = *point[1] - *point[0];
        // �^�[�Q�b�g�̐����̃x�N�g��
        Vector2 targetLineVec = *_target->point[1] - *_target->point[0];

        // 2�̐����̃x�N�g���̊O��
        float twoVec = 1.f / lineVec.Cross(targetLineVec);
        // �n�_����^�[�Q�b�g�̎n�_�ւ̃x�N�g��
        Vector2 vec = *_target->point[0] - *point[0];

        // ��_�ւ̃x�N�g��
        float check1 = vec.Cross(lineVec) * twoVec;
        float check2 = vec.Cross(targetLineVec) * twoVec;

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