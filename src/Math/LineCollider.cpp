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
        // 端点が円に当たっているかの判定
        for (unsigned char i = 0u; i < numOfPoints; i++)
        {
            float distance;

            // 端点と円の中心がが円の半径以下の距離なら当たっている
            distance = (*_target->position - *point[i]).SqrMagnitude();

            if (distance <= *_target->radius * *_target->radius)
            {
                return (Collider2D*)_target;
            }
        }

        Vector2 circleStart = *_target->position - *point[0];
        Vector2 lineVec = *point[1] - *point[0];
        float lineMag = 1.f / lineVec.Magnitude();

        // 線分と円の中心との最短距離が円の半径以下かの判定
        if (abs(circleStart.Cross(lineVec) * lineMag) <= *_target->radius)
        {
            Vector2 circleEnd = *point[1] - *_target->position;

            // 円の中心と線分の最短距離の位置が線分の内側であれば当たっている
            if (circleStart.Dot(lineVec)*lineMag * circleEnd.Dot(lineVec)*lineMag > 0.f)
            {
                return (Collider2D*)_target;
            }
        }

        return nullptr;
    }

    Collider2D * LineCollider::CheckBox(BoxCollider * _target) const
    {
        // ターゲットのコライダーで衝突を検出
        bool check = (_target->CheckCollision((Collider2D*)this) != nullptr);
        
        return (check ? (Collider2D*)_target : nullptr);
    }

    Collider2D * LineCollider::CheckLine(LineCollider * _target) const
    {
        // 線分のベクトル
        Vector2 lineVec = *point[1] - *point[0];
        // ターゲットの線分のベクトル
        Vector2 targetLineVec = *_target->point[1] - *_target->point[0];

        // 2つの線分のベクトルの外積
        float twoVec = 1.f / lineVec.Cross(targetLineVec);
        // 始点からターゲットの始点へのベクトル
        Vector2 vec = *_target->point[0] - *point[0];

        // 交点へのベクトル
        float check1 = vec.Cross(lineVec) * twoVec;
        float check2 = vec.Cross(targetLineVec) * twoVec;

        // 2つの線分の交点へのベクトルが 0～1 なら交差している
        if (check1 >= 0 && check1 <= 1 &&
            check2 >= 0 && check2 <= 1)
        {
            return _target;
        }

        return nullptr;
    }
} // Math
} // CreaDXTKLib