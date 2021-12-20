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
    /*
     * DESCRIPTION:
     *      Default constructor for the force object
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      Nothing is provided to the constructor.
     * POSTCONDITION:
     *      A force object is constructed with default values.
     */
    Force();

    /*
     * DESCRIPTION:
     *      Constructor for force object
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      2 valid doubles are provided.
     * POSTCONDITION:
     *      A force object is created with a magnitude and direction of
     *      the provided doubles.
     */
    Force(double m, double d);

    /*
     * DESCRIPTION:
     *      Apply another force ot the current force.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid force object is provided.
     * POSTCONDITION:
     *      The current force is adjusted by the applied force.
     */
    void apply(const Force &);

    /*
     * DESCRIPTION:
     *      Redirects the force off either the ceiling or the walls of the
     *      game space.
     * RETURN:
     *      void
     * PRECONDITION:
     *      Either integer 1 or 0 is provided.
     * POSTCONDITION:
     *      The force is redirected.
     */
    void redirect(int dir);

    /*
     * DESCRIPTION:
     *      Set direction to the provided double
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid double exists and is provided.
     * POSTCONDITION:
     *      The current direction is set the provided double.
     */
    void setDir(double d) {
        direction = d;
    }

    /*
     * DESCRIPTION:
     *      Getter for magnitude of the force.
     * RETURN:
     *      double
     * PRECONDITION:
     *      A valid force object exists.
     * POSTCONDITION:
     *      The current magnitude of the force is returned.
     */
    double getMag() const {
        return magnitude;
    }

    /*
     * DESCRIPTION:
     *      Getter for the direction of the force.
     * RETURN:
     *      double
     * PRECONDITION:
     *      A valid force object exists.
     * POSTCONDITION:
     *      The current direction of the force is returned as a double.
     */
    double getDir() const {
        return direction;
    }

    /*
     * DESCRIPTION:
     *      Normalizes the current force to within -Pi / 2  to Pi / 2
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid force object exists.
     * POSTCONDITION:
     *      The forces' direction is set at an equivalent radian between -Pi
     *      / 2  to Pi / 2.
     */
    void normalize();

    /*
     * DESCRIPTION:
     *      Returns the direction of the forces when inverted.
     * RETURN:
     *      double
     * PRECONDITION:
     *      A valid force object exists.
     * POSTCONDITION:
     *      The current direction + Pi is returned.
     */
    double invert() const;

    /*
     * DESCRIPTION:
     *      When two balls collide their forces are redirected off each other.
     * RETURN:
     *      void
     * PRECONDITION:
     *      A valid force is provided a long with the slope of the line
     *      perpendicular to the intersection of the balls and the
     *      differences in height and width between the two balls.
     * POSTCONDITION:
     *      Both forces are redirected off of each other.
     */
    void collide(Force &f2, double slope, double differenceY, double differenceX);
};

const Force Gravity(0.01, -(PI / 2));
const double maxMag = 2;

#endif //FALLINGBALLS_FORCE_H
