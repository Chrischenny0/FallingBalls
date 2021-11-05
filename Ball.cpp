#include "Ball.h"

Ball::Ball(int x, int y, int r, const string& image, SDLWrapper &g):
mask(image, x - r, y - r, g), g(g), center(x, y), previousCord(x, y) {

    this -> radius = r;

}

void Ball::drawBall() {
    if(center.delta(previousCord) != 0){
        previousCord = center;
        mask.redrawBkG();
    }
    mask.draw(g, center.x - radius, center.y - radius);
}

void Ball::moveBall(int newX, int newY) {
    center.x = newX;
    center.y = newY;
    drawBall();
}

