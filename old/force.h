//
// Created by cripp on 10/18/2021.
//

#ifndef CL10_18_2021_FORCE_H
#define CL10_18_2021_FORCE_H
#include <cmath>
#include <ostream>

const double PI = 3.14159;

using namespace std;
class force{
    private:
        double magnitude;
        double direction; //radians


    public:
        force(); //default constructor
        force(double m, double d); //Passed mag and dir constructor
        void apply(const force&); //Apply force to current force
        force add(const force&) const;

        void setMagnitude(double m){
            magnitude = m;
        }
        void setDirection(double d){
            direction = d;
        }
        double getMagnitude() const{
            return magnitude;
        }
        double getDirection() const{
            return direction;
        }

        force operator+(const force&) const;
        void display(ostream& out){
            out << "mag = " << magnitude << endl;
            out << "dir = " << direction << endl;
        }
};


const force Gravity(0.04, PI/2);
#endif //CL10_18_2021_FORCE_H
