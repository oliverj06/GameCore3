#pragma once
#include <SDL3/SDL.h>
class Window
{
private:

	int windowWidth = 600;
	int windowHeight = 400;

	SDL_Window* window;

public:
	/**
	Initialize the window with a title, a size, and flags
	CALL BEFORE RENDERER INIT
	*/
	bool Init(const char* title, int width, int height, SDL_WindowFlags flags);
	/**
	Update the size of the window
	Sets the size to what you put it DOES NOT ADD OR SUBTRACT SIZE
	*/
	void UpdateSize(int newWidth, int newHeight);
	/**
	Returns the SDL_Window* that is created on init
	*/
	SDL_Window* GetWindow() const;
	/**
	Destroy the window that was created on init
	CALL THIS AFTER RENDERER DESTROY
	*/
	void DestroyWindow();
};

