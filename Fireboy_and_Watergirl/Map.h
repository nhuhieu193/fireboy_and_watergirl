#ifndef __MAP__
#define __MAP__

#include "Engine.h"
#include <vector>
#include <string>

using namespace std;

class Map {
    int Down[SCREEN_WIDTH][SCREEN_HEIGHT];
    int Up[SCREEN_WIDTH][SCREEN_HEIGHT];
    int Right[SCREEN_WIDTH][SCREEN_HEIGHT];
    int Left[SCREEN_WIDTH][SCREEN_HEIGHT];
    vector <pair<int,int> > WallList;

public:
    Map(string src);
    void Draw();
};

#endif // __MAP__
