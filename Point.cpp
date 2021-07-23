#include "Point.h"

// default constructor
Point::Point() {

	this->x = 0;
	this->y = 0;
	this->z = 0;
}

// constructor with parameters
Point::Point(double x, double y, double z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

// operator =
Point& Point::operator=(const Point& rhs) {

	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}

	return *this;
}

// copy constructor
Point::Point(const Point& rhs) {

	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
}

// destructor
Point::~Point() {}

// getter
double Point::getX() const {

	return this->x;
}

// getter
double Point::getY() const {

	return this->y;
}

// getter
double Point::getZ() const {

	return this->z;
}

// operator == 
bool Point::operator==(const Point& rhs) const {

	return x == rhs.x && y == rhs.y && z == rhs.z;
}

ostream& Point::ins(ostream& out) const {

	out << "Point " << "(" << x << ", " << y << ", " << z << ")";
	return out;
}

ostream& operator<<(ostream& out, const Point& rhs) {
	return rhs.ins(out);
}