#include "Vector.h"

Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector::Vector(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Vector::normalize()
{
	double l = lenght();
	x /= l;
	y /= l;
	z /= l;
}

double Vector::lenght() const
{
	return std::sqrt(x*x + y*y + z*z);
}

void Vector::transform(const Vector & x0Loc, const Vector & y0Loc, const Vector & z0Loc)
{
	double _x = x * x0Loc.x + y * y0Loc.x + z * z0Loc.x;
	double _y = x * x0Loc.y + y * y0Loc.y + z * z0Loc.y;
	double _z = x * x0Loc.z + y * y0Loc.z + z * z0Loc.z;
	x = _x;
	y = _y;
	z = _z;
}

std::ostream & operator<<(std::ostream & o, const Vector & vec)
{
	return o << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}

Vector operator+(const Vector& vec1, const Vector& vec2)
{
	return Vector(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

Vector operator-(const Vector& vec1, const Vector& vec2)
{
	return Vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}
Vector operator*(const Vector& vec, double a)
{
	return Vector(a*vec.x, a*vec.y, a*vec.z);
}
Vector operator*(double a, const Vector& vec)
{
	return vec * a;
}

double operator*(const Vector& vec1, const Vector& vec2)
{
	return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
}

Vector operator&(const Vector& vec1, const Vector& vec2)
{
	return Vector(vec1.y*vec2.z - vec1.z*vec2.y, vec1.z*vec2.x - vec1.x*vec2.z, vec1.x*vec2.y - vec1.y*vec2.x);
}