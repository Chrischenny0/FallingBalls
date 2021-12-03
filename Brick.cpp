//
// Created by Luke Smith on 12/1/21.
//

#include "Brick.h"

Brick::Brick(int x, int y, const string &image, SDLWrapper &g) :
        mask(image, x, y, g), g(g), center(x, y), previousCord(x, y){
    w = mask.getSizeX() / 2;
    l = mask.getSizeX() / 2;
    mask.setPosition(Coordinate(center.x - w, center.y - l));
}

void Brick::drawBrick() {
    if (center.delta(previousCord) != 0) {
        Coordinate lowerLeft(previousCord.x - w, previousCord.y - l);
        mask.redrawBkG(lowerLeft, mask.getRGB());
        previousCord = center;
    }
    mask.draw(g, center.x - l, center.y - l);
}

void Brick::moveBrick(){

}

void Brick::outOfBounds(){
    while(center.x + l > g.getWidth() || center.y + w > g.getHeight()){
        if(center.x + l < 0){
            center.x += abs(0 - center.x + l);
        }
        if(center.x + l >= g.getWidth()){
            center.x -= abs(g.getWidth() - center.x + l);
        }
    }
}
