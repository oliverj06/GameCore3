#pragma once
#include <SDL3/SDL.h>
class Time
{
private:
	static uint64_t prevTime;

public:

	static float deltaTime;
	static float deltaTimeMS;


	static void Update();
};

