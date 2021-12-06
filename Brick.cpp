#include "Brick.h"

Brick::Brick(int x, int y, BMPImage &mask, SDLWrapper &g) :
        mask(mask), g(g), center(x, y){
    w = mask.getSizeX() / 2;
    l = mask.getSizeX() / 2;
    mask.setPosition(Coordinate(center.x - w, center.y - l));
}

int Brick::getLength(){
    return l;
}

void Brick::drawBrick(){
    mask.draw((center.x - l), (center.y - l));
}

void Brick::moveBrick(){
    center.y += 2;
}

void Brick::outOfBounds(){
    while(center.x + l > g.getWidth() || center.y + w > g.getHeight()){
        if(center.x + l < 0){
            center.x += abs(0 - center.x + l);
        }
        if(center.x + l >= g.getWidth()){
            center.x -= abs(g.getWidth() - center.x + l);
        }
    }
}

bool Brick::collisionBrick(Coordinate &ballCenter){

    //If balls radius touches brick
    /*if(center.distance(ball.getCoords()) < 0){

        stepBack(ball);

        double slope = -1 / center.slope(ball.center);

        vector.collide(ballCheck.vector, slope, center.y - ballCheck.center.y, center.x - ballCheck.center.x);

        while(center.distance(ballCheck.center) < r + ballCheck.r){
            moveBall();
            ballCheck.moveBall();
        }
    }*/

    if(ballCenter.x > center.x - w / 2 && ballCenter.x < center.x + w / 2){

    }

    return (ballCenter.x > center.x - w / 2 && ballCenter.x < center.x + w / 2) &&
            (ballCenter.y > center.y - l / 2 && ballCenter.y < center.y + l / 2);
}

Coordinate& Brick::getCenter(){
    return center;
}

