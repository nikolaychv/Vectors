#ifndef INCLUDED_POINT_H
#define INCLUDED_POINT_H
#include "Element.h"

class Point : public Element {
public:
	// Big Five
	Point(); // default constructor
	Point(double, double, double); // constructor with parameters
	Point& operator=(const Point&); // overloaded operator =
	Point(const Point&); // copy constructor
	virtual ~Point(); // destructor

	// getters
	double getX() const;
	double getY() const;
	double getZ() const;
	
	bool operator==(const Point&) const; // checks if a point coincides with another point
	virtual ostream& ins(ostream&) const; // auxiliary function to preserve encapsulation

	friend class Line;
	friend class Segment;
	friend class Triangle;
	friend class Tetrahedron;

	// data
protected:
	double x;
	double y;
	double z;
};

ostream& operator<<(ostream&, const Point&); // overloaded operator <<

#endif