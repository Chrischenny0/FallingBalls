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
#ifndef CL10_18_2021_BMPTRANSFER_H
#define CL10_18_2021_BMPTRANSFER_H

#include <iostream>
#include <iterator>
#include <fstream>
#include <bitset>
#include <vector>
#include <cassert>
#include "SDLWrapper.h"

using namespace std;

class BMPImage {
private:
    //Image Info
    Coordinate pos;
    int sizeX, sizeY, pixelByte;
    string name;
    bool alpha, object = false;

    //
    SDLWrapper &g;

    //Pixel vectors
    vector<vector<vector<unsigned char>>> RGB;
public:
    /*
     * DESCRIPTION:
     *     Constructor for the BMP Image object
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      A string with the image, the lower left coordinate, SDL Wrapper,
     *      and bool are provided to the constructor.
     * POSTCONDITION:
     *      A BMP Image object is created with the provided image inside.
     */
    BMPImage(const string &name, int x, int y, SDLWrapper &g, bool object = false);

    /*
     * DESCRIPTION:
     *     Sets a new position for the image.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid coordinate object is provided.
     * POSTCONDITION:
     *      The lower left coordinate of the object is changed to the
     *      provided coordinate.
     */
    void setPosition(const Coordinate &);

    /*
     * DESCRIPTION:
     *     Gets size of the image on the x-axis.
     * RETURN:
     *      int
     * PRECONDITION:
     *      A valid BMP Image object exists.
     * POSTCONDITION:
     *      The width of the image is returned.
     */
    int getSizeX() const;

    /*
     * DESCRIPTION:
     *     Gets size of the image on the y-axis
     * RETURN:
     *      int
     * PRECONDITION:
     *      A valid BMP Image object exists.
     * POSTCONDITION:
     *      The height of the image is returned.
     */
    int getSizeY() const;

    /*
     * DESCRIPTION:
     *     Gets the current position of the image.
     * RETURN:
     *      Coordinate object
     * PRECONDITION:
     *      A valid BMP Image object exists.
     * POSTCONDITION:
     *      The position of the lower left corner of the image is returned.
     */
    Coordinate getPosition() const;

    /*
     * DESCRIPTION:
     *     Returns the pixel data of the image expressed in a 3D array.
     * RETURN:
     *      3D Vector of unsigned char
     * PRECONDITION:
     *      A valid BMP Image exists.
     * POSTCONDITION:
     *      The image expressed in a 3D vector is returned.
     */
    const vector<vector<vector<unsigned char>>> &getRGB() const;

    //SDL_Plotter Functions

    /*
     * DESCRIPTION:
     *     Draw the image on the screen
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid BMP Image object exists.
     * POSTCONDITION:
     *      The image is drawn to the screen at the coordinate provided.
     */
    void draw(const Coordinate &corner, const Coordinate lowerBound = Coordinate(0,0));

    /*
     * DESCRIPTION:
     *     Redraw the background at the specified position.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid BMP Image object exists.
     *      The SDL Wrapper has a valid background stored in it.
     * POSTCONDITION:
     *      The background at the specified position and using the sizes of
     *      the BMP Image class is redrawn.
     */
    void redrawBkG(const Coordinate &position);

    /*
     * DESCRIPTION:
     *     Sets the current BMP Image data as the background of the game.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid BMP Image object exists.
     * POSTCONDITION:
     *      The image is drawn to the screen and set as the background which
     *      is stored inside the SDL Wrapper object.
     */
    void setBackground();
};

#endif //CL10_18_2021_BMPTRANSFER_H
