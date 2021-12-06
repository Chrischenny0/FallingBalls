//
// Created by Luke Smith on 12/1/21.
//

#include "Brick.h"

Brick::Brick(int x, int y, BMPImage &mask, SDLWrapper &g) :
        mask(&mask), g(g), lowerLeft(x, y), upperRight(x, y), center(x, y){

    upperRight.x += mask.getSizeX();
    upperRight.y += mask.getSizeY();

    center.x += mask.getSizeX() / 2.0;
    center.y += mask.getSizeY() / 2.0;
    mask.setPosition(Coordinate(lowerLeft.x, lowerLeft.y));
}

int Brick::getLength(){
    return l;
}

void Brick::drawBrick(){
    mask -> draw(lowerLeft.x, lowerLeft.y);
}

void Brick::moveBrick(){
    lowerLeft.y += 2;
}

void Brick::outOfBounds(){
    while(lowerLeft.x + l > g.getWidth() || lowerLeft.y + w > g.getHeight()){
        if(lowerLeft.x + l < 0){
            lowerLeft.x += abs(0 - lowerLeft.x + l);
        }
        if(lowerLeft.x + l >= g.getWidth()){
            lowerLeft.x -= abs(g.getWidth() - lowerLeft.x + l);
        }
    }
}

bool Brick::collisionBrick(Coordinate &p2) const{
    return p2.x >= lowerLeft.x && p2.y >= lowerLeft.y && p2.x <= upperRight.x && p2.y <= upperRight.y;
}

Coordinate& Brick::getCenter(){
    /*lowerLeft.display();
    upperRight.display();*/
    return center;
}

