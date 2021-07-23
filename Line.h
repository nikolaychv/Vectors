#ifndef INCLUDED_LINE_H
#define INCLUDED_LINE_H
#include "Vector.h"

class Line : public Vector {
public:
	// Big Five
	Line(); // default constructor
	Line(const Point&, const Vector&); // constructor with parameters
	Line(const Point&, const Point&); // constructor with parameters
	Line& operator=(const Line&); // overloaded operator =
	Line(const Line&); // copy constructor
	virtual ~Line(); // destructor

	Vector line_direction() const; // finds the line direction
	Vector normal_vector(); // finds the normal vector
	double angle_between_lines(const Line&) const; // finds the angle between two lines (in radians)

	bool operator+(const Point&) const; // checks if a point lies on a line
	bool operator||(const Line&) const; // checks if a line is parallel to another line
	bool operator==(const Line&) const; // checks if a line coincides with another line
	bool operator&&(const Line&) const;  // checks if a line intersects another line
	bool operator!=(const Line&) const; // checks if a line is crossed with another line
	bool operator|(const Line&) const; // checks if a line is perpendicular to another line

	virtual ostream& ins(ostream&) const; // auxiliary function to preserve encapsulation

protected:
	// data 
	Point firstPoint;
	Point secondPoint;
	Vector theLine;
};

#endif