#include "Time.h"

float Time::deltaTime = 0.f;
float Time::deltaTimeMS = 0.f;
uint64_t Time::prevTime = SDL_GetTicks();

void Time::Update()
{
    uint64_t currentTime = SDL_GetTicks();
    uint64_t elapsedMS = currentTime - prevTime;

    deltaTimeMS = static_cast<float>(elapsedMS);    // milliseconds
    deltaTime = deltaTimeMS / 1000.f;               // seconds

    prevTime = currentTime;
}
