#pragma once
#include <deque>
#include <raylib.h>

class Snake
{
private:
	std::deque<Vector2> body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	Vector2 direction = { 1,0 };
	bool newSegment = false;
	std::deque<Vector2> directionQue;
	



public:

	void Draw();
	void Update();
	void Reset();
	void SetDirection(int x, int y);
	void SetNewSegment();
	void CheckMove();
	Vector2 GetDirection()const;
	Vector2 GetBody(int index) const;
	std::deque<Vector2>& GetBody();


};