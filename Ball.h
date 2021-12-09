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
#ifndef FALLINGBALLS_BALL_H
#define FALLINGBALLS_BALL_H

#include "BMPImage.h"
#include "Force.h"
#include "Brick.h"

class Ball {
private:
    int r;
    bool solidColor;

    Force vector;
    Coordinate center, previousCord;
    BMPImage *mask;
    SDLWrapper &g;

    Coordinate &lowerBound, &upperBound;

public:

    /*
     * DESCRIPTION:
     *      Constructor
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      Center Coordinate, BMPImage, SDLWrapper, and bounds of the play
     *      area are provided.
     * POSTCONDITION:
     *      A ball object is created.
     */
    Ball(Coordinate center, BMPImage *image, SDLWrapper &g, Coordinate
    &lowerBound, Coordinate &upperBound);

    /*
     * DESCRIPTION:
     *      Get the location of the ball
     * RETURN:
     *      Coordinate
     * PRECONDITION:
     *      Valid ball exists.
     * POSTCONDITION:
     *      The location of the ball is returned as a coordinate object.
     *      All original data remains unchanged.
     */
    Coordinate getCoords();


    /*
     * DESCRIPTION:
     *      Set the magnitude and direction of the ball.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid force is provided.
     * POSTCONDITION:
     *      The ball force is set to the values of the provided force.
     */
    void setMagDir(Force);

    /*
     * DESCRIPTION:
     *      Reset center back to the start of the game.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid ball object exists.
     * POSTCONDITION:
     *      The ball center is set to the original starting point.
     */
    void resetCenter() {
        center.x = 390;
        center.y = 880;
    }

    /*
     * DESCRIPTION:
     *      Draw the ball onto the screen
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid SDL Wrapper object exists.
     * POSTCONDITION:
     *      The ball is printed to the screen.
     */
    void drawBall();

    /*
     * DESCRIPTION:
     *      Move the ball by the given magnitude and direction.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid ball object exists.
     * POSTCONDITION:
     *      The ball is moved by the current force of the ball.
     */
    void moveBall();

    /*
     * DESCRIPTION:
     *      Move the ball by the given magnitude and direction.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      2 valid doubles exist and are provided.
     * POSTCONDITION:
     *      The ball is moved by the given magnitude and direction.
     */
    void moveBall(double mag, double dir);

    /*
     * DESCRIPTION:
     *      Apply a force to the current force of the ball.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid force object is provided.
     * POSTCONDITION:
     *      The balls force is added with the force provided.
     */
    void applyForce(const Force &f);

    /*
     * DESCRIPTION:
     *      Check if ball is out of bounds of the screen and applies a force
     *      to bring it back in.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid ball object exists.
     * POSTCONDITION:
     *      The ball has a force applied and is shifted back into the play area.
     */
    void outOfBounds();

    /*
     * DESCRIPTION:
     *      Check if there is a collision between two balls.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid ball object exists and is provided.
     * POSTCONDITION:
     *      Both ball objects are reflected off each other if there is a
     *      collision identified.
     */
    void collisionCheck(Ball &ballCheck);

    /*
     * DESCRIPTION:
     *      Check if there is a collision between the current ball and a
     *      brick object.
     * RETURN:
     *      bool
     * PRECONDITION:
     *      A valid brick object is provided.
     * POSTCONDITION:
     *      If a collision is identified then the ball is collided off the
     *      brick and true is returned.
     */
    bool collisionCheck(Brick &b2);

    /*
     * DESCRIPTION:
     *     Steps ball back by one pixel.
     * RETURN:
     *      Void
     * PRECONDITION:
     *      A valid ball object exists.
     * POSTCONDITION:
     *      The ball is moved back by one pixel in the opposite direction of
     *      its current direction.
     */
    void stepBack(Ball &ballCheck);
};

#endif //FALLINGBALLS_BALL_H
