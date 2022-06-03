#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "entities.h"

struct Coordinates
{
    float x;
    float y;
};

class Transform : public Entity
{
    public:
        Transform(){};
        ~Transform(){};

        Coordinates getPosition();
        void updatePosition(Coordinates position);

    private:
        Coordinates position;
};


#endif // TRANSFORM_H