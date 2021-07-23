#include "Triangle.h"
#include "EqualPointException.h"

// default constructor
Triangle::Triangle() : Point() {

	this->A = Point();
	this->B = Point();
	this->C = Point();
}

// constructor with parameters
Triangle::Triangle(const Point& firstPoint, const Point& secondPoint, const Point& thirdPoint) : Point(firstPoint.x, firstPoint.y, firstPoint.z) {

	try
	{

		if (firstPoint == secondPoint || firstPoint == thirdPoint || secondPoint == thirdPoint) {

			throw EqualPointException(); 
		}
		else
		{

			this->A = firstPoint;
			this->B = secondPoint;
			this->C = thirdPoint;
		}
	}

	catch (EqualPointException& object2) {
		cerr << object2.equalPoints() << endl;
		cout << "Enter other values to initialize the first point! " << endl;
		double x1, y1, z1;
		cout << "X: "; cin >> x1;
		cout << " Y: "; cin >> y1;
		cout << " Z: "; cin >> z1;
		cout << endl;
		Point first_point(x1, y1, z1);

		cout << "Enter other values to initialize the second point! " << endl;
		double x2, y2, z2;
		cout << "X: "; cin >> x2;
		cout << " Y: "; cin >> y2;
		cout << " Z: "; cin >> z2;
		cout << endl;
		Point second_point(x2, y2, z2);

		cout << "Enter other values to initialize the third point! " << endl;
		double x3, y3, z3;
		cout << "X: "; cin >> x3;
		cout << " Y: "; cin >> y3;
		cout << " Z: "; cin >> z3;
		cout << endl;
		Point third_point(x3, y3, z3);

		Triangle new_triangle(first_point, second_point, third_point);
	}
}

// copy constructor
Triangle::Triangle(const Triangle& rhs) : Point(rhs) {

	this->A = rhs.A;
	this->B = rhs.B;
	this->C = rhs.C;
}

// overloaded operator =
Triangle& Triangle::operator=(const Triangle& rhs) {

	if (this != &rhs)
	{
		Point::operator=(rhs);
		this->A = rhs.A;
		this->B = rhs.B;
		this->C = rhs.C;
	}

	return *this;
}

// destructor
Triangle::~Triangle() {}

// determines the type of triangle
void Triangle::triangle_type() const {

	Vector AB(A, B), BC(B, C), AC(A, C);

	double a = BC.vector_length(), b = AC.vector_length(), c = AB.vector_length();
	
	if ((c == a) && (a == b)) {
		cout << "The triangle is equilateral. ";
	}

	else if ((c == b && c != a) || (c == a && c != b) || (a == b && b != c)) {
		cout << "The triangle is isosceles. ";
	}

	else {
		cout << "The triangle is scalene. ";
	}

    if (((c * c) == (b * b) - (a * a)) || ((a * a) == (b * b) - (c * c)) || ((b * b) == (c * c) + (a * a)))
	{
		cout << "The triangle is rectangular (right-angled). ";
	}

	else if (((b * b) > (c * c) + (a * a)) || ((c * c) > (b * b) + (a * a)) || ((a * a) > (b * b) + (c * c))) 
	{
		cout << "The triangle is obtuse. ";
	}

	else {
		cout << "The triangle is acute.";
	}

	cout << endl;
}

// finds the area of a triangle
double Triangle::triangle_area() const
{
	Vector AB(A, B), BC(B, C), AC(A, C);

	double p = (AB.vector_length() + BC.vector_length() + AC.vector_length()) / 2;
	
	return sqrt(p * (p - AB.vector_length()) * (p - BC.vector_length()) * (p - AC.vector_length()));
}

// finds the perimeter of a triangle
double Triangle::triangle_perimeter() const
{
	Vector AB(A, B), BC(B, C), AC(A, C);
	
	return (AB.vector_length() + BC.vector_length() + AC.vector_length());
}

// finds the centroid of a triangle
Point Triangle::triangle_centroid() const
{
	Point centroid((A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3, (A.z + B.z + C.z) / 3);
	return centroid;
}

// finds the minimum value of the given coordinates
double Triangle::min_value(double first, double second, double third) const {
	double min_value;
	if (first < second && first < third) {
		min_value = first;
	}
	else if (second < first && second < third) {
		min_value = second;
	}
	else {
		min_value = third;
	}

	return min_value;
}

// finds the maximum value of the given coordinates
double Triangle::max_value(double first, double second, double third) const {
	double max_value;
	if (first > second && first > third) {
		max_value = first;
	}
	else if (second > first && second > third) {
		max_value = second;
	}
	else {
		max_value = third;
	}

	return max_value;
}

// checks if a point lies inside a triangle
bool Triangle::operator<(const Point& point) {
	double max_value_x = max_value(A.x, B.x, C.x);
	double min_value_x = min_value(A.x, B.x, C.x);
	
	double max_value_y = max_value(A.y, B.y, C.y);
	double min_value_y = min_value(A.y, B.y, C.y);

	double max_value_z = max_value(A.z, B.z, C.z);
	double min_value_z = min_value(A.z, B.z, C.z);

	return (point.x > min_value_x) && (point.x < max_value_x) &&
		   (point.y > min_value_y) && (point.y < max_value_y) &&
		   (point.z > min_value_z) && (point.z < max_value_z);
}

// checks if a point lies outside a triangle
bool Triangle::operator>(const Point& point) {
	Triangle theTriangle = *this;
	if (theTriangle.operator<(point)) {
		return false;
	}
	else {
		return true;
	}
	// or return !(theTriangle.operator<(point));
}

// checks if a point lies on one of the sides of a triangle
bool Triangle::operator==(const Point& point) {

	Segment AB(A, B), BC(B, C), AC(A, C);

	return (AB == point) || (BC == point) || (AC == point);
}

// auxiliary function to preserve encapsulation
ostream& Triangle::ins(ostream& out) const {

	out << "Triangle " << "(" << A << ", " << B << ", " << C << ")";
	return out;
}