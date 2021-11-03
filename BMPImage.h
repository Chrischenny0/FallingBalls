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
#include "Coordinate.h"
using namespace std;

class BMPImage{
    private:
        //Image Info
        Coordinate pos;
        int sizeX, sizeY, pixelByte;
        string name;
        bool alpha;

        //Pixel vectors
        vector<vector<unsigned char>> RGB;
    public:
        //Constructor
        BMPImage(const string& name, int x, int y);

        //Getters
        int getsizeX() const;
        int getsizeY() const;
        const vector<vector<unsigned char>>& getRGB() const;

        //SDL_Plotter Functions
        void draw(SDLWrapper &g, int newX, int newY);
        void redrawBkG(SDLWrapper &g);
        void setBackground(SDLWrapper &g);


};

vector<vector<unsigned char>> vectBMP();
#endif //CL10_18_2021_BMPTRANSFER_H
