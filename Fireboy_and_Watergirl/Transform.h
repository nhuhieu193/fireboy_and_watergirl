#ifndef __TRANSFORM__
#define __TRANSFORM__

#include "Vector2D.h"
#include <iostream>

class Transform {
public:
    inline void TranslateX(double x) {if (abs(X + x) < 30) X += x;}
    inline void TranslateY(double y) {if (abs(Y + y) < 30) Y += y;}
    inline void Translate(Vector2D v) {X += v.X; Y += v.Y;}
    inline void TranslateReverse(Vector2D v) {X -= v.X; Y -= v.Y;}

    double X,Y;
    Transform(double x = 0 , double y = 0) : X(x) , Y(y) {}

};

#endif // __TRANSFORM__
