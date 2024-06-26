#ifndef __TRANSFORM__
#define __TRANSFORM__

#include "Vector2D.h"
#include <iostream>
#include "Map.h"
#include "Engine.h"
#include "RigidBody.h"

#define maximize(x,y) x = (x < y ? y : x)
#define minimize(x,y) x = (x > y ? y : x)

class Transform {
public:
    bool MoveInMap(Vector2D vect) {
        MoveHorizontal(vect);
        return MoveVertical(vect);
    }

    void MoveHorizontal(Vector2D vect) {
        int x = X , y = Y;
        int LEFT = Engine::GetInstance() -> CurrentMap -> Left[x][y];
        int RIGHT = Engine::GetInstance() -> CurrentMap -> Right[x][y];
        for (int j = y ; j < y + CHARACTER_HEIGHT ; j++) {
            maximize(LEFT , Engine::GetInstance() -> CurrentMap -> Left[x][j]);
            minimize(RIGHT , Engine::GetInstance() -> CurrentMap -> Right[x][j]);
        }
        X += vect.X;
        maximize(X , LEFT);
        minimize(X , RIGHT - CHARACTER_WIDTH);
    }

    bool MoveVertical(Vector2D vect) {
        int x = X , y = Y;
        int UP = Engine::GetInstance() -> CurrentMap -> Up[x][y];
        int DOWN = Engine::GetInstance() -> CurrentMap -> Down[x][y];
        for (int i = x ; i < x + CHARACTER_WIDTH ; i++) {
            maximize(UP , Engine::GetInstance() -> CurrentMap -> Up[i][y]);
            minimize(DOWN , Engine::GetInstance() -> CurrentMap -> Down[i][y]);
        }
        Y += vect.Y;
        bool Collide = false;
        if (Y < UP || Y > DOWN - CHARACTER_HEIGHT) Collide = true;
        maximize(Y , UP);
        minimize(Y , DOWN - CHARACTER_HEIGHT);

        return Collide;
    }

    double X,Y;
    Transform(double x = 0 , double y = 0) : X(x) , Y(y) {}

};

#endif // __TRANSFORM__
