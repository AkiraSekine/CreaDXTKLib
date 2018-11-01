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
        // 中心座標からターゲットの中心座標へのベクトル
        Vector2 distanceVector = *_target->position - *position;

        // 判定の最長距離
        float distance = (*radius + *_target->radius) * (*radius  + *_target->radius);

        // 二点間の距離が判定の最長距離以下なら当たっている
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