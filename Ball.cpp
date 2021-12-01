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

    if (abs(vector.getDirection()) > PI) {
        double dir = vector.getDirection();
        vector.setDirection(-(PI - (dir - PI)));
    }

    center.y += vector.getMagnitude() * sin(vector.getDirection());
    center.x += vector.getMagnitude() * cos(vector.getDirection());

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

    drawBall();
}

void Ball::applyForce(const Force &f) {
    vector.apply(f);
}

void Ball::collisionCheck(Ball &ballCheck) {
    if (abs(vector.getDirection()) > PI) {
        double dir = vector.getDirection();
        vector.setDirection((PI - (dir - PI)) * dir/abs(dir));
    }

    if (center.distance(ballCheck.center) < r + ballCheck.r - 1) {
        double slope = -1 / center.slope(ballCheck.center);

        vector.setDirection((PI - (vector.getDirection() - atan(slope)) + atan(slope)) - PI);

        ballCheck.vector.setDirection((PI - (ballCheck.vector.getDirection() - atan(slope)) + atan(slope)) - PI );

        /*if(abs(vector.getDirection())/vector.getDirection() != abs(ballCheck.vector.getDirection())/ballCheck.vector.getDirection()){

        }
        else if(vector.getDirection() < 0){
            double slope = -1 / center.slope(ballCheck.center);
            double difference = center.y - ballCheck.center.y;

            vector.setDirection((PI - ((vector.getDirection() - ((difference < -50) ? PI : 0) - atan(slope)) + atan(slope)) - PI));

            ballCheck.vector.setDirection((PI - (ballCheck.vector.getDirection() - ((difference > 50) ? PI : 0) - atan(slope)) + atan(slope)) - PI );
        }
        else if(vector.getDirection() > 0){
            double slope = -1 / center.slope(ballCheck.center);
            double difference = center.y - ballCheck.center.y;

            vector.setDirection((PI - ((vector.getDirection() + ((difference > 50) ? PI : 0) - atan(slope)) + atan(slope)) - PI));

            ballCheck.vector.setDirection((PI - (ballCheck.vector.getDirection() + ((difference < -50) ? PI : 0) - atan(slope)) + atan(slope)) - PI );
        }*/
        //vector.setMagnitude((vector.getMagnitude() + ballCheck.vector.getMagnitude()) / 2);
        ballCheck.vector.setMagnitude(vector.getMagnitude());
        while (center.distance(ballCheck.center) < r + ballCheck.r - 3){
            moveBall();
            ballCheck.moveBall();
        }
    }
}

Coordinate Ball::getCoords() {
    return center;
}
