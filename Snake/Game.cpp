#include "Game.h"
#include "Config.h"
#include <fstream>
#include <raymath.h>

void Game::CheckCollision()
{
	if (Vector2Equals(m_snake.GetBody(0), m_food.GetPosition()))
	{
		m_food.GenerateRandomPosition(m_snake.GetBody());
		m_snake.SetNewSegment();
		score += 2;
		PlaySound(eatSound);

		Config::interval -= 0.01;
		if (Config::interval < 0.05)
			Config::interval = 0.05;
	}
}



void Game::SaveHighScore()
{
	std::ofstream file("highscore.txt");
	if (file.is_open())
	{
		file << highScore;
		file.close();
	}
}

void Game::LoadHighScore()
{
	std::ifstream file("highscore.txt");
	if (file.is_open())
	{
		file >> highScore;
		file.close();
	}
}



void Game::CheckCollisionTail()
{
	std::deque<Vector2> headlesBody = m_snake.GetBody();
	headlesBody.pop_front();
	if (Config::ElementInDeque(m_snake.GetBody(0), headlesBody))
	{
		GameOver();
	}
}

void Game::GameOver()
{
	m_snake.Reset();
	m_food.GenerateRandomPosition(m_snake.GetBody());
	running = false;
	if (score > highScore)
	{
		highScore = score;
		SaveHighScore();
	}
	score = 0;
	Config::interval = 0.2;
	PlaySound(wallSound);
}

Game::Game(Snake& snake, Food& food)
	: m_snake(snake), m_food(food), score(0), highScore(0), running(true)
{
	InitAudioDevice();
	eatSound = LoadSound("Assets/Sounds/eat.mp3");
	wallSound = LoadSound("Assets/Sounds/wall.mp3");
	LoadHighScore();
}



Game::~Game()
{
	UnloadTexture(foodTexture);
	UnloadSound(eatSound);
	UnloadSound(wallSound);
	CloseAudioDevice();
}

void Game::Update()
{
	if (running)
	{
		m_snake.Update();
		CheckCollision();
		CheckCollisionTail();
	}
}

void Game::Draw()
{
	m_food.Draw();
	m_snake.Draw();
	DrawRectangleLinesEx(Rectangle{ (float)Config::offset - 5, (float)Config::offset - 5, (float)Config::cellSize * Config::cellCount + 10, (float)Config::cellSize * Config::cellCount + 10 }, 5, Config::darkgreen);
	DrawText("Retro Snake", 75, 30, 30, Config::darkgreen);
	DrawText(TextFormat("Score: %i", this->GetScore()), 345, 30, 30, Config::darkgreen);
	DrawText(TextFormat("HighScore: %i", this->GetHighScore()), 545, 30, 30, Config::darkgreen);
}

void Game::CheckMove()
{
	m_snake.CheckMove();
	if (IsKeyPressed(KEY_SPACE))
		running = true;
}




bool Game::eventTriggered(double interval)
{
	static double lastUpdateTime = 0;
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}

	return false;
}

int Game::GetScore() const
{
	return score;
}

int Game::GetHighScore() const
{
	return highScore;
}



Game Game::CreateGame()
{
	Snake snake;
	Texture2D foodTexture = LoadTexture("Assets/Images/food.png");
	Food food(foodTexture, snake.GetBody());
	Game game(snake, food);

	return game;
}
