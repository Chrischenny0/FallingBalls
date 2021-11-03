#ifndef CL10_18_2021_SDLWRAPPER_H
#define CL10_18_2021_SDLWRAPPER_H

#include <string>
#include <vector>
#include "SDL_Plotter.h"

class SDLWrapper{
    private:
        //SDL_Plotter
        SDL_Plotter g;

        //SDl_Handler Variables
        int width, height;
        vector<vector<unsigned char>> background;

    public:
        //Constructor
        SDLWrapper(int x, int y, bool s);

        //SDL_Plotter Functions
        void drawPixel(int x, int y, int r, int g, int b);
        void setSound(const string &name);
        void startSound(const string &name);
        void stopSound(const string &name);
        bool getQuit();
        bool kbhit();
        char getKey();
        void update();
        int  getWidth();
        int  getHeight();

        //SDLWrapper Functions
        void setBackground(const vector<vector<unsigned char>> &background);
        void redrawBkG(int x, int y, int sizeX, int sizeY);

        const vector<vector<unsigned char>> & getBackground();
};

#endif //CL10_18_2021_SDLWRAPPER_H
