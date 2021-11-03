#include "BMPTransfer.h"

image::image(const string& name, int posX, int posY) {

    this -> name = name;
    this -> posX = posX;
    this -> posY = posY;

    ifstream input;
    ifstream dataSizes;
    ofstream binary;

    unsigned char newByte;
    int dataL;
    int arrayShift;


    vector<string> rawBinary;
    vector<string> headerData;

    vector<int> byteType;

    vector<vector<unsigned char>> RGBTemp;
    vector<unsigned char> RGBRowTemp;


    input.open(name, fstream::binary);
    assert(input.is_open());

    input >> noskipws;

    for(int i = 0; input >> newByte && i < 76; i++){
        rawBinary.push_back(bitset<8>(newByte).to_string());
    }

    dataSizes.open("byteRanges.txt");
    assert(dataSizes.is_open());
    while(dataSizes >> dataL){
        byteType.push_back(dataL);
    }

    for(int i = 0; i < byteType.size() - 1; i++){
        int range = byteType.at(i+1) - byteType.at(i);
        if(range > 1){
            for(int j = 0; j < range/2; j++){
                swap(rawBinary.at(byteType.at(i) + j),
                     rawBinary.at(byteType.at(i + 1) - j - 1));
            }
        }
    }

    for(int i = 0; i < byteType.size() -1; i++){
        int range = byteType.at(i+1) - byteType.at(i);
        headerData.push_back(rawBinary.at(byteType.at(i)));
        if(range > 1){
            for(int j = 1; j < range; j++){
                headerData.at(i).append(rawBinary.at(byteType.at(i) + j));
            }
        }
    }


    this -> sizeX = stoi(headerData.at(6), 0, 2);
    this -> sizeY = stoi(headerData.at(7), 0, 2);

    assert(stoi(headerData.at(5), 0, 2) == 40);
    assert(stoi(headerData.at(9), 0, 2) == 24);
    assert(stoi(headerData.at(10), 0, 2) == 0);
    assert(stoi(headerData.at(11), 0, 2) == 0);

    int remain = 0;
    if(sizeX % 4 != 0){
        remain = 4 - sizeX % 4;
    }

    rawBinary.clear();
    input.seekg(stoi(headerData.at(4), 0, 2));

    for(int j = 0; j < sizeY; j++){
        for(int i = 0; i < sizeX * 3 + remain; i++){

            input >> newByte;
            if(sizeX * 3 - i > 0){
                RGBRowTemp.push_back(newByte);
            }
        }
        RGBTemp.push_back(RGBRowTemp);
        RGBRowTemp.clear();
    }

    this -> RGB = RGBTemp;
}

int image::getposX() const{
    return posX;
}
int image::getposY() const{
    return posY;
}
int image::getsizeX() const{
    return sizeX;
}
int image::getsizeY() const{
    return sizeY;
}
const vector<vector<unsigned char>>& image::getRGB() const{
    return RGB;
}

