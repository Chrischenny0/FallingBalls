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
#ifndef FALLINGBALLS_BRICK_H
#define FALLINGBALLS_BRICK_H

#include "Coordinate.h"
#include "Force.h"
#include "BMPImage.h"
#include "Font.h"

class Brick{
private:
    int l, w, hp = 3;

    Coordinate lowerLeft, upperRight, center;

    BMPImage *mask;
    SDLWrapper &g;

    Font *hpFont;

public:
    /*
     * DESCRIPTION:
     *    Constructor for the brick class
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      A x y location, BMP Image object, Font object, and intial hp (hit
     *      points) is provided to the constructor.
     * POSTCONDITION:
     *      A brick object is created.
     */
    Brick(int x, int y, BMPImage *mask, SDLWrapper &g, Font *hpFont, int hp);

    /*
     * DESCRIPTION:
     *      Gets the center of the brick.
     * RETURN:
     *      Coordinate
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The center of the brick is returned as a Coordinate object.
     */
    Coordinate& getCenter();

    /*
     * DESCRIPTION:
     *      Gets the lower left of the brick.
     * RETURN:
     *      Coordinate
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The lower left coordinate of the brick is returned as a Coordinate
     *      object.
     */
    const Coordinate &getLowerLeft() const;

    /*
     * DESCRIPTION:
     *      Gets the upper right of the brick.
     * RETURN:
     *      Coordinate
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The upper right coordinate of the brick is returned as a Coordinate
     *      object.
     */
    const Coordinate &getUpperRight() const;

    /*
     * DESCRIPTION:
     *      Draws the brick at the current position.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The brick is drawn to the screen at its current position.
     */
    void drawBrick();

    /*
     * DESCRIPTION:
     *      Redraws the background that was behind the brick
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The background behind the brick is redrawn.
     *      There is a background set in the SDL Wrapper object.
     */
    void redrawBackground() const;

    /*
     * DESCRIPTION:
     *      Redraws the background at the given position
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The background at the given position is redrawn.
     *      There is a background set in the SDL Wrapper object.
     */
    void redrawBackground(const Coordinate &coord) const;

    /*
     * DESCRIPTION:
     *      Moves the brick up at the end of every round.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The brick is moved up 75 pixels and redrawn
     *      There is a background set in the SDL Wrapper object.
     */
    void moveBrick();

    /*
     * DESCRIPTION:
     *      Decreases the HP of the brick by one.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The HP of the brick is decremented.
     */
    void decrementColCount();

    /*
     * DESCRIPTION:
     *      Returns the current HP of the brick.
     * RETURN:
     *      int
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      The current HP is returned as an integer.
     */
    int getColCount();

    /*
     * DESCRIPTION:
     *      Checks if the given coordinate lies within the bounds of the brick.
     * RETURN:
     *      bool
     * PRECONDITION:
     *      A valid brick object exists.
     * POSTCONDITION:
     *      True is returned if the provided coordinate lies within the
     *      bounds of the brick.
     */
    bool collisionBrick(Coordinate &);
};

#endif //FALLINGBALLS_BRICK_H
