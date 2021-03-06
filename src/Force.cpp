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
#include "Force.h"


Force::Force() {
    magnitude = 0;
    direction = -PI / 2;
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
    normalize();
    if (dir == 0) {
        direction *= -1;
    }
    if (dir == 1) {
        direction = (PI - abs(direction)) * (direction / abs(direction));
    }
    magnitude *= 1.1;
    if (magnitude > maxMag) {
        magnitude = maxMag;
    }
}

void Force::normalize() {
    while (abs(direction) > PI) {
        direction -= (2 * PI) * abs(direction) / direction;
    }
    if (magnitude > maxMag) {
        magnitude = maxMag;
    }
}

void Force::collide(Force &f2, double slope, double differenceY,
                    double differenceX) {

    if (abs(direction - f2.direction) > PI / 3) {
        direction = ((PI - (direction - atan(slope)) + atan(slope)) - PI);
        f2.direction = ((PI - (f2.direction - atan(slope)) + atan(slope)) - PI);
    } else {
        double forces[] = {direction, f2.direction};

        if (differenceY < 0) {
            swap(forces[0], forces[1]);
        }
        if (direction > 0 && f2.direction > 0) {
            forces[0] = (PI - (forces[0] - atan(slope))) + atan(slope);
            forces[1] = ((PI - (forces[1] - atan(slope)) + atan(slope)) - PI);
        } else if (direction < 0 && f2.direction < 0) {
            forces[1] = (PI - (forces[1] - atan(slope))) + atan(slope);
            forces[0] = ((PI - (forces[0] - atan(slope)) + atan(slope)) - PI);
        } else {
            if (forces[0] > 0) {
                forces[0] = (PI - (forces[0] - atan(slope))) + atan(slope);
                forces[1] = ((PI - (forces[1] - atan(slope)) + atan(slope)) -
                             PI);
            } else {
                forces[1] = (PI - (forces[1] - atan(slope))) + atan(slope);
                forces[0] = ((PI - (forces[0] - atan(slope)) + atan(slope)) -
                             PI);
            }
        }
        if (differenceY < 0) {
            swap(forces[0], forces[1]);
        }
        direction = forces[0];
        f2.direction = forces[1];
    }

    magnitude = ((magnitude + f2.magnitude) / 2);
    f2.magnitude = (magnitude);
}

double Force::invert() const {

    return direction + PI;
}


