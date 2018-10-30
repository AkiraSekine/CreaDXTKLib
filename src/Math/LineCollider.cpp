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
        // 端点が円に当たっているかの判定
        for (unsigned char i = 0u; i < numOfPoints; i++)
        {
            float distance;

            // 端点と円の中心がが円の半径以下の距離なら当たっている
            distance = (_target->position - *point[i]).SqrMagnitude();

            if (distance <= _target->radius * _target->radius)
            {
                return (Collider2D*)_target;
            }
        }

        Vector2 circleStart = _target->position - *point[0];
        float lineMag = 1.f / lineVec.Magnitude();

        // 線分と円の中心との最短距離が円の半径以下かの判定
        if (circleStart.Cross(lineVec) * lineMag <= _target->radius)
        {
            Vector2 circleEnd = *point[1] - _target->position;

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
        // 矩形の辺と交差していれば当たっている
        for (unsigned char i = 0u; i < BoxCollider::numOfLines; i++)
        {
            Collider2D* result =
                _target->lines[i]->CheckCollision((Collider2D*)this);

            if ((bool)result)
            {
                return result;
            }
        }

        // 端点が矩形の内側に入っていれば当たっている
        for (unsigned char i = 0; i < BoxCollider::numOfLines; i++)
        {
            bool in = false;

            for (unsigned char j = 0u; j < numOfPoints; j++)
            {
                // 端点と辺の始点のベクトルを計算
                Vector2 vec = *point[j] - *_target->lines[i]->point[0];
                // 辺のベクトルと端点と辺の始点のベクトルを外積する
                float check = _target->lines[i]->lineVec.Cross(vec);

                // マイナスの値なら当たっている
                if (check <= 0)
                {
                    in = true;

                    break;
                }
            }

            // 1つでもプラスの値なら当たっていない
            if (!in)
            {
                return nullptr;
            }
        }

        return (Collider2D*)_target;
    }

    Collider2D * LineCollider::CheckLine(LineCollider * _target) const
    {
        // 2つの線分のベクトルの外積
        float twoVec = 1.f / lineVec.Cross(_target->lineVec);
        // 始点からターゲットの始点へのベクトル
        Vector2 vec = *_target->point[0] - *point[0];

        // 交点へのベクトル
        float check1 = vec.Cross(lineVec) * twoVec;
        float check2 = vec.Cross(_target->lineVec) * twoVec;

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