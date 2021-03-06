#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"

class Character : public Sprite
{
    public:
        Character(){};
        ~Character(){};

        void Init(GameEngine* game);
        void HandleEvents(GameEngine* game);
        void Update(GameEngine* game);
        
    private:
    Coordinates position;
};

#endif