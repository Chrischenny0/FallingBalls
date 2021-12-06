#include "Ball.h"

Ball::Ball(int x, int y, BMPImage &image, SDLWrapper &g) : g(g), center(x, y), previousCord(x, y), mask(&image) {

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

void Ball::moveBall() {

    vector.normalize();

    center.y += vector.getMag() * sin(vector.getDir());
    center.x += vector.getMag() * cos(vector.getDir());

    outOfBounds();
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
    while (center.y + r > g.getHeight() || center.y - r < 0 || center.x + r >=
                                                                          g.getWidth()  || center.x - r < 0) {
        if (center.y + r > g.getHeight()) {
            center.y -= (((center.y + r) - g.getHeight())) * 2;
            vector.redirect(0);
        } else if (center.y - r < 0) {
            center.y += abs(center.y - r);
            vector.redirect(0);
        }
        if (center.x + r >= g.getWidth()) {
            center.x -= ((center.x + r) - g.getWidth()) * 2;
            vector.redirect(1);
        } else if (center.x - r < 0) {
            center.x += abs(center.x - r);
            vector.redirect(1);
        }
    }
}

void Ball::stepBack(Ball &ballCheck) {


    Force tmp1 = vector, tmp2 = ballCheck.vector;

    vector.setDir(vector.getDir() + PI);
    vector.setMag(1);
    ballCheck.vector.setDir(ballCheck.vector.getDir() + PI);
    ballCheck.vector.setMag(1);


    vector.normalize();
    ballCheck.vector.normalize();

    while(center.distance(ballCheck.center) < r + ballCheck.r){
        moveBall();
        ballCheck.moveBall();
    }

    vector = tmp1;
    ballCheck.vector = tmp2;
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
