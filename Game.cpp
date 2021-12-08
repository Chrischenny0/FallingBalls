#include "Game.h"

Game::Game() : lowerBound(15, 25), upperBound(765, 925), g(disWidth, disLength, false) {
    ballMask = brickMask = nullptr;
    currentScore = nullptr;
    background = new BMPImage("images/BackgroundFinal.bmp", 0, 0, g, false);
}

void Game::startUp() {
    background->setBackground();

    string fileName;

    for (int i = 0; i < 26; i++) {
        fileName = "Fonts/";
        fileName += char('a' + i);
        fileName += ".bmp";
        characters.emplace_back(new BMPImage(fileName, 0, 0, g, false));
    }

    for (int i = 0; i < 10; i++) {
        fileName = "Fonts/";
        fileName += char('0' + i);
        fileName += ".bmp";
        numbers.emplace_back(new BMPImage(fileName, 0, 0, g, false));
    }
    g.setSound("Sounds/hitSound.mp3");

    g.update();
}


void Game::startGame() {
    string temp;

    vector<int> indexes{0, 1, 2, 3, 4};
    background = new BMPImage("images/BackgroundFinal.bmp", 0, 0, g, false);
    ballMask = new BMPImage("images/BallV2.bmp", 0, 0, g, true);
    brickMask = new BMPImage("images/BrickV3.bmp", 0, 0, g, true);

    currentScore = new Font(g, Coordinate(985, 725), characters, numbers, true);
    background->setBackground();

    currentScore->setMessage("0");

    currentScore->draw();

    for (int i = 0; i < 3; i++) {
        balls.push_back(new Ball(Coordinate(390, 880), ballMask, g, lowerBound, upperBound));
    }

    srand(time(0));
    for (int i = 0; i < rand() % 3 + 2; i++) {
        int randIndex = rand() % indexes.size();
        int j = indexes.at(randIndex);
        indexes.erase(indexes.begin() + randIndex);
        Font *tmp = new Font(g, Coordinate(40 + 150 * j + 50, 60 + 23), characters, numbers, true);
        bricks.push_back(new Brick(40 + 150 * j, 60, brickMask, g, tmp, 3));
    }
}

void Game::waitClick() {
    bool mouseClicked = false;

    for (int i = 0; i < bricks.size(); i++) {
        bricks.at(i)->drawBrick();
    }

    balls.at(0)->drawBall();

    g.update();


    while (!mouseClicked && !g.getQuit()) {

        if (g.kbhit()) {
            g.getKey();
        }
        if (g.getMouseClick(x, y)) {
            y = disLength - y;
            mouseClicked = true;
        }
    }
}

void Game::gameGoing() {
    bool allBallsGone = false;
    unsigned int tickCount = 1, index = 1;
    liveBalls.clear();

    double direction = atan(balls.at(0)->getCoords().slope(Coordinate(x, y)));

    if (direction > 0) {
        direction += PI;
    }


    for (int i = 0; i < balls.size(); i++) {
        balls.at(i)->setMagDir(Force(15, direction));
    }

    liveBalls.push_back(balls.at(0));

    for (int i = 0; i < bricks.size(); i++) {
        bricks.at(i)->drawBrick();
    }

    while (!allBallsGone && !g.getQuit()) {

        if (liveBalls.size() < balls.size() && tickCount % 90 == 0) {
            liveBalls.push_back(balls.at(index));
            index++;
        }

        //Draw objects
        for (int i = 0; i < liveBalls.size(); i++) {
            liveBalls.at(i)->drawBall();
            liveBalls.at(i)->applyForce(Gravity);
            liveBalls.at(i)->moveBall();
            liveBalls.at(i)->outOfBounds();
        }

        int below = 0;

        for (int i = 0; i < liveBalls.size(); i++) {
            for (int j = 0; j < liveBalls.size(); j++) {
                if (i != j) {
                    liveBalls.at(i)->collisionCheck(*balls.at(j));
                }
            }
            for (int j = bricks.size() - 1; j >= 0; j--) {
                if (liveBalls.at(i)->collisionCheck(*bricks.at(j))) {
                    g.startSound("Sounds/hitSound.mp3");
                    bricks.at(j)->drawBrick();
                    if (bricks.at(j)->getColCount() <= 0) {
                        bricks.at(j)->redrawBackground();
                        delete bricks.at(j);
                        bricks.erase(bricks.begin() + j);
                    }
                }
            }

            if (liveBalls.at(i)->getCoords().y < 0) {
                below++;
            }
            if (below == liveBalls.size()) {
                allBallsGone = true;
            }
        }
        tickCount++;

        if (g.kbhit()) {
            g.getKey();
        }
        if (g.getMouseClick(x, y)) {
            y = disLength - y;
        }
        g.update();
    }
}

void Game::incrementGame() {
    srand(time(0));
    if (!gameEnded) {
        vector<int> indexes{0, 1, 2, 3, 4};
        string currHighscore;
        score++;

        currentScore->setMessage(to_string(score));

        background->redrawBkG(Coordinate(0, 0));


        currentScore->draw();

        for (int i = 0; i < balls.size(); i++) {
            balls.at(i)->resetCenter();
        }
        for (int i = 0; i < rand() % 3 + 2; i++) {
            int randIndex = rand() % indexes.size();
            int j = indexes.at(randIndex);
            indexes.erase(indexes.begin() + randIndex);
            Font *tmp = new Font(g, Coordinate(40 + 150 * j + 50, 31), characters, numbers, true);
            bricks.push_back(new Brick(40 + 150 * j, -15, brickMask, g, tmp, 3 + score / 2));
        }
        for (int i = 0; i < bricks.size(); i++) {
            bricks.at(i)->moveBrick();
            if (bricks.at(i)->getCenter().y >= 907) {
                dead = true;
            }
            bricks.at(i)->drawBrick();

            if (g.kbhit()) {
                g.getKey();
            }
            if (g.getMouseClick(x, y)) {
            }

        }
        g.update();
    }
}

bool Game::endGame() {
    if (!gameEnded) {
        if (g.getQuit()) {
            gameEnded = true;
        }
    }
    return gameEnded;
}


bool Game::isRunning() {
    return !dead;
}


