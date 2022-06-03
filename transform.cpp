#include "transform.h"

Coordinates Transform::getPosition()
{
    position.x = x;
    position.y = y;
    return position;
}

void Transform::updatePosition(Coordinates position)
{
    x = position.x;
    y = position.y;
}