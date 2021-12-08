#ifndef FALLINGBALLS_FONT_H
#define FALLINGBALLS_FONT_H

#include "BMPImage.h"

class Font {
private:
    vector<BMPImage*>* characters;
    vector<BMPImage*>* numbers;

    vector<int> message;

    Coordinate lowerLeft;
    bool centered;

    int length = 0;

public:
    Font(SDLWrapper &, Coordinate lowerLeft, vector<BMPImage *> &characters, vector<BMPImage *> &numbers,
         bool centered = false);

    Coordinate getLocation();
    void setLocation(Coordinate);

    void setMessage(const string&);

    void getMessage(string &);

    int getCharLength(char);

    void append(char newChar, SDLWrapper &);

    void draw();
};


#endif //FALLINGBALLS_FONT_H
