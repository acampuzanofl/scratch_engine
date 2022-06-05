#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "gameengine.h"
#include "levelstate.h"

LevelState LevelState::m_LevelState;

void LevelState::Init()
{
    // load game assets
    backgroundTexture.loadFromFile("assets/backgrounds/grid.jpg");

    // set sprites
    backgroundSprite.setTexture(backgroundTexture);

    // scale background to current window
    sf::Vector2f targetSize(900, 600);
    backgroundSprite.setScale(targetSize.x / backgroundSprite.getLocalBounds().width, targetSize.y / backgroundSprite.getLocalBounds().height);

    // load character
    player.Init(nullptr);
}

void LevelState::Cleanup()
{
}

void LevelState::Pause()
{
}

void LevelState::Resume()
{
}

void LevelState::HandleEvents(GameEngine *game)
{
    // handle window events
    sf::Event event;
    while (game->pApplicationWindow->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            game->Quit();
        }
    }

    // handle characters events
    player.HandleEvents(game);
}

void LevelState::Update(GameEngine *game)
{
    player.Update(game);
}

void LevelState::Draw(GameEngine *game)
{
    // draw background
    game->pApplicationWindow->draw(backgroundSprite);

    // draw player
    player.Draw(game);

    // update display
    game->pApplicationWindow->display();
}
