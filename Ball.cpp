#include "Ball.h"

Ball::Ball(int x, int y, BMPImage &image, SDLWrapper &g, Coordinate &lowerBound, Coordinate &upperBound) :
                                                           center(x, y), previousCord(x, y),
                                                           mask(&image), g(g),
                                                           lowerBound(lowerBound), upperBound(upperBound) {

    r = mask -> getSizeX() / 2;
    mask -> setPosition(Coordinate(center.x - r, center.y - r));
}

void Ball::drawBall() {
    if (center.delta(previousCord) != 0) {
        Coordinate lowerLeft(previousCord.x - r, previousCord.y - r);
        mask -> redrawBkG(lowerLeft, mask -> getRGB());
        previousCord = center;
    }
    mask->draw(center.x - r, center.y - r);
}

void Ball::moveBall(double mag, double dir) {
    center.y += mag * sin(dir);
    center.x += mag * cos(dir);
}

void Ball::moveBall() {
    moveBall(vector.getMag(), vector.getDir());
}

void Ball::applyForce(const Force &f) {
    vector.apply(f);
}

void Ball::collisionCheck(Ball &ballCheck) {
    vector.normalize();
    ballCheck.vector.normalize();

    if (center.distance(ballCheck.center) < r + ballCheck.r) {

        stepBack(ballCheck);

        double slope = -1 / center.slope(ballCheck.center);

        vector.collide(ballCheck.vector, slope, center.y - ballCheck.center.y, center.x - ballCheck.center.x);

        while(center.distance(ballCheck.center) < r + ballCheck.r){
            moveBall();
            ballCheck.moveBall();
        }
    }
}

Coordinate Ball::getCoords() {
    return center;
}

void Ball::outOfBounds() {
    double dirInvert = vector.invert();
    int redirectX = -1;
    int redirectY = -1;
    if(center.x - r < lowerBound.x || center.x + r > upperBound.x){
        vector.redirect(1);
    }
    if(center.y - r < lowerBound.y || center.y + r > upperBound.y){
        vector.redirect(0);
    }
    while(center.adjust(-r) <= lowerBound || center.adjust(r) >= upperBound){
        moveBall(1, dirInvert);
    }
}

void Ball::stepBack(Ball &ballCheck) {


    double tmp1 = vector.invert(), tmp2 = ballCheck.vector.invert();

    while(center.distance(ballCheck.center) < r + ballCheck.r){
        moveBall(1, tmp1);
        ballCheck.moveBall(1, tmp2);
    }
}
void Ball::stepBack(const Coordinate& p2, double distance){

}


void Ball::collisionCheck(Brick &b){

    double theta = center.slope(b.getCenter());
    theta = atan(theta);

    Coordinate intersection(center.x + r * sin(theta), center.y + r * cos(theta));

    if (b.collisionBrick(intersection)) {
        Force tmp1 = vector;
        vector.setDir(vector.getDir() + PI);
        vector.setMag(1);

        while(b.collisionBrick(intersection)){
            moveBall();
            cout << "step back" << endl;

            theta = center.slope(b.getCenter());
            theta = atan(theta);

            intersection.x = center.x + r * sin(theta);
            intersection.y = center.y + r * cos(theta);
        }

        vector = tmp1;

        if(center.x > b.getCenter().x || center.x < b.getCenter().x){
            vector.redirect(0);
        }
        else{
            vector.redirect(1);
        }
        vector.normalize();
    }

}
