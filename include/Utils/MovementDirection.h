#pragma once

class Vector2D;

enum class MovementDirection {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    NONE,
};

Vector2D GetPositionFromDirection(MovementDirection direction);