#include "Tetrahedron.h"
#include "EqualPointException.h"

// default constructor
Tetrahedron::Tetrahedron() {

	this->A = Point();
	this->B = Point();
	this->C = Point();
	this->D = Point();
}

// constructor with parameters
Tetrahedron::Tetrahedron(const Point& A, const Point& B, const Point& C, const Point& D) {
	try {

		if ((A == B) || (A == C) || (A == D) || (B == C) || (B == D) || (C == D)) {

			throw EqualPointException();
		}

		else {

			this->A = A;
			this->B = B;
			this->C = C;
			this->D = D;
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

		cout << "Enter other values to initialize the fourth point! " << endl;
		double x4, y4, z4;
		cout << "X: "; cin >> x4;
		cout << " Y: "; cin >> y4;
		cout << " Z: "; cin >> z4;
		cout << endl;
		Point fourth_point(x4, y4, z4);

		Tetrahedron new_tetrahedron(first_point, second_point, third_point, fourth_point); 
	}
}

// copy constructor
Tetrahedron::Tetrahedron(const Tetrahedron& rhs) : Point(rhs) {

	this->A = rhs.A;
	this->B = rhs.B;
	this->C = rhs.C;
	this->D = rhs.D;
}

// overloaded operator =
Tetrahedron& Tetrahedron::operator=(const Tetrahedron& rhs) {

	if (this != &rhs)
	{
		Point::operator=(rhs);
		this->A = rhs.A;
		this->B = rhs.B;
		this->C = rhs.C;
		this->D = rhs.D;
	}
	return *this;
}

// destructor
Tetrahedron::~Tetrahedron() {}

// check if it is regular
bool Tetrahedron::is_regular() const {

	Vector first_edge(A, B), second_edge(B, C), third_edge(C, A), fourth_edge(A, D), fifth_edge(B, D), sixth_edge(C, D);

	return (first_edge.vector_length() == second_edge.vector_length() && 
		    first_edge.vector_length() == third_edge.vector_length() &&
		    first_edge.vector_length() == fourth_edge.vector_length() &&
		    first_edge.vector_length() == fifth_edge.vector_length() &&
		    first_edge.vector_length() == sixth_edge.vector_length());
}

// check if it is orthogonal
bool Tetrahedron::is_orthogonal() const {

	Vector first_edge(A, B), second_edge(B, C), third_edge(A, C), fourth_edge(A, D), fifth_edge(B, D), sixth_edge(C, D);

	double a = first_edge.vector_length(), b = second_edge.vector_length(), c = third_edge.vector_length(),
		   d = fourth_edge.vector_length(), e = fifth_edge.vector_length(), f = sixth_edge.vector_length();
	
	return a * a + f * f == c * c + e * e &&
		   a * a + f * f == d * d + b * b;

	// return a * a + f * f == c * c + e * e == d * d + b * b;
}

// finds the surface of a tetrahedron
double Tetrahedron::tetrahedron_surface() const {

	Triangle first_side(A, B, C), second_side(B, C, D), third_side(A, B, D), fourth_side(A, C, D);

	return first_side.triangle_area() + second_side.triangle_area() + third_side.triangle_area() + fourth_side.triangle_area();
}

// finds the volume of a tetrahedron
double Tetrahedron::tetrahedron_volume() const {
	Vector theSide(A, B);
	double a = theSide.vector_length();

	return (a * a * a) / sqrt(72);
}

// checks if a point lies on one of the sides of a tetrahedron
bool Tetrahedron::operator==(const Point& point) {

	Segment first_edge(A, B), second_edge(B, C), third_edge(C, A), fourth_edge(A, D), fifth_edge(B, D), sixth_edge(C, D);

	return (first_edge == point || second_edge == point || third_edge == point || fourth_edge == point || fifth_edge == point || sixth_edge == point);
}

// auxiliary function to preserve encapsulation
ostream& Tetrahedron::ins(ostream& out) const {

	out << "Tetrahedron " << "(" << A << ", " << B << ", " << C << ", " << D << ")";
	return out;
}