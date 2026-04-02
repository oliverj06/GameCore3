#include "Game.h"

bool Game::Init()
{
    std::cout << "Initializing" << '\n';
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO))
    {
        SDL_Log("Failed to init SDL: %s", SDL_GetError());
        return false;
    }

    if (!this->window.Init("Bullet Hell Boss", 600, 400, SDL_WINDOW_RESIZABLE))
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    if (!this->renderer.Init(window.GetWindow(), 600, 400, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE))
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }
    this->renderer.SetVSync(1); //Enable VSync


    if (!this->OnInit())
    {
        SDL_Log("User update failed: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::Run()
{
    std::cout << "Updating" << '\n';
    Time::Update();

    SDL_Event event;
    while (!shouldQuit)
    {

#pragma region Poll Events
        //Handle window events
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            shouldQuit = true;
            break;

        case SDL_EVENT_WINDOW_RESIZED:
            this->window.UpdateSize(event.window.data1, event.window.data2);
            break;

        default:
            break;
        }

#pragma endregion

        this->OnUpdate();

        this->renderer.SetBackgroundColor(0, 0, 0, 255);
        this->renderer.RenderClear();

        this->OnRender();

        this->renderer.RenderPresent();
    }

    this->Quit();
}

bool Game::OnInit() { return true; }
void Game::OnUpdate(){}
void Game::OnRender(){}
void Game::OnQuit(){}



void Game::Quit()
{
    this->OnQuit();
    SDL_Log("Quitting");
    this->renderer.DestroyRenderer();
    this->window.DestroyWindow();
    SDL_Quit();
}
