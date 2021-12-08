#include "SDLWrapper.h"
#include "BMPImage.h"

//Constructor
SDLWrapper::SDLWrapper(int width, int height, bool s) : g(height, width, s){
    this->width = width;
    this->height = height;
}

//SDL_Plotter Functions
void SDLWrapper::drawPixel(int x, int y, int R, int G, int B) {
    if (x >= 0 && x < width && y > 0 && y <= height) {
        g.plotPixel(x, height - y, R, G, B);
    }
}

void SDLWrapper::setSound(const string &name) {
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
    return width;
}

int SDLWrapper::getHeight() const {
    return height;
}


//SDLWrapper Functions

void SDLWrapper::setBackground(const vector<vector<vector<unsigned char>>>
                               &newBKG) {
    background = newBKG;
}

void SDLWrapper::redrawBkG(int x, int y, const vector<vector<vector<unsigned char>>> &mask) {
    bool alpha = (mask.at(0).at(0).size() == 4);

    for(int i = 0; i < mask.size(); i++){
        for(int j = 0; j < mask.at(i).size(); j++){
            if (!alpha || mask.at(i).at(j).at(3) == 255){
                if (i + y >= 0 && i + y < height && j + x >= 0 && j + x < width) {
                    drawPixel(j + x, i + y, background.at(i + y).at(j + x).at(2),background.at(i + y).at(j + x).at(1),background.at(i + y).at(j + x).at(0));
                }
            }
        }
    }
}

void SDLWrapper::redrawBkG(Coordinate lowerleft, Coordinate upperRight) {
    int x = lowerleft.x;
    int y = lowerleft.y;
    for(int i = 0; i < upperRight.y - lowerleft.y; i++){
        for(int j = 0; j < upperRight.x - lowerleft.x; j++){
            if (i + lowerleft.y >= 0 && i + lowerleft.y < height && j + lowerleft.x >= 0 && j + lowerleft.x < width) {
                drawPixel(j + x, i + y, background.at(i + y).at(j + x).at(2),background.at(i + y).at(j + x).at(1),background.at(i + y).at(j + x).at(0));
            }
        }
    }
}

void SDLWrapper::Sleep(int ms) {
    g.Sleep(ms);
}

bool SDLWrapper::getMouseClick(int &x, int &y) {
    return g.getMouseClick(x, y);
}

bool SDLWrapper::getMouseDown(int &x, int &y) {
    return g.getMouseDown(x, y);
}

bool SDLWrapper::getMouseUp(int &x, int &y) {
    return false;
}

bool SDLWrapper::getMouseMotion(int &x, int &y) {
    return false;
}

void SDLWrapper::getMouseLocation(int &x, int &y) {

}