#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "Core/Game.h"
#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Core/Time.h"
#include "Core/GameObject.h"

#define EXIT_SUCCESS 0
#define EXIT_ERROR_SDL_INIT -1		//Error initializing SDL
#define EXIT_ERROR_WINDOW -2		//Error creating window
#define EXIT_ERROR_RENDERER -3		//Error creating renderer
#define EXIT_ERROR_TEXTURE -4		//Error loading texture from assets


int main(int argc, char* argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO))
	{
		SDL_Log("Failed to init SDL: %s", SDL_GetError());
		return EXIT_ERROR_SDL_INIT;
	}

	int windowHeight = 400;
	int windowWidth = 600;

	Window window;
	if (!window.Init("Bullet Hell Boss", 600, 400, SDL_WINDOW_RESIZABLE))
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return EXIT_ERROR_WINDOW;
	}

	Renderer renderer;
	if (!renderer.Init(window.GetWindow(), 600, 400, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE))
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return EXIT_ERROR_RENDERER;
	}
	renderer.SetVSync(1); //Enable VSync
	

	GameObject* player = new GameObject();
	player->SetPosition(200, 200);	//Position of the object in the world
	player->SetImageSize(32, 32);	//Size of the image
	player->SetSize(50, 50);		//Size of the object in the world
	//player.SetImagePivot(0, 0);   Already 0, 0 to begin 
	player->LoadTexture(renderer, "assets/playerTexture.png");
	player->SetTextureScaleMode(SDL_SCALEMODE_NEAREST);




	bool shouldQuit = false;		//While should quit is false the program will update

	SDL_Event event;

	int xMoveInput = 0;
	int yMoveInput = 0;
	float moveSpeed = 300.f;

	
	//Our update method

	while (!shouldQuit)
	{
		Time::Update();

#pragma region Poll Events
		//Handle window events
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			shouldQuit = true;
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			windowWidth = event.window.data1;
			windowHeight = event.window.data2;
			break;

		default:
			break;
		}

#pragma endregion


#pragma region Key Events
		const bool* keys = SDL_GetKeyboardState(NULL);

		xMoveInput = keys[SDL_SCANCODE_RIGHT] - keys[SDL_SCANCODE_LEFT];
		yMoveInput = keys[SDL_SCANCODE_DOWN] - keys[SDL_SCANCODE_UP];
#pragma endregion



#pragma region Update

		player->AddPosition(xMoveInput * moveSpeed * Time::deltaTime, yMoveInput * moveSpeed * Time::deltaTime);

#pragma endregion



		renderer.SetBackgroundColor(255, 0, 0, 255);
		renderer.RenderClear();

#pragma region Render Sprites

		player->Render(renderer);

#pragma endregion

		renderer.RenderPresent();


	}


	renderer.DestroyRenderer();
	window.DestroyWindow();
	SDL_Quit();
	return 0;
}