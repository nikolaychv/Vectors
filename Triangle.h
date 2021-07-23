#ifndef INCLUDED_TRIANGLE_H
#define INCLUDED_TRIANGLE_H
#include "Segment.h"

class Triangle : public Point {
public:
    // Big Five
    Triangle(); // default constructor
    Triangle(const Point&, const Point&, const Point&); // constructor with parameters
    Triangle(const Triangle&); // copy constructor
    Triangle& operator=(const Triangle&); // overloaded operator =
    virtual ~Triangle(); // destructor

    void triangle_type() const; // determines the type of triangle
    double triangle_area() const; // finds the area of a triangle
    double triangle_perimeter() const; // finds the perimeter of a triangle
    Point triangle_centroid() const; // finds the centroid of a triangle

    double min_value(double, double, double) const; // finds the minimum value of the given coordinates
    double max_value(double, double, double) const; // finds the maximum value of the given coordinates

    bool operator<(const Point&); // checks if a point lies inside a triangle
    bool operator>(const Point&); // checks if a point lies outside a triangle
    bool operator==(const Point&); // checks if a point lies on one of the sides of a triangle

    virtual ostream& ins(ostream&) const; // auxiliary function to preserve encapsulation

protected:
    // data
    Point A;
    Point B;
    Point C;
};

#endif