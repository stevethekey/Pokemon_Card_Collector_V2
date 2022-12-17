#include <headers/game.h>

Game::Game(const char* title, int x, int y, int width, int height, Uint32 flags)
{
    screenWidth = width;
    screenLength = height;
    G_State = PLAY;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, x, y, width, height, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
};
Game::~Game(){};

void Game::Run()
{
    

    gameLoop();

    

}

void Game::render(SDL_Texture*text)
{
    SDL_Rect hitBox;
    hitBox.x = 0;
    hitBox.y = 0;
    hitBox.w = 128;
    hitBox.h = 128;

    SDL_Rect dist;
    dist.x = 0;
    dist.y = 0;
    dist.w = 128;
    dist.h = 128;


    SDL_RenderCopy(renderer, text, &hitBox, &dist);
}


void Game::gameLoop()
{
    SDL_Texture* myImage = loadTexture("res/images/bulbasaur.png");
    

    while(G_State != EXIT)
    {
        handleEvents();

        render(myImage);
        display();
        clear();
    }
        
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
        G_State = EXIT;
            break;
    }
}

SDL_Texture* Game::loadTexture(const char* filePath)
{
    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(renderer, filePath);

    if(tex == NULL)
    {
        std::cout << "img couldn't load from " << filePath << ".\nError: " << SDL_GetError() << std:: endl;
    }
    return tex;
}

void Game::display()
{
    SDL_RenderPresent(renderer);
}

void Game::clear()
{
    SDL_RenderClear(renderer);
}

void Game::cleanUp()
{
    SDL_DestroyWindow(window);
}