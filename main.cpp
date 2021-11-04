#include "Ball.h"
using namespace std;

int main(int argc, char ** argv) {
    SDLWrapper g(700,700,false);

    BMPImage overlay("images/sorbet3.bmp", 0, 0, g);
    BMPImage test("images/transparent.bmp", 40, 40, g);

    Ball newBall(40, 40, 200, "images/transparent.bmp", g);

    overlay.setBackground();
    while (!g.getQuit()){
        for(int i = 0; i < 100; i++){

            test.redrawBkG();
            test.draw(g, i, 40);
            newBall.drawBall();

            if(g.kbhit()){
                g.getKey();
            }

            g.update();
        }
    }
    return 0;
}
