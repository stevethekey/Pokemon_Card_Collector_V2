#include <headers/game.h>

Game::Game(const char* title, int x, int y, int width, int height, Uint32 flags)
{
    screenWidth = width;
    screenLength = height;
    
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)        //If the initiliazation function took off successfully
    {
        window = SDL_CreateWindow(title, x, y, width, height, flags);   //sets up a window
        renderer = SDL_CreateRenderer(window, -1, 0);                   //sets up rendering
        SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);            //allows to modify rendering's background color

        SDL_Surface* tmpSurface = IMG_Load("res/images/Gusto.png");
        Main_Model_GUSTO = SDL_CreateTextureFromSurface(renderer, tmpSurface);  //our protagnist, Gusto.
        SDL_FreeSurface(tmpSurface);

        
        destR.h = 64;
        destR.w = 64;
        destR.x = 0;
        destR.y = 0;
        G_State = PLAY;                                                 //allow game loop to run
    }
    else
        G_State = EXIT;
    
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::handleEvents() //handles user input logic (i.e., clicking)
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

void Game::update(){
    /*
    
        This function is responsible for updating game objects/entities

    */

    if(MainModel_cntr > 950)
        goRight = false;

    if(MainModel_cntr < 1)
        goRight= true;
    
    if(goRight == true)
        MainModel_cntr += 1;
    else
        MainModel_cntr-= 1;
    
    destR.x = MainModel_cntr;
    std::cout<< MainModel_cntr << std::endl;
};

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, Main_Model_GUSTO, NULL, &destR);
    SDL_RenderPresent(renderer);
};

void Game::run()
{
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    while(G_State == PLAY)
    {
        frameStart = SDL_GetTicks();

        handleEvents();             //check user input
        update();                   //update entities or insert new 
        render();                   //display new rendering entities or new positions of previous 

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
    Game::~Game();                  //explicit call to deconstructor (game's over if G_State is not set to PLAY)
}