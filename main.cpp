#include "Game.h"
#include <thread>

using namespace std;

int main(int argc, char **argv) {

    Game game;

    game.startUp();

    game.getName();

    game.startGame();

    while(!game.endGame() && game.isRunning()){
        game.waitClick();
        game.gameGoing();
        game.incrementGame();
    }
    game.end();
    while(!game.endGame()){
        game.end_tick();
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}