#pragma once
#include <raylib.h>
#include <deque>

struct Config
{
	static const int cellSize = 30;
	static const int offset = 75;
	static const int cellCount = 25;
	static double interval;
	static const Color green;
	static const Color darkgreen;

	static bool ElementInDeque(const Vector2& element, std::deque<Vector2>& deque);



};

