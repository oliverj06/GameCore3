#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Renderer.h"

class GameObject
{
private:
	SDL_Texture* texture = nullptr;

	float xPosition = 0.f;
	float yPosition = 0.f;
	float width = 0.f;
	float height = 0.f;

	float imageWidth = 0.f;
	float imageHeight = 0.f;
	float imagePivotX = 0.f;
	float imagePivotY = 0.f;

	SDL_FRect dst{ .x = 0, .y = 0, .w = 0, .h = 0 };
	SDL_FRect src{ .x = 0, .y = 0, .w = 0, .h = 0 };


	inline void UpdateDst() 
	{
		this->dst.x = this->xPosition;
		this->dst.y = this->yPosition;
		this->dst.w = this->width;
		this->dst.h = this->height;
	}
	inline void UpdateSrc()
	{
		this->src.x = this->imagePivotX;
		this->src.y = this->imagePivotY;
		this->src.w = this->imageWidth;
		this->src.h = this->imageHeight;
	}

	inline void DestroyObject()
	{
		if (this->texture)
		{
			SDL_DestroyTexture(this->texture);
		}
	}

public:

	GameObject();
	~GameObject();

	void Render(Renderer renderer);
	void LoadTexture(Renderer renderer, const char* path);
	inline SDL_FRect GetSRCRect() const { return this->src; }
	inline SDL_FRect GetDstRect() const { return this->dst; }

	inline void SetPosition(float x, float y) 
	{
		this->xPosition = x;
		this->yPosition = y;
		this->UpdateDst();

	}

	inline void AddPosition(float x, float y)
	{
		this->xPosition += x;
		this->yPosition += y;
		this->UpdateDst();
	}

	inline void SetSize(float width, float height) 
	{
		this->width = width;
		this->height = height;
		this->UpdateDst();
	}

	inline void AddSize(float width, float height)
	{
		this->width = width;
		this->height = height;
		this->UpdateDst();
	}
	
	inline void SetImagePivot(float x, float y)
	{
		this->imagePivotX = x;
		this->imagePivotY = y;
		this->UpdateSrc();
	}

	inline void SetImageSize(float width, float height)
	{
		this->imageWidth = width;
		this->imageHeight = height;
		this->UpdateSrc();
	}

	inline void SetTextureScaleMode(SDL_ScaleMode mode)
	{
		SDL_SetTextureScaleMode(this->texture, mode);
	}
};

