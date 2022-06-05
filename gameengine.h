#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "inputmanager.h"

class GameState;

class GameEngine
{
public:
	// handle to application window
	sf::RenderWindow* pApplicationWindow;
	InputManager inputManager;

	void Init();
	void Cleanup();

	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	void CalculateDeltaTime();
	float GetDeltaTime();

	void PollKey();

	GameEngine();
	~GameEngine();

private:
	// the stack of states
	std::vector<GameState*> states;

	sf::Clock clock;
	float deltaTime;

	bool m_running;
};

#endif