#ifndef __IOBJECT__
#define __IOBJECT__

class IObject {
public:
    virtual void Draw() = 0;
    virtual void Update(double dt) = 0;
    virtual void Clean() = 0;
};

#endif // __IOBJECT__
