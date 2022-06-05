#ifndef ENTITIES_H
#define ENTITIES_H

#include <SFML/Graphics.hpp>

#include "gameengine.h"
#include "entityTypes.h"

// Entity class will contain information on a game objects position, collision, name, sprite, and drawing.
// Entity will be responsible for lifetime, updating and cleaning

class Entity
{
    public:
        Entity(){};
        ~Entity(){};

        virtual void Init(GameEngine* game) = 0;
        virtual void HandleEvents(GameEngine* game) = 0;
        virtual void Update(GameEngine* game) = 0;
        virtual void Draw(GameEngine* game) = 0;

    private:
        EntityType type;
        uint8_t Exist;
};

#endif //ENTITIES_H