#ifndef INCLUDED_TETRAHEDRON_H
#define INCLUDED_TETRAHEDRON_H
#include "Triangle.h"

class Tetrahedron : public Point {
public:
    // Big Five 
    Tetrahedron(); // default constructor
    Tetrahedron(const Point&, const Point&, const Point&, const Point&); // constructor with parameters
    Tetrahedron(const Tetrahedron&); // copy constructor
    Tetrahedron& operator=(const Tetrahedron&); // overloaded operator =
    virtual ~Tetrahedron(); // destructor

    bool is_regular() const; // check if it is regular
    bool is_orthogonal() const; // check if it is orthogonal
    double tetrahedron_surface() const;  // finds the surface of a tetrahedron
    double tetrahedron_volume() const; // finds the volume of a tetrahedron

    bool operator==(const Point&); // checks if a point lies on one of the sides of a tetrahedron

    virtual ostream& ins(ostream&) const; // auxiliary function to preserve encapsulation

protected:
    // data
	Point A;
	Point B;
	Point C;
	Point D;
};

#endif