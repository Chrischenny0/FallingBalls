#include "Font.h"

Font::Font(SDLWrapper &g, Coordinate lowerLeft, vector<BMPImage *> &characters,
           vector<BMPImage *> &numbers) : lowerLeft(lowerLeft){
    this -> characters = &characters;
    this -> numbers = &numbers;
}

void Font::setLocation(Coordinate newCord) {
    lowerLeft = newCord;
}

void Font::setMessage(const string& newMessage) {
    messageStr = newMessage;
    for(int i = 0; i < messageStr.size(); i++){
        message.push_back(toupper(messageStr.at(i)));
    }
}

void Font::draw() {
    int previousChars = 0;
    for(int i = 0; i < message.size(); i++){
        if(message.at(i) >= 65){
            characters -> at(message.at(i) - 65)->draw(Coordinate(lowerLeft.x + previousChars, lowerLeft.y),
                                                    Coordinate(0, 0));
            previousChars += characters -> at(message.at(i) - 65 ) -> getSizeX() + 1;
        }
        else{
            numbers -> at(message.at(i) - 48)->draw(Coordinate(lowerLeft.x + previousChars, lowerLeft.y),
                                                 Coordinate(0, 0));
            previousChars += characters -> at(message.at(i) - 48 ) -> getSizeX() + 1;
        }
    }
}
