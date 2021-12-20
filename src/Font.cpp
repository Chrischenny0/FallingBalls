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
#include "Font.h"

Font::Font(SDLWrapper &, Coordinate lowerLeft, vector<BMPImage *> &characters,
           vector<BMPImage *> &numbers, bool centered) : lowerLeft(lowerLeft) {
    this->characters = &characters;
    this->numbers = &numbers;
    this->centered = centered;
}

void Font::setLocation(Coordinate newCord) {
    lowerLeft = newCord;
}

void Font::setMessage(const string &newMessage) {
    length = 0;
    message.clear();
    for (int i = 0; i < newMessage.size(); i++) {
        message.push_back(toupper(newMessage.at(i)));
        length += getCharLength(toupper(newMessage.at(i)));
    }
}

void Font::draw() {
    int previousChars = 0;
    Coordinate tmp = lowerLeft;
    if (centered) {
        lowerLeft.x -= length / 2;
        lowerLeft.y -= 16;
    }
    for (int i = 0; i < message.size(); i++) {
        if (message.at(i) >= 65) {
            characters->at(message.at(i) - 65)->draw(
                    Coordinate(lowerLeft.x + previousChars, lowerLeft.y),
                    Coordinate(0, 0));
            previousChars +=
                    characters->at(message.at(i) - 65)->getSizeX() + 1;
        } else if (message.at(i) == ' ') {
            previousChars += 20;
        } else {
            numbers->at(message.at(i) - 48)->draw(
                    Coordinate(lowerLeft.x + previousChars, lowerLeft.y),
                    Coordinate(0, 0));
            previousChars +=
                    characters->at(message.at(i) - 48)->getSizeX() + 1;
        }
    }
    lowerLeft = tmp;
}

int Font::getCharLength(char a) {
    int width;
    if (a >= 65) {
        width = characters->at(a - 65)->getSizeX();
    } else if (a >= 48) {
        width = numbers->at(a - 48)->getSizeX();
    } else {
        width = 20;
    }
    return width;
}