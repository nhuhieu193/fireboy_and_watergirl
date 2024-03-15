#ifndef __VECTOR2D__
#define __VECTOR2D__

class Vector2D {
public:
    double X,Y;

    Vector2D(double x = 0 , double y = 0) : X(x) , Y(y) {}

    inline Vector2D operator + (const Vector2D& other) const {
        return Vector2D(X + other.X , Y + other.Y);
    }

    inline Vector2D operator - (const Vector2D& other) const {
        return Vector2D(X - other.X , Y - other.Y);
    }

    inline Vector2D operator * (const double& other) const {
        return Vector2D(X * other , Y * other);
    }
};

#endif // __VECTOR2D__
