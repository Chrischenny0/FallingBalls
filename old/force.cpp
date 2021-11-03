#include "force.h"


force::force(){
    magnitude = 0;
    direction = 0;
}
force::force(double m, double d){
    magnitude = m;
    direction = d;
}
void force::apply(const force& f){
    force r   = add(f);
    magnitude = r.magnitude;
    direction = r.direction;
}

force force::add(const force& f) const{
    force r(magnitude, direction);
    double ax, ay, bx, by;

    ax = magnitude * cos(direction);
    ay = magnitude * sin(direction);

    bx = f.magnitude * cos(f.direction);
    by = f.magnitude * sin(f.direction);

    r.magnitude = sqrt(pow(ax+bx, 2) + pow(ay+by, 2));

    r.direction = atan((ay+by)/(ax+bx));
    return r;
}

force force::operator+ (const force& f) const{
    return add(f);
}