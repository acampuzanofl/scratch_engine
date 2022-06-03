#include "character.h"

void Character::Init(GameEngine* game)
{
    printf("character init\n");
}

void Character::Update(GameEngine* game)
{
    animations[AnimState::Idle].UpdateFrame(game->GetDeltaTime());
}
