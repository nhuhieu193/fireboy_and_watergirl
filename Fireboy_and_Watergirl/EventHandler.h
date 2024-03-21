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
};

#endif // __EVENTHANDLER__
