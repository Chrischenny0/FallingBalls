#include "Ball.h"
using namespace std;

int main(int argc, char ** argv) {
    SDLWrapper g(1600,1030,false);

    BMPImage background("images/sorbet3.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(100, 100, 70, "images/Ball.bmp", g);

    while (!g.getQuit()){

        ball.drawBall();
        ball.moveBall();
        ball.applyForce(Gravity);

        if(g.kbhit()){
            g.getKey();

        }

        g.update();
    }
    return 0;
}
