#include "Force.h"


Force::Force(){
    magnitude = 0;
    direction = 0;
}
Force::Force(double m, double d){
    magnitude = m;
    direction = d;
}
void Force::apply(const Force& f){
    double ax, ay, bx, by;

    ax = magnitude * cos(direction);
    ay = magnitude * sin(direction);

    bx = f.magnitude * cos(f.direction);
    by = f.magnitude * sin(f.direction);

    magnitude = sqrt(pow(ax+bx, 2) + pow(ay+by, 2));

    direction = atan((ay+by)/(ax+bx));
}

Force Force::add(const Force& f) const{
    Force r(magnitude, direction);
    double ax, ay, bx, by;

    ax = magnitude * cos(direction);
    ay = magnitude * sin(direction);

    bx = f.magnitude * cos(f.direction);
    by = f.magnitude * sin(f.direction);

    r.magnitude = sqrt(pow(ax+bx, 2) + pow(ay+by, 2));

    r.direction = atan((ay+by)/(ax+bx));
    return r;
}

void Force::redirect(int dir) {
    if(dir == 0){
        direction *= -1;
    }
    if(dir == -1){
        direction = PI - direction;
    }
    magnitude *= 3;
}

Force Force::operator+ (const Force& f) const{
    return add(f);
}


