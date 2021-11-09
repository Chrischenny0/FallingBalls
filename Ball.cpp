#include "Ball.h"

Ball::Ball(int x, int y, int r, const string& image, SDLWrapper &g):
mask(image, x - r, y - r, g), g(g), center(x, y), previousCord(x, y) {

    this -> r = r;

}

void Ball::drawBall() {
    if(center.delta(previousCord) != 0){
        previousCord = center;
        mask.redrawBkG();
    }
    mask.draw(g, center.x - r, center.y - r);
}

void Ball::moveBall() {

    center.y += vector.getMagnitude() * sin(vector.getDirection());
    center.x += vector.getMagnitude() * cos(vector.getDirection());

    if(center.x + r > g.getWidth() || center.x + r < 0){
        vector.redirect(0);
    }
    if(center.y + r > g.getHeight() || center.y + r < 0){
        vector.redirect(1);
    }

    drawBall();
}

void Ball::applyForce(const Force &f) {
    vector.apply(f);
}