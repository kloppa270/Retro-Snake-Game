#include "Snake.h"
#include "Config.h"
#include <raymath.h>

void Snake::Draw()
{
	for (const Vector2& b : body)
	{
		int x = b.x;
		int y = b.y;
		Rectangle segment = Rectangle{ Config::offset + (float)x * Config::cellSize, Config::offset + (float)y * Config::cellSize, (float)Config::cellSize, (float)Config::cellSize };
		DrawRectangleRounded(segment, 0.5, 6, Config::darkgreen);
	}
}

void Snake::Update()
{
	if (!directionQue.empty())
	{
		Vector2 nextDirection = directionQue.front();
		if (!Vector2Equals(nextDirection, Vector2Negate(direction)))
		{
			direction = nextDirection;
		}
		directionQue.pop_front();
	}

	Vector2 newHead = Vector2Add(body[0], direction);

	if (newHead.x >= Config::cellCount)
		newHead.x = 0;
	else if (newHead.x < 0)
		newHead.x = Config::cellCount - 1;

	if (newHead.y >= Config::cellCount)
		newHead.y = 0;
	else if (newHead.y < 0)
		newHead.y = Config::cellCount - 1;

	if (newSegment)
	{
		body.emplace_front(newHead);
		newSegment = false;
	}
	else
	{
		body.pop_back();
		body.emplace_front(newHead);
	}
}


void Snake::Reset()
{
	body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	direction = { 1,0 };
}

void Snake::SetDirection(int x, int y)
{
	direction.x = x;
	direction.y = y;
}

void Snake::SetNewSegment()
{
	newSegment = true;
}

void Snake::CheckMove()
{
	if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && this->GetDirection().y != 1)
		directionQue.emplace_front(Vector2{ 0, -1 });
	else if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && this->GetDirection().y != -1)
		directionQue.emplace_front(Vector2{ 0, 1 });
	else if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && this->GetDirection().x != 1)
		directionQue.emplace_front(Vector2{ -1, 0 });
	else if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && this->GetDirection().x != -1)
		directionQue.emplace_front(Vector2{ 1, 0 });
}

Vector2 Snake::GetDirection() const
{
	return direction;
}

Vector2 Snake::GetBody(int index) const
{
	return body[index];
}

std::deque<Vector2>& Snake::GetBody()
{
	return body;
}