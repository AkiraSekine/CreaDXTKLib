#include "../Inc/Math/Collider2D.h"

using namespace std;

namespace CreaDXTKLib
{
namespace Math
{
    Collider2D::Collider2D()
    {
        m_targets = vector<Collider2D*>();
    }

    Collider2D::~Collider2D()
    {
        m_targets.clear();
    }

    Collider2D * Collider2D::CheckCollision() const
    {
        // �^�[�Q�b�g�Ƃ̓����蔻��
        for (Collider2D* target : m_targets)
        {
            if (target == nullptr)
            {
                continue;
            }

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
        if (_collider == nullptr)
        {
            return nullptr;
        }

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

    void Collider2D::EraseTarget(Collider2D * _collider)
    {
        unsigned int count = 0;

        for (Collider2D* target : m_targets)
        {
            // _collider�Ɨv�f�������A�h���X�Ȃ�v�f����폜
            if (target == _collider)
            {
                m_targets.erase(m_targets.begin() + count);

                return;
            }

            count++;
        }
    }
} // Math
} // CreaDXTKLib