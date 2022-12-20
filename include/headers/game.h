#ifndef GUARD_HEADER
#define GUARD_HEADER

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <iostream>

enum GameState {PLAY, EXIT};

class Game
{
    public:
        Game(const char* title, int x, int y, int width, int height, Uint32 flags); //Main window
        ~Game();                                                                    //Gets rid of window, clears rendering too

        void run();                                                                 //Allows game to run

    private:
        void handleEvents();
        void update();
        void render();


        float MainModel_cntr = 0;
        int screenWidth;
        int screenLength; 
        SDL_Window* window;
        SDL_Renderer* renderer;
        GameState G_State;     

        SDL_Texture* Main_Model_GUSTO;
        SDL_Rect srcR, destR;           //MainModel's hitboxes and placement information

        bool goRight = true;
};

#endif