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

void Music::Clean() {
    for (auto e : m_MusicMap) {
        Mix_FreeMusic(e.second);
    }
    for (auto e : m_ChunkMap) {
        Mix_FreeChunk(e.second);
    }
}

void Music::PlayMusic(std::string id) {
    Mix_PlayMusic(m_MusicMap[id] , -1);
}

void Music::PlayChunk(std::string id) {
    Mix_PlayChannel(-1 , m_ChunkMap[id] , 0);
}

