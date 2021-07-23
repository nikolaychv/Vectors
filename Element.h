#ifndef INCLUDED_ELEMENT_H
#define INCLUDED_ELEMENT_H
#include <iostream>
using namespace std;

// abstract class 
class Element {
public:
	virtual ostream& ins(ostream& out) const = 0; // virtual function 
	virtual ~Element() {} // virtual destructor
};

#endif