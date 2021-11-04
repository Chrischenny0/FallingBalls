#include "Ball.h"

Ball::Ball(int x, int y, int r, const string& image, SDLWrapper &g): mask(image, x - r, y - r, g), g(g), center(x, y) {
    this -> radius = r;

}

void Ball::drawBall() {
    mask.draw(g, center.x - radius, center.y - radius);
}

