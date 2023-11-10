#include "Circle.h"

Vector Circle::getPointInPlane(double param)
{
	return Vector(radius*cos(param), radius*sin(param), 0);
}
Vector Circle::getPoint(double param)
{
	Vector loc = getPointInPlane(param);
	loc.transform(x0, y0, normVec);
	return centre + loc;
}
double Circle::getRadius() const
{
	return radius;
}

Circle::Circle(double _radius, Vector _centre, Vector _normVec)
{
	if (_radius <= 0)
	{
		throw "_radius <= 0";
	}
	radius = _radius;
	centre = _centre;
	locSystem(_normVec);
}

Vector Circle::getDeriv(double param)
{
	Vector result(radius*sin(param)*(-1), radius*cos(param),0);
	result.transform(x0, y0, normVec);
	return result;
}
Vector Circle::getCentre()
{
	
	return centre;
}