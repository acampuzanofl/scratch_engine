#include <SFML/Graphics.hpp>

#include "inputmanager.h"

void InputManager::Update()
{
    lastFrameKeys = thisFrameKeys;
    thisFrameKeys = 0;
    thisFrameKeys = thisFrameKeys | Key::Left * sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    thisFrameKeys = thisFrameKeys | Key::Up * sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    thisFrameKeys = thisFrameKeys | Key::Right * sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    thisFrameKeys = thisFrameKeys | Key::Down * sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    thisFrameKeys = thisFrameKeys | Key::Esc * sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    //printf("last: %x this: %x\n", lastFrameKeys, thisFrameKeys);
}

bool InputManager::IsKeyPressed(Key keycode)
{
    return (thisFrameKeys & keycode) != 0;
}

bool InputManager::IsKeyDown(Key keycode)
{
    bool lastFrame = (lastFrameKeys & keycode) != 0;
    bool thisFrame = (thisFrameKeys & keycode) != 0;
    return thisFrame && !lastFrame;
}

bool InputManager::IsKeyUp(Key keycode)
{
    bool lastFrame = (lastFrameKeys & keycode) != 0;
    bool thisFrame = (thisFrameKeys & keycode) != 0;
    return !thisFrame && lastFrame;
}