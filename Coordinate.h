//
// Created by cripp on 10/18/2021.
//

#ifndef CL10_18_2021_POINT_H
#define CL10_18_2021_POINT_H

#include <cmath>
using namespace std;

struct Coordinate{
    //Variables
    double x, y;

    //Constructor
    Coordinate(double x, double y);

    //Functions
    double distance(const Coordinate& other) const;
    double delta(const Coordinate& other) const;
};
#endif //CL10_18_2021_POINT_H
