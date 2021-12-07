#ifndef FALLINGBALLS_FONT_H
#define FALLINGBALLS_FONT_H

#include "BMPImage.h"

class Font {
private:
    vector<BMPImage*>* characters;
    vector<BMPImage*>* numbers;

    vector<int> message;

    Coordinate lowerLeft;

    string messageStr;

public:
    Font(SDLWrapper &, Coordinate lowerLeft, vector<BMPImage *> &characters,
         vector<BMPImage *> &numbers);

    void setLocation(Coordinate);

    void setMessage(const string&);

    void draw();
};


#endif //FALLINGBALLS_FONT_H
