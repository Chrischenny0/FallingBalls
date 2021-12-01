#include "Ball.h"

Ball::Ball(int x, int y, const string &image, SDLWrapper &g) :
        mask(image, x, y, g), g(g), center(x, y), previousCord(x, y) {
    r = mask.getSizeX() / 2;
    mask.setPosition(Coordinate(center.x - r, center.y - r));
}

void Ball::drawBall() {
    if (center.delta(previousCord) != 0) {
        Coordinate lowerLeft(previousCord.x - r, previousCord.y - r);
        mask.redrawBkG(lowerLeft, mask.getRGB());
        previousCord = center;
    }
    mask.draw(g, center.x - r, center.y - r);
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

        Force tmp1 = vector, tmp2 = ballCheck.vector;
        vector.setDir(vector.getDir() + PI);
        vector.setMag(1);
        ballCheck.vector.setDir(vector.getDir() + PI);
        ballCheck.vector.setMag(1);
        while(center.distance(ballCheck.center) < r + ballCheck.r - 1){
            moveBall();
        }
        vector = tmp1;
        ballCheck.vector = tmp2;

        if(abs(vector.getDir()) / vector.getDir() != abs(ballCheck.vector.getDir()) /
                                                     ballCheck.vector.getDir()){
            double slope = -1 / center.slope(ballCheck.center);

            vector.setDir((PI - (vector.getDir() - atan(slope)) + atan(slope)) - PI);

            ballCheck.vector.setDir((PI - (ballCheck.vector.getDir() - atan(slope)) + atan(slope)) - PI);
        }
        else if(vector.getDir() < 0){
            double slope = -1 / center.slope(ballCheck.center);
            double difference = center.y - ballCheck.center.y;

            vector.setDir(
                    (PI - ((vector.getDir() - ((difference < -50) ? PI : 0) - atan(slope)) + atan(slope)) - PI));

            ballCheck.vector.setDir(
                    (PI - (ballCheck.vector.getDir() - ((difference > 50) ? PI : 0) - atan(slope)) +
                     atan(slope)) - PI);
        }
        else if(vector.getDir() > 0){
            double slope = -1 / center.slope(ballCheck.center);
            double difference = center.y - ballCheck.center.y;

            vector.setDir(
                    (PI - ((vector.getDir() + ((difference > 50) ? PI : 0) - atan(slope)) + atan(slope)) - PI));

            ballCheck.vector.setDir(
                    (PI - (ballCheck.vector.getDir() + ((difference < -50) ? PI : 0) - atan(slope)) +
                     atan(slope)) - PI);
        }
        //vector.setMagnitude((vector.getMagnitude() + ballCheck.vector.getMagnitude()) / 2);
        //ballCheck.vector.setMagnitude(vector.getMagnitude());
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
