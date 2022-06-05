#include "gameengine.h"
#include "levelstate.h"

int main(int argc, char const *argv[])
{
    GameEngine game;

    // initialize the engine
    game.Init();

    // load the level
	game.PushState( LevelState::Instance() );

	// main loop
	while ( game.Running() )
	{
		game.PollKey();
		game.HandleEvents();
		game.Update();
		game.Draw();
		game.CalculateDeltaTime();
	}

	// cleanup the engine
	game.Cleanup();

    return 0;
}
