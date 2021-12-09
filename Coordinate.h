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
#ifndef CL10_18_2021_POINT_H
#define CL10_18_2021_POINT_H

#include <cmath>
#include <iostream>

using namespace std;

struct Coordinate {
    //Variables
    double x, y;

    //Constructor
    /*
     * DESCRIPTION:
     *      Constructor for the coordinate class
     * RETURN:
     *      N/A
     * PRECONDITION:
     *      2 Valid doubles are provided.
     * POSTCONDITION:
     *      A coordinate object is created with the provided x and y.
     */
    Coordinate(double x, double y);

    //Functions
    /*
     * DESCRIPTION:
     *      Checks the distance between two Coordinates.
     * RETURN:
     *      double
     * PRECONDITION:
     *      A valid coordinate object exists and is provided.
     * POSTCONDITION:
     *      The distance between the two coordinates is returned.
     *      Neither coordinate data is changed.
     */
    double distance(const Coordinate &other) const;

    /*
     * DESCRIPTION:
     *      Returns the amount changed of x and y between two coordinates.
     * RETURN:
     *      double
     * PRECONDITION:
     *      A valid coordinate object exists and is provided.
     * POSTCONDITION:
     *      The changed and y and x is returned as a double.
     *      Neither coordinate data is changed.
     */
    double delta(const Coordinate &other) const;

    /*
     * DESCRIPTION:
     *      Returns the slope between the two points.
     * RETURN:
     *      double
     * PRECONDITION:
     *      A valid coordinate object exists and is provided.
     *      The slope between the two coordinates is not undefined.
     * POSTCONDITION:
     *      The distance between the two coordinates is returned.
     *      Neither coordinate data is changed.
     */
    double slope(const Coordinate &other) const;

    /*
     * DESCRIPTION:
     *      Adjusts the coordinate by the given value.
     * RETURN:
     *      Coordinate
     * PRECONDITION:
     *      A valid double is provided.
     * POSTCONDITION:
     *      Coordinate object is returned containing the original points
     *      values both adjusted by the given double.
     */
    Coordinate adjust(double) const;

    /*
     * DESCRIPTION:
     *      Less than operator overload
     * RETURN:
     *      bool
     * PRECONDITION:
     *      A valid coordinate object exists and is provided.
     * POSTCONDITION:
     *      Returned true if the point is less than the provided point.
     */
    bool operator<(const Coordinate &rhs) const;

    /*
     * DESCRIPTION:
     *      Greater than operator overload
     * RETURN:
     *      bool
     * PRECONDITION:
     *      A valid coordinate object exists and is provided.
     * POSTCONDITION:
     *      Returned true if the point is greater than the provided point.
     */
    bool operator>(const Coordinate &rhs) const;

    /*
     * DESCRIPTION:
     *      Greater than or equal to operator overload
     * RETURN:
     *      bool
     * PRECONDITION:
     *      A valid coordinate object exists and is provided.
     * POSTCONDITION:
     *      Returned true if the point is greater than or equal to the
     *      provided point.
     */
    bool operator>=(const Coordinate &rhs) const;
};

#endif //CL10_18_2021_POINT_H
