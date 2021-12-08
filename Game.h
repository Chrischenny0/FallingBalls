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
    vector<BMPImage*> characters;
    vector<BMPImage*> numbers;

    //Game Masks
    BMPImage *ballMask, *background, *brickMask;

    //Game Variables
    int score = 0;
    bool dead = false;

    //Game Objects
    Font *currentScore;

    vector<Ball*> balls;
    vector<Ball*> liveBalls;
    vector<Brick*> bricks;

    int x, y;



public:
    Game();

    void startUp();

    void startGame();

    void waitClick();

    void gameGoing();

    void incrementGame();

    void end();

    void end_tick();

    bool isRunning();

    bool endGame();

};


#endif //FALLINGBALLS_GAME_H
