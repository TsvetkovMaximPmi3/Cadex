#pragma once
#include <iostream>
#include <algorithm>
struct Vector
{
	double x, y, z;
	Vector();
	Vector(double _x, double _y, double _z);
	void normalize();
	double lenght() const;
	//Transforms a local coordinate system into a global
	void transform(const Vector& x0Loc, const Vector& y0Loc, const Vector& z0Loc);
};

std::ostream& operator << (std::ostream& o, const Vector& vec);
Vector operator+(const Vector& vec1, const Vector& vec2);

Vector operator-(const Vector& vec1, const Vector& vec2);

Vector operator*(const Vector& vec, double a);

Vector operator*(double a, const Vector& vec);

double operator*(const Vector& vec1, const Vector& vec2);

Vector operator&(const Vector& vec1, const Vector& vec2);
