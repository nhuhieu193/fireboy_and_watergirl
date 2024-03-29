#ifndef __MAP__
#define __MAP__

#include <vector>
#include <string>
#include "Vector2D.h"

using namespace std;

const int __SCREEN_WIDTH = 900;
const int __SCREEN_HEIGHT = 600;
const int __OBJECT_SIZE = 30;
//const int __CHARACTER_WIDTH = 29;
//const int __CHARACTER_HEIGHT = 59;
const int __CHARACTER_WIDTH = 40;
const int __CHARACTER_HEIGHT = 61;


class Map {
public:
    int Down[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Up[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Right[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Left[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    vector <pair<int,int> > WallList;

    Map(string src);
    void Draw();
    bool OnGround(const Vector2D& vect);
};

#endif // __MAP__
