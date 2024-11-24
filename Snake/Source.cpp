#include <raylib.h>
#include "Game.h"
#include "Config.h"

int main()
{

	InitWindow(2*Config::offset + Config::cellCount*Config::cellSize,2*Config::offset + Config::cellCount*Config::cellSize, "Retro Snake");
	SetTargetFPS(60);

	Game game = Game::CreateGame();

	while (!WindowShouldClose())
	{
		if(game.eventTriggered(Config::interval))
			game.Update();

		game.CheckMove();

		BeginDrawing();
		ClearBackground(Config::green);

		game.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}