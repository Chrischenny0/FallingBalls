#include "Ball.h"

using namespace std;

int main(int argc, char **argv) {
    int disWidth = 1200;
    int disLength = 950;
    Coordinate lowerBound(15, 25), upperBound(765, 925);
    SDLWrapper g(disWidth, disLength, false);

    BMPImage background("images/BackgroundV2.bmp", 0, 0, g);
    BMPImage ballMask("images/BallV2.bmp", 0, 0, g);
    BMPImage brickMask("images/Brick.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(300, 300, ballMask, g, lowerBound, upperBound);
    Ball ball2(100, 400, ballMask, g, lowerBound, upperBound);
    Ball ball3(600, 450, ballMask, g, lowerBound, upperBound);
    Brick brick(200, 200, brickMask, g);

    vector<Ball*> balls;
    balls.push_back(&ball);
    balls.push_back(&ball2);
    balls.push_back(&ball3);

    while (!g.getQuit()) {

        for(int i = 0; i < 3; i++){

        }

        for(int i = 0; i < 3; i++){
            balls.at(i) -> drawBall();
        }

        for(int i = 0; i < 3; i++){
            balls.at(i) -> applyForce(Gravity);
        }

        for(int i = 0; i < 3; i++){
            balls.at(i) -> moveBall();
            balls.at(i) -> outOfBounds();
        }

        brick.drawBrick();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j){
                    balls.at(i) -> collisionCheck(*balls.at(j));
                }
            }
        }

        ball.collisionCheck(brick);
        ball2.collisionCheck(brick);
        ball3.collisionCheck(brick);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j){
                    balls.at(i) -> collisionCheck(*balls.at(j));
                }
            }
        }


        if (g.kbhit()) {
            g.getKey();
        }

        g.update();
    }
    return 0;
}