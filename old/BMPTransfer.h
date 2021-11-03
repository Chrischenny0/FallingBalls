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
using namespace std;

class image{
    private:
        vector<vector<unsigned char>> RGB;
        int posX, posY, sizeX, sizeY;
        string name;
    public:
        image(const string& name, int posX, int posY);
        int getposX() const;
        int getposY() const;
        int getsizeX() const;
        int getsizeY() const;

        const vector<vector<unsigned char>>& getRGB() const;

};

vector<vector<unsigned char>> vectBMP();
#endif //CL10_18_2021_BMPTRANSFER_H
