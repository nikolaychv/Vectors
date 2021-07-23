#include "Line.h"

// default constructor
Line::Line() : Vector() {

	this->firstPoint = Point();
	this->secondPoint = Point();
	this->theLine = Vector();
}

// constructor with parameters
Line::Line(const Point& thePoint, const Vector& theVector) : Vector(thePoint.x, thePoint.y, thePoint.z) {

	this->firstPoint = thePoint;
	this->theLine = theVector;
	this->secondPoint = Point(theLine.x + firstPoint.x, theLine.y + firstPoint.y, theLine.z + firstPoint.z);
}

// constructor with parameters
Line::Line(const Point& firstPoint, const Point& secondPoint) : Vector(firstPoint.x, firstPoint.y, firstPoint.z) {

	this->firstPoint = firstPoint;
	this->secondPoint = secondPoint;
	this->theLine = line_direction();
}

// overloaded operator =
Line& Line::operator=(const Line& rhs) {

	if (this != &rhs) {
		Vector::operator=(rhs);
		firstPoint = rhs.firstPoint;
		secondPoint = rhs.secondPoint;
		theLine = rhs.theLine;
	}

	return *this;
}

// copy constructor
Line::Line(const Line& rhs) : Vector(rhs) {

	firstPoint = rhs.firstPoint;
	secondPoint = rhs.secondPoint;
	theLine = rhs.theLine;
}

// destructor
Line::~Line() {}

// finds the line direction
Vector Line::line_direction() const {

	return Vector(secondPoint.x - firstPoint.x, secondPoint.y - firstPoint.y, secondPoint.z - firstPoint.z);
}

// finds the normal vector
Vector Line::normal_vector() {

	return Vector(-(secondPoint.y - firstPoint.y), secondPoint.x - firstPoint.x, 0);
}

// finds the angle between two lines (in radians)
double Line::angle_between_lines(const Line& secondLine) const {

	double theAngle = (this->theLine.x * secondLine.theLine.x + this->theLine.y * secondLine.theLine.y + this->theLine.z * secondLine.theLine.z) /
		(this->theLine.vector_length() * secondLine.theLine.vector_length());

	return acos(theAngle);
}


// check if a point lies on a line
bool Line::operator+(const Point& point) const {
	double first = (point.x - firstPoint.x / theLine.x) - (point.y - firstPoint.y / theLine.y);
	double second = (point.y - firstPoint.y / theLine.y) - (point.z - firstPoint.z / theLine.z);
	
	return first < EPSILON && second < EPSILON;
}

// check if a line is parallel to another line

bool Line::operator||(const Line& secondLine) const {
	double first = (secondLine.firstPoint.x - this->firstPoint.x) - (secondLine.secondPoint.x - this->secondPoint.x);
	double second = (secondLine.firstPoint.y - this->firstPoint.y) - (secondLine.secondPoint.y - this->secondPoint.y);
	double third = (secondLine.firstPoint.z - this->firstPoint.z) - (secondLine.secondPoint.z - this->secondPoint.z);
	
	return first < EPSILON && second < EPSILON && third < EPSILON;
}

// check if a line coincides with another right
bool Line::operator==(const Line& secondLine) const {

	return (this->firstPoint == secondLine.firstPoint || this->firstPoint == secondLine.secondPoint) &&
		(this->theLine == secondLine.theLine);
}

// check if a line intersects another line
bool Line::operator&&(const Line& secondLine) const {

	double first_ratio = (secondPoint.x - firstPoint.x / secondLine.secondPoint.x - secondLine.firstPoint.x);
	double second_ratio = (secondPoint.y - firstPoint.y / secondLine.secondPoint.y - secondLine.firstPoint.y);
	double third_ratio = (secondPoint.z - firstPoint.z / secondLine.secondPoint.z - secondLine.firstPoint.z);

	return first_ratio != second_ratio && first_ratio != third_ratio && second_ratio != third_ratio;
}

// check if a line is crossed with another right
bool Line::operator!=(const Line& secondLine) const {

	Line firstLine = *this;
	return !(firstLine.operator||(secondLine)) && !(firstLine.operator==(secondLine));
}

// check if a line is perpendicular to another line
bool Line::operator|(const Line& secondLine) const {

	return this->theLine.is_perpendicularity(secondLine.theLine);
}

// auxiliary function to preserve encapsulation
ostream& Line::ins(ostream& out) const {

	out << "Line " << "(" << theLine.x << ", " << theLine.y << ", " << theLine.z << ")";
	return out;
}