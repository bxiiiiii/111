/*********************************************************************************
* (The MyPoint class) Design a class named MyPoint to represent a point with     *
* x- and y-coordinates. The class contains:                                      *
*                                                                                *
* ■ The data fields x and y that represent the coordinates with getter           *
*   methods.                                                                     *
* ■ A no-arg constructor that creates a point (0, 0).                            *
* ■ A constructor that constructs a point with specified coordinates.            *
* ■ A method named distance that returns the distance from this point to a       *
*   specified point of the MyPoint type.                                         *
* ■ A method named distance that returns the distance from this point to         *
*   another point with specified x- and y-coordinates.                           *
*                                                                                *
* Draw the UML diagram for the class and then implement the class. Write a test  *
* program that creates the two points (0, 0) and (10, 30.5) and displays the     *
* distance between them.                                                         *
*********************************************************************************/

#include <iostream>
#include <math.h>

class MyPoint{
public:
    MyPoint (double a = 0, double b = 0) :
                             x(a), y(b) { }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    double Distance(MyPoint i) {
        return sqrt(pow(x-i.getX(), 2) + pow(y-i.getY(), 2));

    }

    double Distance(double a, double b) {
        return sqrt(pow(x-a, 2) + pow(y-b, 2));
    }

private:
    double x;
    double y;
};

int main()
{
    double a, b;
    MyPoint point1;

    std::cin >> a >> b;
    MyPoint point2(a, b);

    std::cout << "The distance between (" << point1.getX() << "," << point1.getY()
                << ") and (" << point2.getX() << "," << point2.getY() << ") is "
                << point1.Distance(point2) << std::endl;

    return 0;
}