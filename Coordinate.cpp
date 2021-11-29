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
