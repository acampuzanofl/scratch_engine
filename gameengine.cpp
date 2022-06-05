#include "gameengine.h"
#include "gamestate.h"

GameEngine::GameEngine()
{
    deltaTime = clock.restart().asSeconds();
}

GameEngine::~GameEngine()
{ 
    delete pApplicationWindow;
}

void GameEngine::Init()
{

    pApplicationWindow = new sf::RenderWindow(sf::VideoMode(900, 600), "Scratch Engine");
    pApplicationWindow->setFramerateLimit(60);
    deltaTime = 1;

    m_running = true;
}

void GameEngine::Cleanup()
{
    // cleanup the all states
    while (!states.empty())
    {
        states.back()->Cleanup();
        states.pop_back();
    }
}

void GameEngine::PushState(GameState *state)
{
    // pause current state
    if (!states.empty())
    {
        states.back()->Pause();
        // previousState = currentState;
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init();
}

void GameEngine::PopState()
{
    // cleanup the current state
    if (!states.empty())
    {
        states.back()->Cleanup();
        states.pop_back();
    }

    // resume previous state
    if (!states.empty())
    {
        states.back()->Resume();
    }
}

void GameEngine::HandleEvents()
{
    // let the state handle events
    states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
    // let the state update the game
    states.back()->Update(this);
}

void GameEngine::Draw()
{
    // let the state draw the screen
    states.back()->Draw(this);
}

void GameEngine::CalculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}

float GameEngine::GetDeltaTime()
{
    return deltaTime;
}

void GameEngine::PollKey()
{
    input.Update();
}