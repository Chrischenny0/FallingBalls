#ifndef FALLINGBALLS_BALL_H
#define FALLINGBALLS_BALL_H

#include "BMPImage.h"

class Ball{
    private:

        int radius;
        bool solidColor;
        unsigned char Color;

        Coordinate center;
        BMPImage mask;
        SDLWrapper &g;

    public:
        Ball(int x, int y, int r, const string& image, SDLWrapper &g);
        void drawBall();
};
#endif //FALLINGBALLS_BALL_H
