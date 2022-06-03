#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include <map>

#include "animation.h"
#include "transform.h"

struct SpriteMap
{
    uint32_t id;
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;

    bool operator<(const SpriteMap& a)
    {
        uint32_t id1 = (id >> 24) |
         ((id<<8) & 0x00FF0000) |
         ((id>>8) & 0x0000FF00) |
         (id << 24);

        uint32_t id2 = (a.id >> 24) |
         ((a.id<<8) & 0x00FF0000) |
         ((a.id>>8) & 0x0000FF00) |
         (a.id << 24);

        return id1 < id2;
    }

};

class Sprite : public Transform
{
    public:
    
        std::map<AnimState, Animation> animations;
        
        Sprite(){};
        ~Sprite(){};

        AnimState GetState();
        void SetState();

        void Draw(GameEngine* game);

        void LoadAnim(AnimState state, std::vector<SpriteMap>& spriteMap);
        void LoadSheet(const char* path);
        std::vector<SpriteMap> LoadMap(const char* path);

    private:
        void SetSpriteRect(const FrameData* frameData);

        sf::Sprite sprite;
        sf::Texture spriteSheet;

};

#endif