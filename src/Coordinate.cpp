/*
 * AUTHOR: Christopher Chenoweth, Katie Boatwright, Luke Smith,
 *    Preston Witschonke, Shepard Berry
 * ASSIGNMENT TITLE: Falling Balls
 * ASSIGNMENT DESCRIPTION:
 *      Create a version of the game falling balls.
 * DUE DATE: 12/08/2021
 * DATE CREATED: 11/03/2021
 * DATE LAST MODIFIED: 12/08/2021
 */
#include "Coordinate.h"
#include <cmath>

using namespace std;

Coordinate::Coordinate(double x, double y) {
    this->x = x;
    this->y = y;
}

double Coordinate::distance(const Coordinate &other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));

}

double Coordinate::delta(const Coordinate &other) const {
    return (x - other.x) + (y - other.y);
}

double Coordinate::slope(const Coordinate &other) const {
    return static_cast<double>(other.y - y) / static_cast<double>(other.x - x);
}

bool Coordinate::operator<(const Coordinate &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    return y < rhs.y;
}

bool Coordinate::operator>(const Coordinate &rhs) const {
    return rhs < *this;
}

bool Coordinate::operator>=(const Coordinate &rhs) const {
    return !(*this < rhs);
}

Coordinate Coordinate::adjust(double adj) const {
    return Coordinate(x + adj, y + adj);
}

