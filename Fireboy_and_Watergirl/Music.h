#ifndef __MUSIC__
#define __MUSIC__

#include <map>
#include <string>
#include <SDL_mixer.h>
#include "texture.h"

const int FramesClickDelay = 15;

class Music {
    static Music* s_Instance;
    std::map <std::string , Mix_Music*> m_MusicMap;
    std::map <std::string , Mix_Chunk*> m_ChunkMap;

    bool SpeakerIsOn = true, SoundIsOn = true;
    int LastFrameClickSpeaker = -10, LastFrameClickSound = -10;
    int countFrame = 0;

public:
    static Music* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new Music());
    }
    bool LoadMUS(std::string id , std::string filename);
    bool LoadCHU(std::string id , std::string filename);
    void Clean();
    void PlayMusic(std::string id);
    void PlayChunk(std::string id);

    void Update();
    void Draw();
};

#endif // __MUSIC__
