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
        // 中心座標からターゲットの中心座標へのベクトル
        Vector2 distanceVector = _target->position - position;

        // 判定の最長距離
        float distance = radius * radius + _target->radius * _target->radius;

        // 二点間の距離が判定の最長距離以下なら当たっている
        if (distanceVector.SqrMagnitude() <= distance)
        {
            return (Collider2D*)_target;
        }

        return nullptr;
    }

    Collider2D * CircleCollider::CheckBox(BoxCollider* _target) const
    {
        // 矩形の全ての辺と当たっていれば当たっている
        for (unsigned char i = 0u; i < BoxCollider::numOfLines; i++)
        {
            Collider2D* check = CheckLine(_target->lines[i]);

            if ((bool)check)
            {
                return (Collider2D*)_target;
            }
        }

        // 中心座標が矩形の内側に入っていれば当たっている
        for (unsigned char i = 0u; i < BoxCollider::numOfLines; i++)
        {
            bool in = false;

            // 端点と辺の始点のベクトルを計算
            Vector2 vec = position - *_target->lines[i]->point[0];
            // 辺のベクトルと端点と辺の始点のベクトルを外積する
            float check = _target->lines[i]->lineVec.Cross(vec);

            // 1つでもプラスの値なら当たっていない
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