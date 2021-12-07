#include "BMPImage.h"

BMPImage::BMPImage(const string &name, int x, int y, SDLWrapper &g) : pos(x, y),
                                                                      g(g) {
    this->name = name;

    ifstream input;
    ifstream dataSizes;

    unsigned char newByte;
    int dataL;

    vector<string> rawBinary;
    vector<string> headerData;

    vector<int> byteType;

    vector<vector<vector<unsigned char>>> RGBTemp;
    vector<vector<unsigned char>> RGBRowTemp;
    vector<unsigned char> pixelTemp;

    dataSizes.open("byteRanges.txt");
    assert(dataSizes.is_open());

    while (dataSizes >> dataL) {
        byteType.push_back(dataL);
    }
    dataSizes.close();

    input.open(name, fstream::binary);
    assert(input.is_open());

    input >> noskipws;

    for (int i = 0;
         input >> newByte && i < byteType.at(byteType.size() - 1); i++) {
        rawBinary.push_back(bitset<8>(newByte).to_string());
    }

    for (int i = 0; i < byteType.size() - 1; i++) {
        int range = byteType.at(i + 1) - byteType.at(i);
        if (range > 1) {
            for (int j = 0; j < range / 2; j++) {
                swap(rawBinary.at(byteType.at(i) + j),
                     rawBinary.at(byteType.at(i + 1) - j - 1));
            }
        }
    }


    for (int i = 0; i < byteType.size() - 1; i++) {
        int range = byteType.at(i + 1) - byteType.at(i);
        headerData.push_back(rawBinary.at(byteType.at(i)));
        if (range > 1) {
            for (int j = 1; j < range; j++) {
                headerData.at(i).append(rawBinary.at(byteType.at(i) + j));
            }
        }
    }

    this->sizeX = stoi(headerData.at(6), 0, 2);
    this->sizeY = stoi(headerData.at(7), 0, 2);

    rawBinary.clear();
    input.seekg(stoi(headerData.at(4), 0, 2));

    cout << stoi(headerData.at(9), 0, 2) << endl;
    pixelByte = (stoi(headerData.at(9), 0, 2) == 24) ? 3 : 4;
    this->alpha = (pixelByte == 4);

    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            for (int k = 0; k < pixelByte; k++) {
                input >> newByte;
                pixelTemp.push_back(newByte);
            }
            RGBRowTemp.push_back(pixelTemp);
            pixelTemp.clear();
        }
        RGBTemp.push_back(RGBRowTemp);
        RGBRowTemp.clear();
    }
    input.close();

    this->RGB = RGBTemp;
}

Coordinate BMPImage::getPosition() const {
    return pos;
}

void BMPImage::setPosition(const Coordinate &newPosition) {
    pos = newPosition;
}

const vector<vector<vector<unsigned char>>> &BMPImage::getRGB() const {
    return RGB;
}

void BMPImage::draw(const Coordinate &corner) {

    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (!alpha || RGB.at(i).at(j).at(3) == 255) {
                g.drawPixel(corner.x + j, corner.y + i,
                            RGB.at(i).at(j).at(2),
                            RGB.at(i).at(j).at(1),
                            RGB.at(i).at(j).at(0));
            }
        }
    }
}

void BMPImage::setBackground() {
    g.setBackground(RGB);
    draw(Coordinate(0,0));
}

void BMPImage::redrawBkG(const Coordinate &position) {
    g.redrawBkG(position.x, position.y, RGB);
}

int BMPImage::getSizeX() const {
    return sizeX;
}

int BMPImage::getSizeY() const {
    return sizeY;
}



