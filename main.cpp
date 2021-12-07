#include "Ball.h"
#include "Font.h"

using namespace std;

int main(int argc, char **argv) {
    int disWidth = 1200;
    int disLength = 950;
    Coordinate lowerBound(15, 25), upperBound(765, 925); //750 x 900
    SDLWrapper g(disWidth, disLength, false);

    BMPImage background("images/BackgroundV3.bmp", 0, 0, g);
    BMPImage ballMask("images/BallV2.bmp", 0, 0, g);
    BMPImage brickMask("images/Brick.bmp", 0, 0, g);

    Font highScore(g, Coordinate(900, 200));
    highScore.setMessage("hello");
    background.setBackground();

    vector<Brick*> bricks;
    bricks.push_back(new Brick(150, 200, brickMask, g));
    bricks.push_back(new Brick(300, 200, brickMask, g));
    bricks.push_back(new Brick(450, 200, brickMask, g));
    bricks.push_back(new Brick(600, 200, brickMask, g));
    bricks.push_back(new Brick(150, 400, brickMask, g));
    bricks.push_back(new Brick(300, 400, brickMask, g));
    bricks.push_back(new Brick(450, 400, brickMask, g));
    bricks.push_back(new Brick(600, 400, brickMask, g));

    vector<Ball*> balls;
    balls.push_back(new Ball(300, 600, ballMask, g, lowerBound, upperBound));
    balls.push_back(new Ball(100, 600, ballMask, g, lowerBound, upperBound));
    balls.push_back(new Ball(600, 600, ballMask, g, lowerBound, upperBound));

    while (!g.getQuit()) {

        for(int i = 0; i < balls.size(); i++){
            balls.at(i) -> drawBall();
        }
        for(int i = 0; i < bricks.size(); i++){
            bricks.at(i) -> drawBrick();
        }
        highScore.draw();

        for(int i = 0; i < balls.size(); i++){
            balls.at(i) -> applyForce(Gravity);
        }

        for(int i = 0; i < balls.size(); i++){
            balls.at(i) -> moveBall();
            balls.at(i) -> outOfBounds();
        }

        for(int i = 0; i < balls.size(); i++){
            for(int j = 0; j < balls.size(); j++){
                if(i != j){
                    balls.at(i) -> collisionCheck(*balls.at(j));
                }
            }
        }

        for(int i = 0; i < balls.size(); i++){
            for(int j = 0; j < balls.size(); j++){
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

        for(int i = 0; i < bricks.size(); i++){
            if(bricks.at(i) -> getColCount() < 0){
                bricks.at(i) -> redrawBackground();
                delete bricks.at(i);
                bricks.erase(bricks.begin() + i);
            }
        }


        if (g.kbhit()) {
            g.getKey();
        }

        g.update();
    }
    return 0;
}