#ifndef FALLINGBALLS_BALL_H
#define FALLINGBALLS_BALL_H

#include "BMPImage.h"

class Ball{
    private:
        int radius;
        bool solidColor;

        Coordinate center, previousCord;
        BMPImage mask;
        SDLWrapper &g;

    public:
        Ball (int x, int y, int r, const string& image, SDLWrapper &g);
        void drawBall();
        void moveBall(int newX, int newY);
};
#endif //FALLINGBALLS_BALL_H
