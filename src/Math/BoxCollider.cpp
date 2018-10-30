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

        // 矩形は4つの辺からできているため4つの辺に同じターゲットを追加
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
        // お互いの全ての辺同士の当たり判定を行う
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