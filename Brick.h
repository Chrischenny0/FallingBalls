/*
 * Increment brick every two balls
 */

#ifndef FALLINGBALLS_BRICK_H
#define FALLINGBALLS_BRICK_H

#include "Coordinate.h"
#include "Force.h"
#include "BMPImage.h"

class Brick{
private:
    int l, w;

    Force vector;
    Coordinate center;

    BMPImage &mask;
    SDLWrapper &g;

public:
    Brick(int x, int y, BMPImage&, SDLWrapper &g);

    int getLength();

    Coordinate& getCenter();

    void drawBrick();

    void moveBrick();

    void outOfBounds();

    bool collisionBrick(Coordinate &);

};

#endif //FALLINGBALLS_BRICK_H
