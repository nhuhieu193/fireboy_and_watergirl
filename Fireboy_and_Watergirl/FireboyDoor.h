#ifndef __FIREBOYDOOR__
#define __FIREBOYDOOR__

#include "texture.h"

class FireboyDoor {
    int DoorWidth , DoorHeight;
    int x,y;
    int numFrames;
    int CountTicks , animationSpeed;
public:
    FireboyDoor(int _x , int _y) {
        x = _x;
        y = _y;
        DoorWidth = 74;
        DoorHeight = 80;
        numFrames = 13;
        CountTicks = 0;
        animationSpeed = 5;
    }
    bool Collide(double _x , double _y , double _u , double _v) {
        if (_x > x + DoorWidth || _u < x) return false;
        if (_y > y + DoorHeight || _v < y) return false;
        return true;
    }
    void Update(double _x , double _y , int _width , int _height) {
        if (Collide(_x , _y , _x + _width , _y + _height)) CountTicks++;else CountTicks--;
        if (CountTicks < 0) CountTicks = 0;
        if (CountTicks >= animationSpeed * 13) CountTicks = animationSpeed * 13 - 1;
    }
    void Render() {
        Texture::GetInstance() -> DrawDoor("door" , x , y , DoorWidth , DoorHeight , 0 , CountTicks / animationSpeed);
    }
    inline bool GameCompleted() {
        return CountTicks == animationSpeed * 13 - 1;
    }
};

#endif // __FIREBOYDOOR__
