#ifndef CL10_18_2021_SDLWRAPPER_H
#define CL10_18_2021_SDLWRAPPER_H

#include <string>
#include <vector>
#include "Coordinate.h"
#include "SDL_Plotter.h"

class SDLWrapper {
private:
    //SDL_Plotter
    SDL_Plotter g;

    //SDlWrapper Variables
    int width, height;
    vector<vector<vector<unsigned char>>> background;

public:
    //Constructor
    SDLWrapper(int width, int height, bool s);

    //SDL_Plotter Functions
    void drawPixel(int x, int y, int r, int g, int b);

    void setSound(const string &name);

    void startSound(const string &name);

    void stopSound(const string &name);

    bool getQuit();

    bool kbhit();

    char getKey();

    void update();

    int getWidth() const;

    int getHeight() const;

    void Sleep(int ms);
    bool getMouseClick(int& x, int& y);
    bool getMouseDown(int& x, int& y);
    bool getMouseUp(int& x, int& y);
    bool getMouseMotion(int& x, int& y);
    void getMouseLocation(int& x, int& y);

    //SDLWrapper Functions
    void setBackground(const vector<vector<vector<unsigned char>>> &newBKG);

    void
    redrawBkG(int x, int y, const vector<vector<vector<unsigned char>>> &mask);
};

#endif //CL10_18_2021_SDLWRAPPER_H
