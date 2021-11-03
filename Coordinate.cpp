#include "Coordinate.h"
#include <cmath>

using namespace std;
Coordinate::Coordinate(double x, double y){
    this -> x = x;
    this -> y = y;
}
double Coordinate::distance(Coordinate other)const{
    return sqrt(pow(x-other.x, 2) + pow(y-other.y, 2));

}
