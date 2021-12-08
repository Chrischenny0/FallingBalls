#ifndef FALLINGBALLS_BRICK_H
#define FALLINGBALLS_BRICK_H

#include "Coordinate.h"
#include "Force.h"
#include "BMPImage.h"
#include "Font.h"

class Brick{
private:
    int l, w, hp = 3;

    Coordinate lowerLeft, upperRight, center;

    BMPImage *mask;
    SDLWrapper &g;

    Font *hpFont;

public:
    Brick(int x, int y, BMPImage *mask, SDLWrapper &g, Font *hpFont, int hp);

    Coordinate& getCenter();

    const Coordinate &getLowerLeft() const;

    const Coordinate &getUpperRight() const;

    void drawBrick();

    void redrawBackground() const;

    void redrawBackground(const Coordinate &coord) const;

    void moveBrick();

    void decrementColCount();

    int getColCount();



    bool collisionBrick(Coordinate &);

};

#endif //FALLINGBALLS_BRICK_H
