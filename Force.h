#ifndef FALLINGBALLS_FORCE_H
#define FALLINGBALLS_FORCE_H

#include <cmath>
#include <iostream>

using namespace std;
const double PI = 3.14159265359;

using namespace std;

class Force {
private:
    double magnitude;
    double direction; //radians


public:
    Force();                   //default constructor
    Force(double m, double d); //Passed mag and dir constructor
    void apply(const Force &);  //Apply force to current force
    void redirect(int dir);

    void setMag(double m) {
        magnitude = m;
    }

    void setDir(double d) {
        direction = d;
    }

    double getMag() const {
        return magnitude;
    }

    double getDir() const {
        return direction;
    }

    void normalize();
};


const Force Gravity(0.02, -(PI / 2));
#endif //FALLINGBALLS_FORCE_H
