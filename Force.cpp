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
    if (magnitude > 20) {
        magnitude = 20;
    }
}


