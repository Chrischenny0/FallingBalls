#include "Ball.h"

Ball::Ball(Coordinate center, BMPImage *image, SDLWrapper &g, Coordinate &lowerBound, Coordinate &upperBound) :
                                                           center(center), previousCord(center),
                                                           mask(image), g(g),
                                                           lowerBound(lowerBound), upperBound(upperBound) {
    r = (mask -> getSizeX()) / 2;
    mask -> setPosition(Coordinate(center.x - r, center.y - r));
}

void Ball::drawBall() {
    if (center.delta(previousCord) != 0) {
        Coordinate lowerLeft(previousCord.x - r, previousCord.y - r);
        mask->redrawBkG(lowerLeft);
        previousCord = center;
    }
    mask->draw(Coordinate(center.x - r, center.y - r), lowerBound);
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
    if(center.y + r > upperBound.y){
        vector.redirect(0);
    }

    while(center.x < lowerBound.x || center.adjust(r) >= upperBound){
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

bool Ball::collisionCheck(Brick &b2){
    vector.normalize();
    Coordinate& bCenter = b2.getCenter();
    bool collision = false;

    double theta = atan(center.slope(b2.getCenter()));

    if(center.x > bCenter.x){
        theta += PI;
    }

    Coordinate intersection(r * cos(theta) + center.x, r * sin(theta) + center.y);

    if (b2.collisionBrick(intersection)) {
        //Added Decrement of Col Count
        b2.decrementColCount();

        double invertVec = vector.invert();

        while(b2.collisionBrick(intersection)){
            moveBall(1, invertVec);

            theta = atan(center.slope(b2.getCenter()));

            if(center.x > bCenter.x){
                theta += PI;
            }

            intersection.x = r * cos(theta) + center.x;
            intersection.y = r * sin(theta) + center.y;
        }

        if(center.x >= b2.getLowerLeft().x && center.x <= b2.getUpperRight().x){

            vector.redirect(0);
        }
        else if(center.y >= b2.getLowerLeft().y && center.y <= b2.getUpperRight().y){
            vector.redirect(1);
        }
        else{
            vector.setDir(vector.invert());
        }

        vector.normalize();
        moveBall();

        collision = true;
    }
    return collision;
}

void Ball::setMagDir(Force f) {
    vector = f;
}
