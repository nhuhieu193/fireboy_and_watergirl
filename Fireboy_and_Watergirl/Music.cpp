#include "Music.h"

Music* Music::s_Instance = NULL;

bool Music::LoadMUS(std::string id , std::string filename) {
    Mix_Music* newMusic = Mix_LoadMUS(filename.c_str());
    m_MusicMap[id] = newMusic;
}

bool Music::LoadCHU(std::string id , std::string filename) {
    Mix_Chunk* newChunk = Mix_LoadWAV(filename.c_str());
    m_ChunkMap[id] = newChunk;
}

void Music::Update() {
    countFrame++;
    int x,y;
    int state = SDL_GetMouseState(&x , &y);
    int currentTime = SDL_GetTicks();
    if (state == 1 && x < 60 && x > 0 && y < 60 && y > 0 && countFrame - FramesClickDelay > LastFrameClickSpeaker) {
        LastFrameClickSpeaker = countFrame;
        SpeakerIsOn = 1 - SpeakerIsOn;
    }else if (state == 1 && x < 120 && x > 60 && y < 60 && y > 0 && countFrame - FramesClickDelay > LastFrameClickSound){
        LastFrameClickSound = countFrame;
        SoundIsOn = 1 - SoundIsOn;
        if (SoundIsOn) Mix_ResumeMusic();else Mix_PauseMusic();
    }
}

void Music::Draw() {
    if (SpeakerIsOn) Texture::GetInstance() -> Draw("speaker_on" , 0 , 0 , 60 , 60);else
        Texture::GetInstance() -> Draw("speaker_off" , 0 , 0 , 60 , 60);
    if (SoundIsOn) Texture::GetInstance() -> Draw("sound_on" , 60 , 0 , 60 , 60);else
        Texture::GetInstance() -> Draw("sound_off" , 60 , 0 , 60 , 60);
}

void Music::Clean() {
    for (auto e : m_MusicMap) {
        Mix_FreeMusic(e.second);
    }
    for (auto e : m_ChunkMap) {
        Mix_FreeChunk(e.second);
    }
}

void Music::PlayMusic(std::string id) {
    if (SoundIsOn == false) return;
    Mix_PlayMusic(m_MusicMap[id] , -1);
}

void Music::PlayChunk(std::string id) {
    if (SpeakerIsOn == false) return;
    Mix_PlayChannel(-1 , m_ChunkMap[id] , 0);
}

