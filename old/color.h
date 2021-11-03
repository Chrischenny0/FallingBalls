//
// Created by cripp on 10/18/2021.
//

#ifndef CL10_18_2021_COLOR_H
#define CL10_18_2021_COLOR_H


struct color_t{
    int R, G, B;

    color_t(){
        R = G = B = 0;
    }
    color_t(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }
};

const color_t RED(220, 20, 20);
//const color_t WHITE(255, 255, 255);

#endif //CL10_18_2021_COLOR_H
