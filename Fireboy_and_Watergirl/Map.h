#ifndef __MAP__
#define __MAP__

#include <vector>
#include <string>
#include "Vector2D.h"

using namespace std;

const int __SCREEN_WIDTH = 900;
const int __SCREEN_HEIGHT = 600;
const int __OBJECT_SIZE = 30;
const int __CHARACTER_WIDTH = 40;
const int __CHARACTER_HEIGHT = 61;


class Map {
    int LiquidAnimationSpeed = 128;
    int numFrames = 5;
public:
    int Down[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Up[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Right[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Left[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    vector <pair<int,int> > BrickList;
    vector <pair<int,int> > LavaList;
    vector <pair<int,int> > WaterList;
    vector <pair<int,int> > GreenGooList;

    void InputBrick(string src);
    void InputLava(string src);
    void InputWater(string src);
    void InputGreenGoo(string src);


    Map(string src);
    void Draw();
    bool OnGround(const Vector2D& vect);

    bool CollideWithLava(double x , double y , int width , int height);
    bool CollideWithWater(double x , double y , int width , int height);
    bool CollideWithGreenGoo(double x , double y , int width , int height);
};

#endif // __MAP__
