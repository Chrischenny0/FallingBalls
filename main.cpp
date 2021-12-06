#include "Ball.h"

using namespace std;

int main(int argc, char **argv) {
    int disWidth = 1200;
    int disLength = 950;
    Coordinate lowerBound(15, 25), upperBound(765, 925);
    SDLWrapper g(disWidth, disLength, false);

    BMPImage background("images/BackgroundV2.bmp", 0, 0, g);
    BMPImage ballMask("images/Ball.bmp", 0, 0, g);
    BMPImage brickMask("images/Brick.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(300, 300, ballMask, g, lowerBound, upperBound);
    Ball ball2(100, 400, ballMask, g, lowerBound, upperBound);
    Ball ball3(600, 450, ballMask, g, lowerBound, upperBound);
    Brick brick(rand() % g.getWidth(), 200, brickMask, g);

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

        ball.outOfBounds();
        ball2.outOfBounds();
        ball3.outOfBounds();

        ball.collisionCheck(ball2);
        ball.collisionCheck(ball3);


        ball2.collisionCheck(ball);
        ball2.collisionCheck(ball3);


        ball3.collisionCheck(ball);
        ball3.collisionCheck(ball2);

        ball.collisionCheck(brick);
        ball2.collisionCheck(brick);
        ball3.collisionCheck(brick);


        if (g.kbhit()) {
            g.getKey();
        }

        g.update();
    }
    return 0;
}