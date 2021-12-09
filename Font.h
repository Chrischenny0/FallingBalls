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
#ifndef FALLINGBALLS_FONT_H
#define FALLINGBALLS_FONT_H

#include "BMPImage.h"

class Font {
private:
    vector<BMPImage*>* characters;
    vector<BMPImage*>* numbers;

    vector<int> message;

    Coordinate lowerLeft;
    bool centered;

    int length = 0;

public:
    /*
     * DESCRIPTION:
     *      Constructor for Font object.
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      A SDL Wrapper object, Coordinate, character vector, number
     *      vector, and bool is provided to the constructor.
     * POSTCONDITION:
     *      A Font object is created at the given coordinate and centered
     *      aligned if provided true for the boolean.
     */
    Font(SDLWrapper &, Coordinate lowerLeft, vector<BMPImage *> &characters, vector<BMPImage *> &numbers,
         bool centered = false);

    /*
     * DESCRIPTION:
     *      Sets the location of the font at the given coordinate.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid coordinate object exists and is provided.
     * POSTCONDITION:
     *      The position of the text is changed to the provided point.
     */
    void setLocation(Coordinate);

    /*
     * DESCRIPTION:
     *      The message to be displayed is changed to the provided string.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid string exists and is provided.
     * POSTCONDITION:
     *      The message is set to the string.
     */
    void setMessage(const string&);

    /*
     * DESCRIPTION:
     *      Gets the length of the character in the provided font.
     * RETURN:
     *      int
     * PRECONDITION:
     *      A valid character that is in either the characters or numbers
     *      array is provided.
     * POSTCONDITION:
     *      Returns the length of the given character in the current font.
     */
    int getCharLength(char);

    /*
     * DESCRIPTION:
     *      Draw the text to the screen
     * RETURN:
     *      void
     * PRECONDITION:
     *      The font has a message provided.
     * POSTCONDITION:
     *      The current message is drawn to the screen at the current
     *      coordinates.
     */
    void draw();
};


#endif //FALLINGBALLS_FONT_H
