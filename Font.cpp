#include "Font.h"

Font::Font(SDLWrapper &g, Coordinate lowerLeft) : lowerLeft(lowerLeft) {
    string fileName;
    for (int i = 0; i < 26; i++) {
        fileName = "Fonts/";
        fileName += char('A' + i);
        fileName += ".bmp";
        characters.emplace_back(new BMPImage(fileName, 0, 0, g));
    }

    for (int i = 0; i < 10; i++) {
        fileName = "Fonts/";
        fileName += char('0' + i);
        fileName += ".bmp";
        numbers.emplace_back(new BMPImage(fileName, 0, 0, g));
    }
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
            characters.at(message.at(i) - 65 ) -> draw(Coordinate(lowerLeft.x + previousChars, lowerLeft.y));
            previousChars += characters.at(message.at(i) - 65 ) -> getSizeX() + 1;
        }
        else{
            numbers.at(message.at(i) - 48) -> draw(Coordinate(lowerLeft.x + previousChars, lowerLeft.y));
            previousChars += characters.at(message.at(i) - 48 ) -> getSizeX() + 1;
        }
    }
}
