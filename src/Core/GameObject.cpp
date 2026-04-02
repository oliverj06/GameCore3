#include "GameObject.h"

GameObject::GameObject()
{
	this->UpdateDst();
	this->UpdateSrc();
}

GameObject::~GameObject()
{
	this->DestroyObject();
}

void GameObject::Render(Renderer renderer)
{
	if (this->texture)
	{
		renderer.RenderTexture(this->texture, &this->src, &this->dst);
	}
}

void GameObject::LoadTexture(Renderer renderer, const char* path)
{
	this->texture = IMG_LoadTexture(renderer.GetRenderer(), path);
}
