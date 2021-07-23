#include "Segment.h"

// default constructor
Segment::Segment() : Line() {

	this->intervalStart = Point();
	this->intervalEnd = Point();
}

// constructor with parameters
Segment::Segment(const Point& firstPoint, const Point& secondPoint) {

	this->intervalStart = firstPoint;
	this->intervalEnd = secondPoint;
	Line theSegment(this->intervalStart, this->intervalEnd);
}

// copy constructor
Segment::Segment(const Segment& rhs) : Line(rhs) {

	this->intervalStart = rhs.intervalStart;
	this->intervalEnd = rhs.intervalEnd;
	Line theSegment(this->intervalStart, this->intervalEnd);
}

// overloaded operator =
Segment& Segment::operator=(const Segment& rhs) {

	if (this != &rhs)
	{
		Line::operator=(rhs);
		this->intervalStart = rhs.intervalStart;
		this->intervalEnd = rhs.intervalEnd;
		Line theSegment(this->intervalStart, this->intervalEnd);
	}
	return *this;
}

// destructor
Segment::~Segment() {}

// finds the length of a segment
double Segment::segment_length() const {

	Vector len(this->intervalStart, this->intervalEnd);
	return len.vector_length();
}

// finds the midpoint of a segment
Point Segment::middle_of_segment() const {
	Point middlePoint((this->intervalStart.x + this->intervalEnd.x) / 2, 
		              (this->intervalStart.y + this->intervalEnd.y) / 2, 
		              (this->intervalStart.z + this->intervalEnd.z) / 2);
	
	return middlePoint;
}

// checks if a point lies on a segment
bool Segment::operator==(const Point& C) {
	
	double theWholeSegment  = sqrt((this->intervalEnd.x - this->intervalStart.x) * (this->intervalEnd.x - this->intervalStart.x) +
		                           (this->intervalEnd.y - this->intervalStart.y) * (this->intervalEnd.y - this->intervalStart.y) +
		                           (this->intervalEnd.z - this->intervalStart.z) * (this->intervalEnd.z - this->intervalStart.z));

	double firstPartSegment = sqrt((C.x - this->intervalStart.x) * (C.x - this->intervalStart.x) + 
		                           (C.y - this->intervalStart.y) * (C.y - this->intervalStart.y) + 
		                           (C.z - this->intervalStart.z) * (C.z - this->intervalStart.z));

	double secondPartSegment = sqrt((this->intervalEnd.x - C.x) * (this->intervalEnd.x - C.x) +
		                            (this->intervalEnd.y - C.y) * (this->intervalEnd.y - C.y) +
		                            (this->intervalEnd.z - C.z) * (this->intervalEnd.z - C.z));

	return (abs(firstPartSegment + secondPartSegment - theWholeSegment) < EPSILON);
}

// auxiliary function to preserve encapsulation
ostream& Segment::ins(ostream& out) const {

	out << "Segment with two points: " << "(" << intervalStart.x << ", " << intervalStart.y << ", " << intervalStart.z << ")"
		                             << ", (" << intervalEnd.x << ", " << intervalEnd.y << ", " << intervalEnd.z << ")";
	return out;
}