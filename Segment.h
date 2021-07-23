#include "Line.h"
#ifndef INCLUDED_SEGMENT_H
#define INCLUDED_SEGMENT_H

class Segment : public Line {
public:
    // Big Five
    Segment(); // default constructor
    Segment(const Point&, const Point&); // constructor with parameters
    Segment(const Segment&); // copy constructor
    Segment& operator=(const Segment&); // overloaded operator =
    virtual ~Segment(); // destructor

    double segment_length() const; // finds the length of a segment
    Point middle_of_segment() const; // finds the midpoint of a segment
    bool operator==(const Point&); // checks if a point lies on a segment

    virtual ostream& ins(ostream&) const; // auxiliary function to preserve encapsulation

protected:
    // data
    Point intervalStart;
    Point intervalEnd;
};

#endif