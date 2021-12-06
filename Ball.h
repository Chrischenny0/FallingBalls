#ifndef FALLINGBALLS_BALL_H
#define FALLINGBALLS_BALL_H

#include "BMPImage.h"
#include "Force.h"
#include "Brick.h"

class Ball {
private:
    int r;
    bool solidColor;

    Force vector;
    Coordinate center, previousCord;
    BMPImage &mask;
    SDLWrapper &g;

public:
    Coordinate getCoords();

    Ball(int x, int y, BMPImage &, SDLWrapper &g);

    void drawBall();

    void moveBall();

    void applyForce(const Force &f);

    void outOfBounds();

    void collisionCheck(Ball &ballCheck);

    void collisionCheck(Brick &b2);

    void stepBack(Ball &ballCheck);
};

#endif //FALLINGBALLS_BALL_H
