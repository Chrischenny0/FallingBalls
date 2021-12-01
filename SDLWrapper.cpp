#include "SDLWrapper.h"
#include "BMPImage.h"

//Constructor
SDLWrapper::SDLWrapper(int width, int height, bool s) : g(height, width, s) {
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

void SDLWrapper::redrawBkG(int x, int y,
                           const vector<vector<vector<unsigned char>>> &mask) {

    for (int i = y; i < mask.size() + y; i++) {
        for (int j = x; j < mask.at(i - y).size() + x; j++) {
            if (mask.at(i - y).at(j - x).at(3) == 255) {
                if (i >= 0 && i < height &&
                    j >= 0 && j < (width)) {
                    drawPixel(j, i, background.at(i).at(j).at(2),
                              background.at(i).at(j).at(1),
                              background.at(i).at(j).at(0));
                }
            }
        }
    }
}