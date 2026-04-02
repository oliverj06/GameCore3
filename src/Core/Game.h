#pragma once
#include <SDL3/SDL.h>
#include "Renderer.h"
#include "Window.h"
#include "Time.h"
#include <iostream>
class Game
{
private:

	Window window;
	Renderer renderer;
	bool shouldQuit = false;
	const bool* keys = SDL_GetKeyboardState(NULL);

	void Quit();

public:

	bool Init();
	void Run();
	inline void QuitGame() { this->shouldQuit = true; }

	inline const bool* GetKeys() const
	{
		return this->keys;
	}

	virtual bool OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnQuit();

	inline Renderer GetRenderer() { return this->renderer; }
	inline Window GetWindow() { return this->window; }
};

