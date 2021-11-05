#include "Ball.h"
using namespace std;

int main(int argc, char ** argv) {
    SDLWrapper g(700,700,false);

    BMPImage background("images/sorbet3.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(100, 100, 70, "images/Ball.bmp", g);

    while (!g.getQuit()){
        for(int i = 0; i < 100; i++){

            ball.drawBall();
            ball.moveBall(100+i, 100);

            if(g.kbhit()){
                g.getKey();

            }

            g.update();
        }
    }
    return 0;
}
