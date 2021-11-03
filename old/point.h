//
// Created by cripp on 10/18/2021.
//

#ifndef CL10_18_2021_POINT_H
#define CL10_18_2021_POINT_H

#include <cmath>
using namespace std;

struct point_t{
    double x, y;
    point_t(double x = 0, double y = 0);
    double distance(point_t other)const;
};
#endif //CL10_18_2021_POINT_H
