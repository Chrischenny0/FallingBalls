#include "Ball.h"

using namespace std;

int main(int argc, char **argv) {
    SDLWrapper g(1600, 950, false);

    BMPImage background("images/Background1600.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(300, 150, "images/Ball.bmp", g);
    Ball ball2(100, 400, "images/Ball.bmp", g);
    Ball ball3(200, 150, "images/Ball.bmp", g);

    vector<Ball> balls;

    while (!g.getQuit()) {

        ball.drawBall();
        ball2.drawBall();
        ball3.drawBall();

        ball.applyForce(Gravity);
        ball2.applyForce(Gravity);
        ball3.applyForce(Gravity);

        ball.moveBall();
        ball2.moveBall();
        ball3.moveBall();

        ball.collisionCheck(ball2);
        ball.collisionCheck(ball3);
        ball2.collisionCheck(ball3);

        if (g.kbhit()) {
            g.getKey();
        }

        g.update();
    }
    return 0;
}