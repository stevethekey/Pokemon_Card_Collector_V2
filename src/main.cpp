#include<headers/game.h>

int main(int argc, char* argv[])
{
    Game Pokemon_Game = Game("Collect them all!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 600, SDL_WINDOW_SHOWN);
    Pokemon_Game.run();


    
    return 0;
}