#include "SDLWrapper.h"

//Constructor
SDLWrapper::SDLWrapper(int width, int height, bool s): g(height, width, s){
    this -> width = width;
    this -> height = height;
}

//SDL_Plotter Functions
void SDLWrapper::drawPixel(int x, int y, int R, int G, int B){
    if(x >= 0 && x <= width && y > 0 && y < height){
        g.plotPixel(x, height - y, R, G, B);
    }
}

void SDLWrapper::setSound(const string &name){
    g.initSound(name);
}

void SDLWrapper::startSound(const string &name) {
    g.playSound(name);
}

void SDLWrapper::stopSound(const string &name) {
    g.quitSound(name);
}

bool SDLWrapper::getQuit() {
    return g.getQuit();
}

bool SDLWrapper::kbhit() {
    return g.kbhit();
}

char SDLWrapper::getKey() {
    return g.getKey();
}

void SDLWrapper::update() {
    g.update();
}

int SDLWrapper::getWidth() const {
    return height;
}

int SDLWrapper::getHeight() const {
    return width;
}


//SDLWrapper Functions

void SDLWrapper::setBackground(const vector<vector<unsigned char>> &background){
    this -> background = background;
}

void SDLWrapper::redrawBkG(int x, int y, int sizeX, int sizeY) {
    for(int i = y; i < sizeY + y; i++){
        for(int j = x; j < sizeX + x; j++){
            drawPixel(j, i, background.at(i).at(j*3+2), background.at(i).at
            (j*3+1), background.at(i).at(j*3));
        }
    }
}




