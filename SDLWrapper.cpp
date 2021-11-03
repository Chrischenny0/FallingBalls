#include "SDLWrapper.h"

//Constructor
SDLWrapper::SDLWrapper(int x, int y, bool s): g(x, y, s){
    width = x;
    height = y;
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

int SDLWrapper::getWidth() {
    return height;
}

int SDLWrapper::getHeight() {
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

/*void SDLWrapper::getslice(int x, int y, int sizeX, int sizeY,
                      vector<vector<unsigned char>> &vec) {

    vec.clear();
    vector<unsigned char> newRow;

    for(int i = 0; i < sizeY; i++){
        for(int j = 0; j < sizeX * 3; j++){
            newRow.push_back(background.at(0).at(i).at(j));
        }
        vec.push_back(newRow);
        newRow.clear();
    }
}

void SDLWrapper::draw(int x, int y, const vector<vector<unsigned char>> &array) {
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array.at(i).size()/3; j++){
            g.plotPixel(j, y - i, array.at(i).at(j * 3 + 2), array.at(i).at
                    (j*3 + 1), array.at(i).at(j*3));
        }
    }
}

void SDLWrapper::drawBackground() {
    draw(0,height - 1, background.at(0));
}*/




