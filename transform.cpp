#include "transform.h"


Transform::Transform()
{

}

Transform::~Transform()
{

}

Coordinates Transform::GetPosition()
{
    return position;
}

void Transform::UpdatePosition(Coordinates position)
{
    this->position.x = position.x;
    this->position.y = position.y;
}