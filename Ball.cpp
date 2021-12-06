#include "Ball.h"

Ball::Ball(int x, int y, BMPImage &image, SDLWrapper &g, Coordinate &lowerBound, Coordinate &upperBound) :
                                                           center(x, y), previousCord(x, y),
                                                           mask(&image), g(g),
                                                           lowerBound(lowerBound), upperBound(upperBound) {

    r = (mask -> getSizeX()) / 2;
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
    outOfBounds();
}

Coordinate Ball::getCoords() {
    return center;
}

void Ball::outOfBounds() {
    double dirInvert = vector.invert();
    if(center.x - r < lowerBound.x || center.x + r > upperBound.x){
        vector.redirect(1);
    }
    if(center.y - r < lowerBound.y || center.y + r > upperBound.y){
        vector.redirect(0);
    }
    while(center.adjust(-r) <= lowerBound || center.adjust(r) >= upperBound){
        moveBall(1, dirInvert);
    }
    moveBall();
}

void Ball::stepBack(Ball &ballCheck) {
    double vectInvert1 = vector.invert(), vectInvert2 = ballCheck.vector.invert();

    while(center.distance(ballCheck.center) < r + ballCheck.r){
        moveBall(1, vectInvert1);
        ballCheck.moveBall(1, vectInvert2);
    }
}

void Ball::collisionCheck(Brick &b){
    double vertBoundsL = tan(31.0/69.0);

    Coordinate& bCenter = b.getCenter();
    double theta = atan(center.slope(b.getCenter()));

    if(center.x > bCenter.x){
        theta += PI;
    }

    Coordinate intersection(r * cos(theta) + center.x, r * sin(theta) + center.y);

    if (b.collisionBrick(intersection)) {

        double invertVec = vector.invert();

        while(b.collisionBrick(intersection)){
            moveBall(1, invertVec);

            theta = atan(center.slope(b.getCenter()));

            intersection.x = center.x + r * cos(theta);
            intersection.y = center.y + r * sin(theta);
        }

        if(theta > vertBoundsL && theta < PI - vertBoundsL){
            vector.redirect(0);
            vector.setMag(vector.getMag() )
        }
        else{
            vector.redirect(1);
        }
        vector.normalize();
        moveBall();
    }
}
