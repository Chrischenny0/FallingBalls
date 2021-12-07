#ifndef FALLINGBALLS_BRICK_H
#define FALLINGBALLS_BRICK_H

#include "Coordinate.h"
#include "Force.h"
#include "BMPImage.h"

class Brick{
private:
    int l, w;

    Coordinate lowerLeft, upperRight, center;

    BMPImage *mask;
    SDLWrapper &g;

public:
    Brick(int x, int y, BMPImage&, SDLWrapper &g);

    int getLength();

    Coordinate& getCenter();

    const Coordinate &getLowerLeft() const;

    const Coordinate &getUpperRight() const;

    void drawBrick();

    void moveBrick();

    void outOfBounds();

    bool collisionBrick(Coordinate &) const;



};

#endif //FALLINGBALLS_BRICK_H
