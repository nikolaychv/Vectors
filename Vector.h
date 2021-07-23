#ifndef INCLUDED_VECTOR_H
#define INCLUDED_VECTOR_H
#include "Point.h"
#include <cmath>

const double EPSILON = 1e-6;

class Vector : public Point {
public:
	// Big Five
	Vector(); // default constructor
	Vector(const Point&, const Point&); // constructor with parameters
	Vector(double, double, double); // constructor with parameters
	Vector& operator=(const Vector&);  // overloaded operator =
	Vector(const Vector&); // copy constructor
	virtual ~Vector(); // destructor

	Vector vector_direction() const; // finds the direction of vector
	double vector_length() const; // finds the length of vector
	bool is_null_vector() const; // zero vector check
	bool is_parallelism(const Vector&) const; // parallelism check
	bool is_perpendicularity(const Vector&) const; // perpendicularity check

	Vector operator+(const Vector&) const; //  addition of two vectors
	Vector operator-(const Vector&) const; //  subtraction of two vectors
	Vector operator*(double) const; //  multiplication of a vector by a real number
	double operator*(const Vector&) const; //  scalar product of two vectors
	Vector operator^(const Vector&) const; //  vector product of two vectors
	double operator()(Vector&, Vector&); //  mixed product of three vectors

	// auxiliary function to preserve encapsulation
	virtual ostream& ins(ostream&) const;

	friend class Line;
	friend class Triangle;

protected:
	// data
	double x;
	double y;
	double z;
};

#endif