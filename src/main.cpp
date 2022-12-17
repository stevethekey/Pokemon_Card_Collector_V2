#include<headers/game.h>

int main(int argc, char* argv[])
{
    Game game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 600, SDL_WINDOW_SHOWN);

    game.Run();
    return 0;
}