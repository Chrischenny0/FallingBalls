#include "Ball.h"

using namespace std;

int main(int argc, char **argv) {
    int disWidth = 1200;
    int disLength = 950;
    Coordinate space1(15, 25), space2(165, 25), space3(315, 25);
    Coordinate space4(465, 25), space5(615, 25);
    Coordinate lowerBound(15, 25), upperBound(765, 925);
    SDLWrapper g(disWidth, disLength, false);

    BMPImage background("images/BackgroundV2.bmp", 0, 0, g);
    BMPImage ballMask("images/BallV2.bmp", 0, 0, g);
    BMPImage brickMask("images/Brick.bmp", 0, 0, g);
    background.setBackground();

    Ball ball(300, 300, ballMask, g, lowerBound, upperBound);
    Ball ball2(100, 400, ballMask, g, lowerBound, upperBound);
    Ball ball3(600, 450, ballMask, g, lowerBound, upperBound);
    Brick brick(space1.x, space1.y, brickMask, g);
    Brick brick2(space2.x, space2.y, brickMask, g);
    Brick brick3(space3.x, space3.y, brickMask, g);
    Brick brick4(space4.x, space4.y, brickMask, g);
    Brick brick5(space5.x, space5.y, brickMask, g);

    vector<Brick*> bricks;

    bricks.push_back(&brick);
    bricks.push_back(&brick2);
    bricks.push_back(&brick3);
    bricks.push_back(&brick4);
    bricks.push_back(&brick5);


    vector<Ball*> balls;
    balls.push_back(&ball);
    balls.push_back(&ball2);
    balls.push_back(&ball3);


    while (!g.getQuit()) {
        /*
         * Brick Space Formula:
         * xPos = (rand % screenSize) + leftMargin;
         * if(xPos ){
         *
         * }
         */

        for(int i = 0; i < 3; i++){

        }

        for(int i = 0; i < 3; i++){
            balls.at(i) -> drawBall();
        }

        brick.drawBrick();
        brick2.drawBrick();
        brick3.drawBrick();
        brick4.drawBrick();
        brick5.drawBrick();


        for(int i = 0; i < 3; i++){
            balls.at(i) -> applyForce(Gravity);
        }

        for(int i = 0; i < 3; i++){
            balls.at(i) -> moveBall();
            balls.at(i) -> outOfBounds();
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j){
                    balls.at(i) -> collisionCheck(*balls.at(j));
                }
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j){
                    balls.at(i) -> collisionCheck(*balls.at(j));
                }
            }
        }

        for(int i = 0; i < balls.size(); i++){
            for(int j = 0; j < bricks.size(); j++){
                balls.at(i) -> collisionCheck(*bricks.at(j));
            }
        }



        if (g.kbhit()) {
            g.getKey();
        }

        g.update();
    }
    return 0;
}