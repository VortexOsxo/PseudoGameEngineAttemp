#include <Utils/MovementDirection.h>

#include <Utils/Vector2D.h>

Vector2D GetPositionFromDirection(MovementDirection direction)
{
    switch (direction) {
        case MovementDirection::UP:
            return {-1.f, 0.f};
        
        case MovementDirection::DOWN:
            return {1.f, 0.f};

        case MovementDirection::RIGHT:
            return {0.f, 1.f};
        
        case MovementDirection::LEFT:
            return {0.f, -1.f};
        default:
            return {0.f, 0.f};
    }
}