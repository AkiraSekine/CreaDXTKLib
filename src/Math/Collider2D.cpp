#include "../Inc/Math/Collider2D.h"

namespace CreaDXTKLib
{
namespace Math
{
    Collider2D * Collider2D::CheckCollision() const
    {
        // �^�[�Q�b�g�Ƃ̓����蔻��
        for (Collider2D* target : m_targets)
        {
            Collider2D* result = nullptr;

            result = CheckCollision(target);

            // �������Ă����瓖�������R���C�_�[��Ԃ�
            if (result != nullptr)
            {
                return result;
            }
        }

        return nullptr;
    }

    Collider2D * Collider2D::CheckCollision(Collider2D * _collider) const
    {
        Collider2D* result = nullptr;

        // �^�[�Q�b�g�̌`��ɉ����ă��\�b�h���Ă�
        switch (_collider->shape)
        {
        case Circle:
        {
            CircleCollider* circle = dynamic_cast<CircleCollider*>(_collider);
            result = CheckCircle(circle);

            break;
        }
        case Box:
        {
            BoxCollider* box = dynamic_cast<BoxCollider*>(_collider);
            result = CheckBox(box);

            break;
        }
        case Line:
        {
            LineCollider* line = dynamic_cast<LineCollider*>(_collider);
            result = CheckLine(line);

            break;
        }
        }

        return result;
    }

    void Collider2D::AddTarget(Collider2D * _collider)
    {
        m_targets.push_back(_collider);
    }
} // Math
} // CreaDXTKLib