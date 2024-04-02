#ifndef __EVENTHANDLER__
#define __EVENTHANDLER__

#include <SDL.h>

class EventHandler {
    const Uint8* m_KeyboardState;
    static EventHandler* s_Instance;

    void Keydown();
    void Keyup();

public:
    EventHandler();
    static EventHandler* GetInstance() {
        return (s_Instance != NULL ? s_Instance : new EventHandler());
    }

    void Listen();
    bool Left() {
        return m_KeyboardState[SDL_SCANCODE_LEFT];
    }
    bool Up() {
        return m_KeyboardState[SDL_SCANCODE_UP];
    }
    bool Right() {
        return m_KeyboardState[SDL_SCANCODE_RIGHT];
    }

    bool KeyA() {
        return m_KeyboardState[SDL_SCANCODE_A];
    }
    bool KeyW() {
        return m_KeyboardState[SDL_SCANCODE_W];
    }
    bool KeyD() {
        return m_KeyboardState[SDL_SCANCODE_D];
    }
};

#endif // __EVENTHANDLER__
