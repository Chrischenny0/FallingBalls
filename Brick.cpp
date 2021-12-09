/*
 * AUTHOR: Christopher Chenoweth, Katie Boatwright, Luke Smith,
 *    Preston Witschonke, Shepard Berry
 * ASSIGNMENT TITLE: Falling Balls
 * ASSIGNMENT DESCRIPTION:
 *      Create a version of the game falling balls.
 * DUE DATE: 12/08/2021
 * DATE CREATED: 11/03/2021
 * DATE LAST MODIFIED: 12/08/2021
 */
#include "Brick.h"
#include "Font.h"

Brick::Brick(int x, int y, BMPImage *mask, SDLWrapper &g, Font *hpFont, int hp)
        :
        mask(mask), g(g), lowerLeft(x, y), upperRight(x, y), center(x, y),
        hpFont(hpFont), hp(hp) {

    upperRight.x += mask->getSizeX();
    upperRight.y += mask->getSizeY();

    center.x += mask->getSizeX() / 2.0;
    center.y += mask->getSizeY() / 2.0;
    mask->setPosition(Coordinate(lowerLeft.x, lowerLeft.y));
}

void Brick::drawBrick() {
    mask->draw(lowerLeft, Coordinate(15, 25));
    hpFont->setMessage(to_string(hp));
    hpFont->draw();
}

void Brick::moveBrick() {
    Coordinate previous = lowerLeft;
    lowerLeft.y += 75;
    center.y += 75;
    upperRight.y += 75;
    hpFont->setLocation(center);
    redrawBackground(previous);
}

void Brick::decrementColCount() {
    hp--;
}

int Brick::getColCount() {
    return hp;
}

bool Brick::collisionBrick(Coordinate &p2) {
    return p2.x >= lowerLeft.x && p2.y >= lowerLeft.y &&
           p2.x <= upperRight.x && p2.y <= upperRight.y;
}

Coordinate &Brick::getCenter() {
    return center;
}

const Coordinate &Brick::getLowerLeft() const {
    return lowerLeft;
}

const Coordinate &Brick::getUpperRight() const {
    return upperRight;
}

void Brick::redrawBackground() const {
    redrawBackground(lowerLeft);
}

void Brick::redrawBackground(const Coordinate &coord) const {
    mask->redrawBkG(coord);
}

