#pragma once
#include <raylib.h>
#include <deque>

class Food
{
private:

	Vector2 m_position;
	Texture2D m_FoodTexture;
	

	Vector2 GenerateRandomCell();


public:

	void GenerateRandomPosition(std::deque<Vector2>& snakeBody);
	Food();
	Food(const Texture2D& snakeTexture, std::deque<Vector2>& snakeBody);
	void Draw();
	Vector2 GetPosition() const;
	void SetPosition(int x, int y);



};