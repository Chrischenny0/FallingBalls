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
#ifndef CL10_18_2021_SDLWRAPPER_H
#define CL10_18_2021_SDLWRAPPER_H

#include <string>
#include <vector>
#include "Coordinate.h"
#include "SDL_Plotter.h"
#include <ctime>
#include <chrono>
#include <sys/time.h>

class SDLWrapper {
private:
    //SDL_Plotter
    SDL_Plotter g;

    //SDlWrapper Variables
    int width, height;
    vector<vector<vector<unsigned char>>> background;

    //For fps lock
    time_t curr = time(nullptr);
    int fps = 0;
    double sleep = 5;

public:
    //Constructor
    /*
     * DESCRIPTION:
     *      Constructor for the SDL Wrapper.
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      2 integers for the width and height of the screen is provided
     *      along with bool for sound.
     * POSTCONDITION:
     *      A SDL Wrapper object is created with width and height specified.
     */
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
    /*
     * DESCRIPTION:
     *      Sets the background of the SDL Image.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid SDL Wrapper object exists.
     * POSTCONDITION:
     *      The background is stored as a 3D vector inside the SDL Wrapper.
     */
    void setBackground(const vector<vector<vector<unsigned char>>> &newBKG);

    /*
     * DESCRIPTION:
     *      Redraws the background at the specified x and y using the mask
     *      dimensions.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid SDL Wrapper object exists.
     * POSTCONDITION:
     *      The background is at the specified x and y and with the
     *      dimensions of the provided mask.
     */
    void redrawBkG(int x, int y, const vector<vector<vector<unsigned char>>> &mask);

    /*
     * DESCRIPTION:
     *      Redraws the background at the specified upper and lower coordinates.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid SDL Wrapper object exists.
     * POSTCONDITION:
     *      The background is redrawn between the two provided coordinates.
     */
    void redrawBkG(Coordinate lowerleft, Coordinate upperRight);
};

#endif //CL10_18_2021_SDLWRAPPER_H
