#include "Ball.h"
#include "Brick.h"

using namespace std;

int main(int argc, char **argv) {
    int disWidth = 1000;
    int disLength = 600;
    SDLWrapper g(disWidth, disLength, false);

    BMPImage background("images/Background1600.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(300, 300, "images/Ball.bmp", g);
    Ball ball2(100, 400, "images/Ball.bmp", g);
    Ball ball3(800, 450, "images/Ball.bmp", g);
    Brick brick(200, 500, "images/Brick.bmp", g);

    vector<Ball> balls;

    while (!g.getQuit()) {

        ball.drawBall();
        ball2.drawBall();
        ball3.drawBall();

        brick.drawBrick();

        ball.applyForce(Gravity);
        ball2.applyForce(Gravity);
        ball3.applyForce(Gravity);

        ball.moveBall();
        ball2.moveBall();
        ball3.moveBall();

        ball.collisionCheck(ball2);
        ball.collisionCheck(ball3);

        ball2.collisionCheck(ball);
        ball2.collisionCheck(ball3);

        ball3.collisionCheck(ball);
        ball3.collisionCheck(ball2);


        if (g.kbhit()) {
            g.getKey();
        }

        g.update();
    }
    return 0;
}