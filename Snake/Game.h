#pragma once

#include <raylib.h>
#include "Snake.h"
#include "Food.h"


class Game
{
private:

	
	int score;
	int highScore;
	bool running;
	Snake m_snake;
	Food m_food;
	Sound eatSound;
	Sound wallSound;
	Texture2D foodTexture;
	void CheckCollision();
	void CheckCollisionTail();
	void GameOver();
	Game(Snake& snake, Food& food);



public:

	static Game CreateGame();
	bool eventTriggered(double interval);
	~Game();
	void Update();
	void Draw();
	void CheckMove();
	int GetScore() const;
	int GetHighScore()const;
	void LoadHighScore();
	void SaveHighScore();
};