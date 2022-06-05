#include "character.h"

void Character::Init(GameEngine* game)
{
    // load character sheet
    LoadSheet("assets/WagnerSheet/Wagner.sheet");

    // load animations
    LoadAnim(AnimState::Idle, LoadMap("assets/WagnerIdleAnim/WagnerIdle.map"), 1.f/15.f);
    LoadAnim(AnimState::Walk, LoadMap("assets/WagnerWalkAnim/WagnerWalk.map"), 1.f/7.5f);

    //set default animations
    SetAnimState(AnimState::None);

    //set default positions
    position.x = 0;
    position.y = 0;
    UpdatePosition(position);
}

void Character::HandleEvents(GameEngine* game)
{
    int movspeed = 300;
    int frameMoveX = 0;
    if(game->inputManager.IsKeyPressed(InputManager::Key::Right)){
        frameMoveX = movspeed;
        SetAnimState(AnimState::Walk);
    }
    else if(game->inputManager.IsKeyPressed(InputManager::Key::Left)){
        frameMoveX = -movspeed;
        SetAnimState(AnimState::Walk);
    }
    else{
        SetAnimState(AnimState::Idle);
    }

    position.x += frameMoveX*game->GetDeltaTime(); 
}

void Character::Update(GameEngine* game)
{

    // update position
    UpdatePosition(position);

    // Update Animation
    animations[GetAnimState()].UpdateFrame(game->GetDeltaTime());
    //animations[AnimState::Idle].UpdateFrame(game->GetDeltaTime());

}


