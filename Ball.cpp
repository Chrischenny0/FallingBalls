#include "Ball.h"

Ball::Ball(int x, int y, const string& image, SDLWrapper &g):
mask(image, x, y, g), g(g), center(x, y), previousCord(x, y) {
    r = mask.getSizeX() / 2;
    mask.setPosition(Coordinate(center.x - r, center.y - r));
}

void Ball::drawBall() {
    if(center.delta(previousCord) != 0){
        Coordinate lowerLeft(previousCord.x - r, previousCord.y - r);
        mask.redrawBkG(lowerLeft, mask.getSizeX(), mask.getSizeY());
        previousCord = center;
    }
    mask.draw(g, center.x - r, center.y - r);
}

void Ball::moveBall() {
    bool redirect = false;

    center.y += vector.getMagnitude() * sin(vector.getDirection());
    center.x += vector.getMagnitude() * cos(vector.getDirection());

    if(center.y + r > g.getHeight()){
        center.y -= (((center.y + r) - g.getHeight())) * 2;
        vector.redirect(0);
    }
    else if(center.y - r < 0){
        center.y += abs(center.y - r);
        vector.redirect(0);
    }
    if(center.x + r >= g.getWidth()){
        center.x -= ((center.x + r) - g.getWidth()) * 2;
        vector.redirect(1);
    }
    else if(center.x - r < 0){
        center.x += abs(center.x - r);
        vector.redirect(1);
    }

    drawBall();
}

void Ball::applyForce(const Force &f) {
    vector.apply(f);
}