#include "Force.h"


Force::Force() {
    magnitude = 0.8;
    direction = PI / 5;
}

Force::Force(double m, double d) {
    magnitude = m;
    direction = d;
}

void Force::apply(const Force &f) {
    double ax, ay, bx, by;

    ax = magnitude * cos(direction);
    ay = magnitude * sin(direction);

    bx = f.magnitude * cos(f.direction);
    by = f.magnitude * sin(f.direction);

    magnitude = sqrt(pow(ax + bx, 2) + pow(ay + by, 2));

    direction = atan((ay + by) / (ax + bx));
    if ((ay + by) < 0 && direction > 0) direction += PI;
    if ((ay + by) > 0 && direction < 0) direction += PI;
}

void Force::redirect(int dir) {
    if (dir == 0) {
        direction *= -1;
    }
    if (dir == 1) {
        direction = (PI - abs(direction)) * (direction / abs(direction));
    }
    magnitude *= 1.1;
    if (magnitude > 8) {
        magnitude = 8;
    }
}

void Force::normalize() {
    while(abs(direction) > PI){
        direction -= (2 * PI) * abs(direction) / direction;
    }
}

void Force::collide(Force &f2, double slope, double difference) {

    direction = ((PI - (direction - atan(slope)) + atan(slope)) - PI);
    f2.direction = ((PI - (f2.direction - atan(slope)) + atan(slope)) - PI);

    magnitude = ((magnitude + f2.magnitude) / 2);
    f2.magnitude = (magnitude);
}


