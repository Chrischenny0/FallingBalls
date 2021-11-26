#include "Ball.h"
using namespace std;

int main(int argc, char ** argv) {
    SDLWrapper g(1600,1030,false);

    BMPImage background("images/Background1600.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(300, 300, "images/Ball.bmp", g);

    while (!g.getQuit()){

        ball.drawBall();
        ball.applyForce(Gravity);
        ball.moveBall();

        if(g.kbhit()){
            g.getKey();
        }

        g.update();
    }
    return 0;
}
