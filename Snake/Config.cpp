#include "Config.h"
#include <raylib.h>
#include <raymath.h>

const Color Config::green = { 77, 90, 87, 255 };
const Color Config::darkgreen = { 32, 33, 28, 255 };
double Config::interval = 0.2;

bool Config::ElementInDeque(const Vector2& element, std::deque<Vector2>& deque)
{
	for (unsigned int i = 0; i < deque.size(); i++)
	{
		if (Vector2Equals(deque[i], element))
			return true;
	}
	return false;
}