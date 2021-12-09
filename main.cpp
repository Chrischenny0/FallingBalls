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
#include "Game.h"

int main(int argc, char **argv) {

    Game game;

    game.startUp();
    game.startGame();

    while(!game.endGame() && game.isRunning()){
        game.waitClick();
        game.gameGoing();
        game.incrementGame();
    }

    return 0;
}