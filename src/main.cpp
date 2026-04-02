#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "Core/Game.h"
#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Core/Time.h"
#include "Core/GameObject.h"


class MyGame : public Game
{
private:

	GameObject* player = new GameObject();
	int playerXInput = 0;
	int playerYInput = 0;
	float playerMoveSpeed = 1.f;

public:

	bool OnInit() override
	{
		std::cout << "User init" << '\n';

		this->player->SetPosition(200, 200);	//Position of the object in the world
		this->player->SetImageSize(32, 32);	//Size of the image
		this->player->SetSize(50, 50);		//Size of the object in the world
		//this->player.SetImagePivot(0, 0);   Already 0, 0 to begin 
		this->player->LoadTexture(GetRenderer(), "assets/playerTexture.png");
		this->player->SetTextureScaleMode(SDL_SCALEMODE_NEAREST);

		return true;
	}

	void OnUpdate() override
	{
		//Update stuff
		this->playerXInput = GetKeys()[SDL_SCANCODE_RIGHT] - GetKeys()[SDL_SCANCODE_LEFT];
		this->playerYInput = GetKeys()[SDL_SCANCODE_DOWN] - GetKeys()[SDL_SCANCODE_UP];

		this->player->AddPosition(this->playerXInput * this->playerMoveSpeed * Time::deltaTime,
			this->playerYInput * this->playerMoveSpeed * Time::deltaTime);
	}

	void OnRender() override
	{
		//Render stuff
		this->player->Render(GetRenderer());
	}

	void OnQuit() override
	{
		//Destroy stuff
		std::cout << "User Quit" << '\n';
	}
};

int main(int argc, char* argv[])
{

	MyGame game;
	if (!game.Init())
		return -1;

	game.Run();


	return 0;
}