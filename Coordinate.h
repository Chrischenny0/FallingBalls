//
// Created by cripp on 10/18/2021.
//

#ifndef CL10_18_2021_POINT_H
#define CL10_18_2021_POINT_H

#include <cmath>
using namespace std;

struct Coordinate{
    double x, y;
    Coordinate(double x, double);
    double distance(Coordinate other)const;
};
#endif //CL10_18_2021_POINT_H
