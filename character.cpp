#include "character.h"

void Character::Init(GameEngine* game)
{
    LoadSheet("assets/WagnerSheet/Wagner.sheet");

    LoadAnim(AnimState::Idle, LoadMap("assets/WagnerIdleAnim/WagnerIdle.map"));
    LoadAnim(AnimState::Walk, LoadMap("assets/WagnerWalkAnim/WagnerWalk.map"));

    SetAnimState(AnimState::Idle);
}

void Character::Update(GameEngine* game)
{
    animations[GetAnimState()].UpdateFrame(game->GetDeltaTime());
    //animations[AnimState::Idle].UpdateFrame(game->GetDeltaTime());
}
