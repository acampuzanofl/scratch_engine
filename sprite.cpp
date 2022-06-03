#include <fstream>
#include <stdio.h>
#include <algorithm>

#include "sprite.h"

std::vector<SpriteMap> Sprite::LoadMap(const char *LoadMap)
{
    std::ifstream f(LoadMap, std::ios::ate | std::ios::binary);
    uint32_t size;
    uint16_t numberOfMaps;
    SpriteMap* mapBlocks;
    std::vector<SpriteMap> spriteMaps;

    if( !f.is_open() ){    
        perror("failed to open file");
        return std::vector<SpriteMap>();
    }

    size = f.tellg();
    f.seekg(std::ios::beg);
    numberOfMaps = size / sizeof(SpriteMap);

    mapBlocks = new SpriteMap[numberOfMaps];

    f.read((char*)mapBlocks, size);
    for(int i = 0; i < numberOfMaps; i++){
        spriteMaps.push_back(mapBlocks[i]);
    }

    delete[] mapBlocks;

    f.close();

    std::sort(spriteMaps.begin(), spriteMaps.end());

    return spriteMaps;
}

void Sprite::LoadSheet(const char* path)
{
    spriteSheet.loadFromFile(path);

    sprite.setTexture(spriteSheet);
}

void Sprite::LoadAnim(AnimState state, std::vector<SpriteMap>& spriteMap)
{
    Animation anim;

    for(auto frame : spriteMap){
        anim.AddFrame(frame.id, frame.x, frame.y, frame.width, frame.height, .1);
    }

    animations[state] = anim;
}

void Sprite::SetSpriteRect(const FrameData* frameData)
{
    sprite.setTextureRect( sf::IntRect(frameData->x, frameData->y, frameData->width, frameData->height) ); 
}

void Sprite::Draw(GameEngine* game)
{
    auto currentFrame = animations[AnimState::Idle].GetCurrentFrame();
    SetSpriteRect(currentFrame);

    game->pApplicationWindow->draw(sprite);
}
