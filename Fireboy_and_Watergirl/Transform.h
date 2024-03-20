#ifndef __TRANSFORM__
#define __TRANSFORM__

#include "Vector2D.h"

class Transform {
public:
    inline void TranslateX(double x) {X += x;}
    inline void TranslateY(double y) {Y += y;}
    inline void Translate(Vector2D v) {X += v.X; Y += v.Y;}

    double X,Y;
    Transform(double x = 0 , double y = 0) : X(x) , Y(y) {}

};

#endif // __TRANSFORM__
