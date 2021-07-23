#include "Vector.h"
#include "VectorLengthException.h"

// default constructor
Vector::Vector() : Point() {

	this->x = 0;
	this->y = 0;
	this->z = 0;
}

// constructor with parameters
Vector::Vector(const Point& p1, const Point& p2) {

	this->x = p2.getX() - p1.getX();
	this->y = p2.getY() - p1.getY();
	this->z = p2.getZ() - p1.getZ();
}

// constructor with parameters
Vector::Vector(double x, double y, double z) : Point(x, y, z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

// overloaded operator =
Vector& Vector::operator=(const Vector& rhs) {

	if (this != &rhs)
	{
		Point::operator=(rhs);
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}

	return *this;
}

// copy constructor
Vector::Vector(const Vector& rhs) : Point(rhs) {

	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
}

// destructor
Vector::~Vector() {}

// finds the length of vector
double Vector::vector_length() const {

	return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

// finds the direction of vector
Vector Vector::vector_direction() const {
	try
	{
		if (vector_length() == 0)
		{
			throw VectorLengthException();
		}
		else
		{
			double x1 = this->x / vector_length();
			double y1 = this->y / vector_length();
			double z1 = this->z / vector_length();

			return Vector(x1, y1, z1);
		}
	}
	catch (VectorLengthException& object)
	{
		cerr << object.excep() << endl;
		cout << "Enter other values to initialize the vector! " << endl;
		double x1, y1, z1;
		cout << "X: "; cin >> x1;
		cout << " Y: "; cin >> y1;
		cout << " Z: "; cin >> z1;
		cout << endl;
		Vector V1(x1, y1, z1);
	}
}

// zero vector check
bool Vector::is_null_vector() const {

	return (this->x == 0) && (this->y == 0) && (this->z == 0);
}

// parallelism check
bool Vector::is_parallelism(const Vector& secondVector) const {

	try
	{
		if (vector_length() == 0 || secondVector.vector_length() == 0)
		{
			throw VectorLengthException();
		}
		else {
			double first = (this->x / secondVector.x) - (this->y / secondVector.y);
			double second = (this->y / secondVector.y) - (this->z / secondVector.z);
			return first < EPSILON && second < EPSILON;
		}

	}

	catch (VectorLengthException& object) {
		cerr << object.excep() << endl;
		cout << "Enter other values to initialize the vector! " << endl;
		double x1;
		cout << "X: "; cin >> x1;
		double y1;
		cout << "Y: "; cin >> y1;
		double z1;
		cout << "Z: "; cin >> z1;
		cout << endl;
		Vector V1(x1, y1, z1);
	}
}

// perpendicularity check
bool Vector::is_perpendicularity(const Vector& secondVector) const {

	try
	{
		if (vector_length() < EPSILON || secondVector.vector_length() < EPSILON) { 

			throw VectorLengthException();
		}
		else {
			double scalar = ((this->x * secondVector.x) + (this->y * secondVector.y) + (this->z * secondVector.z));
			return scalar < EPSILON;
		}
	}
	catch (VectorLengthException& object)
	{
		cerr << object.excep() << endl;
		cout << "Enter other values to initialize the vector! " << endl;
		double x1;
		cout << "X: "; cin >> x1;
		double y1;
		cout << "Y: "; cin >> y1;
		double z1;
		cout << "Z: "; cin >> z1;
		cout << endl;
		Vector V1(x1, y1, z1);
	}
}

//  addition of two vectors
Vector Vector::operator+(const Vector& secondVector) const {

	return Vector(this->x + secondVector.x, this->y + secondVector.y, this->z + secondVector.z);
}

//  subtraction of two vectors
Vector Vector::operator-(const Vector& secondVector) const {

	return Vector(this->x - secondVector.x, this->y - secondVector.y, this->z - secondVector.z);
}

//  multiplication of a vector by a real number
Vector Vector::operator*(double r) const {

	return Vector(this->x * r, this->y * r, this->z * r);
}

//  scalar product of two vectors
double Vector::operator*(const Vector& secondVector) const {

	return ((this->x * secondVector.x) + (this->y * secondVector.y) + (this->z * secondVector.z));
}

//  vector product of two vectors
Vector Vector::operator^(const Vector& secondVector) const {

	return Vector((this->y * secondVector.z - this->z * secondVector.y),
		          (this->z * secondVector.x - this->x * secondVector.z),
		          (this->x * secondVector.y - this->y * secondVector.x));
}

//  mixed product of three vectors
double Vector::operator()(Vector& secondVector, Vector& thirdVector) {

	double firstPart = (this->x * secondVector.y * thirdVector.z) +
		               (this->y * secondVector.z * thirdVector.x) +
		               (this->z * secondVector.x * thirdVector.y);

	double secondPart = (this->z * secondVector.y * thirdVector.x) +
		                (this->x * secondVector.z * thirdVector.y) +
		                (this->y * secondVector.x * thirdVector.z);

	return firstPart - secondPart;
}

// auxiliary function to preserve encapsulation
ostream& Vector::ins(ostream& out) const {

	out << "Vector " << "(" << this->x << ", " << this->y << ", " << this->z << ")";
	return out;
}