#include "Renderer.h"

bool Renderer::Init(SDL_Window* window, int logicalWidth, int logicalHeight, SDL_RendererLogicalPresentation flags)
{
	this->renderer = SDL_CreateRenderer(window, NULL);
	if (!this->renderer) { return false; }

	SDL_SetRenderLogicalPresentation(this->renderer, logicalWidth, logicalHeight, flags);

	return true;
}

SDL_Renderer* Renderer::GetRenderer() const
{
	return this->renderer;
}

void Renderer::DestroyRenderer()
{
	SDL_DestroyRenderer(this->renderer);
}

//Set the window background color
void Renderer::SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

//Render a existing texture
void Renderer::RenderTexture(SDL_Texture* texture, SDL_FRect* srcRect, SDL_FRect* dstRect)
{
	SDL_RenderTexture(this->renderer, texture, srcRect, dstRect);
}

//Render background color and clear the old buffer to prepare it for drawing
void Renderer::RenderClear()
{
	SDL_RenderClear(this->renderer);
}

//Swap buffers and show whats on the buffer
void Renderer::RenderPresent()
{
	SDL_RenderPresent(this->renderer);
}

//Set 1 for every first vertical refresh and 2 for every second vertical refresh
void Renderer::SetVSync(int vsync)
{
	SDL_SetRenderVSync(this->renderer, 1);
}
