#pragma once
#include <SDL3/SDL.h>
class Renderer
{
private:

	int logWidth = 600;
	int logHeight = 400;

	SDL_Renderer* renderer;

public:

	/**
	Initialize a renderer for the window. This must be called in order to render anything.
	CALL THIS AFTER WINDOW INIT!!
	*/
	bool Init(SDL_Window* window, int logicalWidth, int logicalHeight, SDL_RendererLogicalPresentation flags);

	/**
	Get the SDL_Renderer* that is used for its window.
	*/
	SDL_Renderer* GetRenderer() const;

	/**
	Destory the renderer (this does not destroy the window). CALL THIS BEFORE WINDOW DESTROY!!!
	*/
	void DestroyRenderer();

	/**
	Set the background color of the renderer. Each value is 0-255. Almost always use 255 for alpha. CALL THIS BEFORE RENDER CLEAR!
	*/
	void SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/**
	Render the given texture with the given src and dst.
	*/
	void RenderTexture(SDL_Texture* texture, SDL_FRect* srcRect, SDL_FRect* dstRect);

	/**
	Render background color and clear the old buffer to prepare it for drawing. CALL THIS BEFORE RENDER PRESENT
	*/
	void RenderClear();
	/**
	Swap buffers and show what is on the front buffer
	*/
	void RenderPresent();

	/**
	
	Enable or Disable VSync
	
	vsync = 0 to set VSync to off (render frames as fast as possible)
	vsync = 1 to sync to the displays refresh rate, looks better but takes more power
	vsync = 2 to sync to half the displays refresh rate, looks worse but takes less power
	*/
	void SetVSync(int vsync);
};

