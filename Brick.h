/*
 * Increment brick every two balls
 */

#ifndef FALLINGBALLS_BRICK_H
#define FALLINGBALLS_BRICK_H

#include <cmath>
#include "Coordinate.h"
#include "BMPImage.h"
using namespace std;

class Brick{
private:
    int l, w;
    Coordinate center, previousCord;

    BMPImage mask;
    SDLWrapper &g;

public:
    Brick(int x, int y, const string &image, SDLWrapper &g);

    void drawBrick();

    void moveBrick();

    void outOfBounds();


};

#endif //FALLINGBALLS_BRICK_H
