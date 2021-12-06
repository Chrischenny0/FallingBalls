//
// Created by cripp on 10/29/2021.
//

#ifndef CL10_18_2021_BMPTRANSFER_H
#define CL10_18_2021_BMPTRANSFER_H

#include <iostream>
#include <iterator>
#include <fstream>
#include <bitset>
#include <vector>
#include <cassert>
#include "SDLWrapper.h"

using namespace std;

class BMPImage {
private:
    //Image Info
    Coordinate pos;
    int sizeX, sizeY, pixelByte;
    string name;
    bool alpha;

    //
    SDLWrapper &g;

    //Pixel vectors
    vector<vector<vector<unsigned char>>> RGB;
public:
    //Constructor
    BMPImage(const string &name, int x, int y, SDLWrapper &g);

    //Setters
    void setPosition(const Coordinate &);

    //Getters
    int getSizeX() const;

    int getSizeY() const;

    Coordinate getPosition() const;

    const vector<vector<vector<unsigned char>>> &getRGB() const;

    //SDL_Plotter Functions
    void draw(int newX, int newY);

    void redrawBkG(const Coordinate &position,
                   const vector<vector<vector<unsigned char>>> &mask);

    void setBackground();


};

#endif //CL10_18_2021_BMPTRANSFER_H
