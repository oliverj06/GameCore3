#include "Window.h"

bool Window::Init(const char* title, int width, int height, SDL_WindowFlags flags)
{
	this->window = SDL_CreateWindow(title, width, height, flags);
	if (!this->window) { return false; }
	return true;
}

void Window::UpdateSize(int newWidth, int newHeight)
{
	this->windowWidth = newWidth;
	this->windowHeight = newHeight;
}

SDL_Window* Window::GetWindow() const
{
	return this->window;
}

void Window::DestroyWindow()
{
	SDL_DestroyWindow(this->window);
}
