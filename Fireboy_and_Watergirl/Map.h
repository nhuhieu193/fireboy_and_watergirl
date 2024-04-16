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

const int SlideTime = 1600;
const int ButtonTime = 128;

struct Slide {
    string SlideName;
    int x,y;
    int Direction;
    double VelocitySlide;
    double VelocityButton;
    int FramesSlide , FramesButton;
    int numButtons;
    vector <int> currentFramesButton;
    vector <pair<int,int> > ButtonList;
    bool CollideWithButtonList(double X , double Y , double U , double V) {
        bool SlideCheck = false;
        for (int i = 0 ; i < numButtons ; i++) {
            if (CollideWithButton(ButtonList[i] , X , Y) || CollideWithButton(ButtonList[i] , U , V)) {
                currentFramesButton[i]++;
                if (currentFramesButton[i] > FramesButton) currentFramesButton[i] = FramesButton;
                SlideCheck = true;
            }else {
                currentFramesButton[i]--;
                if (currentFramesButton[i] < 0) currentFramesButton[i] = 0;
            }
        }
        return SlideCheck;
    }
    bool CollideWithButton(pair <int,int> e , double X , double Y) {
        if (e.first + 5 > X + __CHARACTER_WIDTH || e.first + 24 < X) return false;
        if (e.second + 2 > Y + __CHARACTER_HEIGHT || e.second + 10 < Y) return false;
        return true;
    }
    bool CollideWithCharacter(int CurrentFrame , double X , double Y) {
        if (1.0 * x + VelocitySlide * CurrentFrame > X + __CHARACTER_WIDTH || 1.0 * x + VelocitySlide * CurrentFrame + 90 < X) return false;
        if (y >= Y + __CHARACTER_HEIGHT || y + 15 <= Y) return false;
        return true;
    }
};

class Map {
    int LiquidAnimationSpeed = 128;
    int numFrames = 5;
    vector <int> currentSlideFrames;
    vector <int> updateRow , updateCol;
    void SaveRawMap();
    int PreDown[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int PreUp[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int PreRight[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int PreLeft[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    void TurnBackRawMap();
    void UpdateCurrentSlideMap(int x , int y);
    void UpdateEntireMap();
public:
    int Down[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Up[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Right[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    int Left[__SCREEN_WIDTH][__SCREEN_HEIGHT];
    vector <pair<int,int> > BrickList;
    vector <pair<int,int> > LavaList;
    vector <pair<int,int> > WaterList;
    vector <pair<int,int> > GreenGooList;
    vector <Slide> SlideList;

    void InputBrick(string src);
    void InputLava(string src);
    void InputWater(string src);
    void InputGreenGoo(string src);
    void InputSlide(string src);

    Map(string src);
    ~Map(){}
    void Draw();
    void Update(double X , double Y , double U , double V);
    bool OnGround(const Vector2D& vect);

    bool CollideWithLava(double x , double y , int width , int height);
    bool CollideWithWater(double x , double y , int width , int height);
    bool CollideWithGreenGoo(double x , double y , int width , int height);

};

#endif // __MAP__
