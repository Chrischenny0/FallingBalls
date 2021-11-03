#include "BMPImage.h"

BMPImage::BMPImage(const string& name, int x, int y): pos(x, y) {
    this -> name = name;

    ifstream input;
    ifstream dataSizes;
    ofstream binary;

    unsigned char newByte;
    int dataL;

    vector<string> rawBinary;
    vector<string> headerData;

    vector<int> byteType;

    vector<vector<unsigned char>> RGBTemp;
    vector<unsigned char> RGBRowTemp;

    dataSizes.open("byteRanges.txt");
    assert(dataSizes.is_open());

    while(dataSizes >> dataL){
        byteType.push_back(dataL);
    }
    dataSizes.close();

    input.open(name, fstream::binary);
    assert(input.is_open());

    input >> noskipws;

    for(int i = 0; input >> newByte && i < byteType.at(byteType.size()-1); i++){
        rawBinary.push_back(bitset<8>(newByte).to_string());
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
    /*for(int i = 0; i < headerData.size()-4; i++){
        cout << i+1 << ": " << byteType.at(i) << ": " << stoi(headerData.at(i), 0, 2) << endl;
    }*/

    this -> sizeX = stoi(headerData.at(6), 0, 2);
    this -> sizeY = stoi(headerData.at(7), 0, 2);

    cout << sizeX << endl;
    cout << sizeY << endl;

    int remain = 0;
    if(sizeX % 4 != 0){
        remain = 4 - sizeX % 4;
    }

    rawBinary.clear();
    input.seekg(stoi(headerData.at(4), 0, 2));

    pixelByte = (stoi(headerData.at(5), 0, 2) == 40)? 3: 4;
    this -> alpha = (pixelByte == 4);

    for(int j = 0; j < sizeY; j++){
        for(int i = 0; i < sizeX * pixelByte + remain; i++){

            input >> newByte;
            if(sizeX * pixelByte - i > 0){
                RGBRowTemp.push_back(newByte);
            }
        }
        RGBTemp.push_back(RGBRowTemp);
        RGBRowTemp.clear();
    }
    input.close();

    this -> RGB = RGBTemp;
}

int BMPImage::getsizeX() const{
    return sizeX;
}
int BMPImage::getsizeY() const{
    return sizeY;
}
const vector<vector<unsigned char>>& BMPImage::getRGB() const{
    return RGB;
}

void BMPImage::draw(SDLWrapper &g, int newX, int newY){
    vector<unsigned char> temp;
    pos.x = newX;
    pos.y = newY;

    for(int i = 0; i < sizeY; i++){
        for(int j = 0; j < sizeX; j++){
            if(!alpha || RGB.at(i).at(j * pixelByte + 3)){
                g.drawPixel(pos.x + j, pos.y + i,
                            RGB.at(i).at(j * pixelByte + 2),
                            RGB.at(i).at(j * pixelByte + 1),
                            RGB.at(i).at(j * pixelByte));


            }
        }
    }
}

void BMPImage::setBackground(SDLWrapper &g){
    g.setBackground(RGB);
    draw(g, 0, 0);
}

void BMPImage::redrawBkG(SDLWrapper &g) {
    g.redrawBkG(pos.x, pos.y, sizeX, sizeY);
}


