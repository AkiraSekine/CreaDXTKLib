#include "Collider2D.h"

namespace CreaDXTKLib
{
namespace Math
{
    BoxCollider::BoxCollider(const Vector2 & _centerPosition, const Vector2 & _size) :
        centerPosition(_centerPosition),
        size(_size)
    {
        m_shape = Box;
    }

    BoxCollider::~BoxCollider()
    {
        for (int i = 0; i < numOfLines; i++)
        {
            delete lines[i];
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
        return _target->CheckCollision((Collider2D*)this);
    }

    Collider2D * BoxCollider::CheckBox(BoxCollider * _target) const
    {
        // ���݂��̑S�Ă̕ӓ��m�̓����蔻����s��
        for (unsigned char i = 0u; i < numOfLines; i++)
        {
            for (unsigned char j = 0u; j < numOfLines; j++)
            {
                Collider2D* check = lines[i]->CheckCollision(_target->lines[j]);

                if ((bool)check)
                {
                    return check;
                }
            }
        }

        return nullptr;
    }

    Collider2D * BoxCollider::CheckLine(LineCollider * _target) const
    {
        return _target->CheckCollision((Collider2D*)this);
    }
} // Math
} // CreaDXTKLib