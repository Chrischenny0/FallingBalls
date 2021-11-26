#ifndef FALLINGBALLS_BALL_H
#define FALLINGBALLS_BALL_H

#include "BMPImage.h"
#include "Force.h"

class Ball{
    private:
        int r;
        bool solidColor;

        Force vector;
        Coordinate center, previousCord;
        BMPImage mask;
        SDLWrapper &g;

    public:
        Ball (int x, int y, const string& image, SDLWrapper &g);
        void drawBall();
        void moveBall();
        void applyForce(const Force &f);
};
#endif //FALLINGBALLS_BALL_H
