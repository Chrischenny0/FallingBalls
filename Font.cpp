#include "Font.h"

Font::Font(SDLWrapper &, Coordinate lowerLeft, vector<BMPImage *> &characters, vector<BMPImage *> &numbers,
           bool centered) : lowerLeft(lowerLeft){
    this -> characters = &characters;
    this -> numbers = &numbers;
    this -> centered = centered;
}

Coordinate Font::getLocation(){
    return lowerLeft;
}

void Font::setLocation(Coordinate newCord) {
    lowerLeft = newCord;
}

void Font::setMessage(const string& newMessage) {
    length = 0;
    message.clear();
    for(int i = 0; i < newMessage.size(); i++){
        message.push_back(toupper(newMessage.at(i)));
        length += getCharLength(toupper(newMessage.at(i)));
    }
}

void Font::draw() {
    int previousChars = 0;
    Coordinate tmp = lowerLeft;
    if(centered){
        lowerLeft.x -= length / 2;
        lowerLeft.y -= 16;
    }
    for(int i = 0; i < message.size(); i++){
        if(message.at(i) >= 65){
            characters -> at(message.at(i) - 65)->draw(Coordinate(lowerLeft.x + previousChars, lowerLeft.y),
                                                       Coordinate(0, 0));
            previousChars += characters -> at(message.at(i) - 65 ) -> getSizeX() + 1;
        }
        else if(message.at(i) == ' '){
            previousChars += 20;
        }
        else{
            numbers -> at(message.at(i) - 48)->draw(Coordinate(lowerLeft.x + previousChars, lowerLeft.y),
                                                    Coordinate(0, 0));
            previousChars += characters -> at(message.at(i) - 48 ) -> getSizeX() + 1;
        }
    }
    lowerLeft = tmp;
}

void Font::getMessage(string &strMessage) {
    for(int i = 0; i < message.size(); i++){
        strMessage += message.at(i);
    }
}

int Font::getCharLength(char a) {
    int width;
    if(a >= 65){
        width = characters -> at(a - 65)->getSizeX();
    }
    else if (a >= 48){
        width = numbers -> at(a - 48)->getSizeX();
    }
    else{
        width = 20;
    }
    return width;
}

void Font::append(char newChar, SDLWrapper &g) { //fix it so that it redraw the area behind the letter
    if(newChar == 0 && message.size() != 0){
        /*char deleteChar = message.at(message.size() - 1);
        if(deleteChar != ' '){
            BMPImage *letter = (deleteChar >= 65)? characters -> at(deleteChar - 65) : numbers -> at(newChar - 48);
            g.redrawBkG(lowerLeft.x + length - letter -> getSizeX() + 1, lowerLeft.y, letter -> getRGB());
        }
        length -= getCharLength(deleteChar);
        message.pop_back();*/
        g.redrawBkG(lowerLeft, Coordinate(lowerLeft.x + length, lowerLeft.y + 30));
        message.pop_back();
        draw();
    }
    else if(newChar != 0){
        length += getCharLength(newChar);
        message.push_back(newChar);
    }
}


