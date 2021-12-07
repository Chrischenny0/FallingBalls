#ifndef FALLINGBALLS_BRICK_H
#define FALLINGBALLS_BRICK_H

#include "Coordinate.h"
#include "Force.h"
#include "BMPImage.h"

class Brick{
private:
    int l, w, colCount = 3;

    Coordinate lowerLeft, upperRight, center;

    BMPImage *mask;
    SDLWrapper &g;

public:
    Brick(int x, int y, BMPImage&, SDLWrapper &g);

    //~Brick();

    //Brick& operator=();

    Coordinate& getCenter();

    const Coordinate &getLowerLeft() const;

    const Coordinate &getUpperRight() const;

    void drawBrick();

    void moveBrick();

    void decrementColCount();

    int getColCount();



    bool collisionBrick(Coordinate &);

};

#endif //FALLINGBALLS_BRICK_H
