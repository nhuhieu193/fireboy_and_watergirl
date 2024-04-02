#include "EventHandler.h"
#include "Engine.h"

EventHandler* EventHandler::s_Instance = NULL;

EventHandler::EventHandler() {
    m_KeyboardState = SDL_GetKeyboardState(NULL);
}

void EventHandler::Listen() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: Engine::GetInstance() -> Quit();break;
            case SDL_KEYDOWN: Keydown();break;
            case SDL_KEYUP: Keyup();break;
        }
    }
}

void EventHandler::Keydown() {
    SDL_GetKeyboardState(NULL);

}

void EventHandler::Keyup() {
    SDL_GetKeyboardState(NULL);
}
