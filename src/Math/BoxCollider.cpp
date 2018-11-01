#include "Collider2D.h"

namespace CreaDXTKLib
{
namespace Math
{
    BoxCollider::BoxCollider(const Vector2& _centerPosition, const Vector2& _size, const float& _rotation) :
        centerPosition(&_centerPosition),
        size(&_size),
        m_rot(&_rotation)
    {
        m_shape = Box;

        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            m_corners[i] = new Vector2();
        }

        CalcCorners();

        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            if (i != numOfLines - 1)
            {
                lines[i] = new LineCollider(*m_corners[i], *m_corners[i + 1]);
            }
            else
            {
                lines[i] = new LineCollider(*m_corners[i], *m_corners[0]);
            }
        }
    }

    BoxCollider::~BoxCollider()
    {
        for (int i = 0; i < numOfLines; i++)
        {
            delete lines[i];
            delete m_corners[i];
        }
    }

    void BoxCollider::AddTarget(Collider2D * _collider)
    {
        m_targets.push_back(_collider);

        // ��`��4�̕ӂ���ł��Ă��邽��4�̕ӂɓ����^�[�Q�b�g��ǉ�
        for (int i = 0; i < 4; i++)
        {
            lines[i]->AddTarget(_collider);
        }
    }

    Collider2D * BoxCollider::CheckCircle(CircleCollider * _target) const
    {
        CalcCorners();

        // �ӂƉ~���~�̔��a�ȉ��̋����Ȃ瓖�����Ă���
        for (unsigned char i = 0u; i < BoxCollider::numOfLines; i++)
        {
            // �ӂ̎����Ă���LineCollider�Ɖ~�̏Փ˂��擾
            Collider2D* check = lines[i]->CheckCollision(_target);

            if (check != nullptr)
            {
                return (Collider2D*)_target;
            }
        }

        // ���S���W����`�̓����ɓ����Ă���Γ������Ă���
        if (IsInside(*_target->position))
        {
            return (Collider2D*)_target;
        }

        return nullptr;
    }

    Collider2D * BoxCollider::CheckBox(BoxCollider * _target) const
    {
        CalcCorners();
        _target->CalcCorners();

        // ���_���ǂ��炩�̓����ɓ����Ă���Γ������Ă���
        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            if (IsInside(*_target->m_corners[i]) || _target->IsInside(*m_corners[i]))
            {
                return (Collider2D*)_target;
            }
        }

        // ���݂��̑S�Ă̕ӓ��m�̓����蔻����s��
        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            for (unsigned char j = 0u; j < numOfLines; j++)
            {
    // �ӂ�LineCollider���g���ă^�[�Q�b�g�̕ӂƂ̏Փ˂����o
                Collider2D* check = lines[i]->CheckCollision(_target->lines[j]);

                if (check != nullptr)
                {
                    return (Collider2D*)_target;
                }
            }
        }

        return nullptr;
    }

    Collider2D * BoxCollider::CheckLine(LineCollider * _target) const
    {
        CalcCorners();

        // �ӂƐ������������Ă���Γ������Ă���
        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            Collider2D* result = _target->CheckCollision((Collider2D*)lines[i]);

            if (result != nullptr)
            {
                return (Collider2D*)_target;
            }
        }

        // �[�_����`�̓����ɓ����Ă���Γ������Ă���
        for (unsigned char i = 0u; i < LineCollider::numOfPoints; i++)
        {
            if (IsInside(*_target->point[i]))
            {
                return (Collider2D*)_target;
            }
        }

        return nullptr;
    }

    bool BoxCollider::IsInside(const Vector2 & _pos) const
    {
        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            // �ӂ̎n�_����_�ւ̃x�N�g��
            Vector2 vec = _pos - *lines[i]->point[0];
            // �ӂ̃x�N�g��
            Vector2 lineVec = *lines[i]->point[1] - *lines[i]->point[0];
            // �ӂ�vec���O�ς���
            float check = lineVec.Cross(vec);

            // �O�ς����l������������O��
            if (check < 0)
            {
                return false;
            }
        }

        return true;
    }

    void BoxCollider::CalcCorners() const
    {
        Vector2 halfSize = *size * 0.5f;

        *m_corners[0] = -halfSize;
        *m_corners[1] = Vector2(halfSize.x, -halfSize.y);
        *m_corners[2] = halfSize;
        *m_corners[3] = Vector2(-halfSize.x, halfSize.y);

        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            Vector2 newPos;

            newPos.x = m_corners[i]->x * cosf(*m_rot) - m_corners[i]->y * sinf(*m_rot);
            newPos.y = m_corners[i]->x * sinf(*m_rot) + m_corners[i]->y * cosf(*m_rot);

            *m_corners[i] = *centerPosition + newPos;
        }
    }
} // Math
} // CreaDXTKLib