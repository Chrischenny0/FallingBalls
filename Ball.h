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
    BMPImage *mask;
    SDLWrapper &g;

    Coordinate &lowerBound, &upperBound;

public:
    Coordinate getCoords();

    Ball(Coordinate center, BMPImage *image, SDLWrapper &g, Coordinate &lowerBound, Coordinate &upperBound);

    void setMagDir(Force);

    void resetCenter(){
        center.x = 390;
        center.y = -10;
    }

    void drawBall();

    void moveBall();

    void moveBall(double mag, double dir);

    void applyForce(const Force &f);

    void outOfBounds();

    void collisionCheck(Ball &ballCheck);

    bool collisionCheck(Brick &b2);

    void stepBack(Ball &ballCheck);
};

#endif //FALLINGBALLS_BALL_H
