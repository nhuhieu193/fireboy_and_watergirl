#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CHARACTER_WIDTH = 50;
const int CHARACTER_HEIGHT = 50;
const int GROUND_HEIGHT = 400;
const int JUMP_VELOCITY = -10;
const int GRAVITY = 1;

bool isOnGround(int characterY) {
    return characterY >= GROUND_HEIGHT;
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Fireboy and Watergirl Movement", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int characterX = 100;
    int characterY = GROUND_HEIGHT;
    int jumpVelocity = 0;
    bool jumping = false;

    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE && !jumping && isOnGround(characterY)) {
                    jumping = true;
                    jumpVelocity = JUMP_VELOCITY;
                }
            }
        }

        if (jumping) {
            characterY += jumpVelocity;
            jumpVelocity += GRAVITY;
            if (characterY >= GROUND_HEIGHT) {
                characterY = GROUND_HEIGHT;
                jumpVelocity = 0;
                jumping = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect characterRect = { characterX, characterY, CHARACTER_WIDTH, CHARACTER_HEIGHT };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &characterRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
