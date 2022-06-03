#ifndef LEVELSTATE_H
#define LEVELSTATE_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "character.h"

class LevelState : public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static LevelState* Instance(){
    	return &m_LevelState;
	}

protected:
	LevelState() { };

private:
	Character player;
    static LevelState m_LevelState;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};

#endif
