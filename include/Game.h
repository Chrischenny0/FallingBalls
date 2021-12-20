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
#ifndef FALLINGBALLS_GAME_H
#define FALLINGBALLS_GAME_H

#include <sstream>
#include "Ball.h"
#include "Font.h"

using namespace std;

class Game {
private:
    //SDL Wrapper Arguments
    int disWidth = 1200;
    int disLength = 950;
    Coordinate lowerBound, upperBound; //750 x 900
    SDLWrapper g;
    bool gameEnded = false;

    //Font Class Images
    vector<BMPImage *> characters;
    vector<BMPImage *> numbers;

    //Game Masks
    BMPImage *ballMask, *background, *brickMask;

    //Game Variables
    int score = 0;
    bool dead = false;

    //Game Objects
    Font *currentScore;

    vector<Ball *> balls;
    vector<Ball *> liveBalls;
    vector<Brick *> bricks;

    int x, y;


public:
    /*
     * DESCRIPTION:
     *      Default constructor for the game class
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      The necessary file dependencies are available.
     * POSTCONDITION:
     *      A game class is created.
     */
    Game();

    /*
     * DESCRIPTION:
     *      Starting up the game by loading the font and game sound into
     *      their respective classes.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid game class exists.
     * POSTCONDITION:
     *      All font characters are loaded into memory and the ball sounded
     *      is loaded into the SDL Plotter.
     */
    void startUp();

    /*
     * DESCRIPTION:
     *      Starts the game by loading in the ball image, brick image, and
     *      drawing their respective elements to the screen.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid game class exists.
     * POSTCONDITION:
     *      All graphics are loaded into their respective classes and the
     *      initial ball and bricks are drawn.
     */
    void startGame();

    /*
     * DESCRIPTION:
     *      Waiting for user click input.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid game class exists.
     * POSTCONDITION:
     *     The game waits for the user click input on the screen and captures
     *     the location of the click.
     */
    void waitClick();

    /*
     * DESCRIPTION:
     *      Game proceeds without any user interaction. Balls are directed in
     *      the direction specified by the user.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid game class exists.
     * POSTCONDITION:
     *      The balls are thrown in the direction from the user and all
     *      collisions are detected.
     */
    void gameGoing();

    /*
     * DESCRIPTION:
     *      Once all balls have left the screen the game increments up by one.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid game class exists.
     * POSTCONDITION:
     *      The game count increments by one and the game resets the game field.
     */
    void incrementGame();

    /*
     * DESCRIPTION:
     *      Check for if all balls have left the screen.
     * RETURN:
     *      bool
     * PRECONDITION:
     *      A valid game class exists.
     * POSTCONDITION:
     *      If all balls have left the screen then false is returned,
     *      otherwise true.
     */
    bool isRunning();

    /*
     * DESCRIPTION:
     *      Check for if the game has finished. IE the bricks have reached
     *      the top of the screen.
     * RETURN:
     *      bool
     * PRECONDITION:
     *      A valid game class exists.
     * POSTCONDITION:
     *      If the bricks have reached the top of the screen then false is
     *      returned, otherwise true.
     */
    bool endGame();
};


#endif //FALLINGBALLS_GAME_H
