#include "Food.h"
#include "Config.h"
#include <raymath.h>


Food::Food(const Texture2D& snakeTexture, std::deque<Vector2>& snakeBody)
{
	m_FoodTexture = snakeTexture;
	GenerateRandomPosition(snakeBody);
}

void Food::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void Food::GenerateRandomPosition(std::deque<Vector2>& snakeBody)
{
	Vector2 position;

	do
	{
		position = GenerateRandomCell();
	} while (Config::ElementInDeque(position, snakeBody));


	SetPosition(position.x, position.y);
}




void Food::Draw()
{
	DrawTexture(m_FoodTexture, Config::offset + m_position.x * Config::cellSize, Config::offset + m_position.y * Config::cellSize, WHITE);
}

Vector2 Food::GetPosition() const
{
	return this->m_position;
}

Vector2 Food::GenerateRandomCell()
{
	float x = GetRandomValue(0, Config::cellCount - 1);
	float y = GetRandomValue(0, Config::cellCount - 1);

	return Vector2{ x,y };
}

