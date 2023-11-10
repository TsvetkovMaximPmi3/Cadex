#include "Ellipse.h"

Vector Ellipse::getPointInPlane(double param)
{
	return Vector(radiusX*cos(param), radiusY*sin(param), 0);
}



Ellipse::Ellipse(double _radiusX, double _radiusY, Vector _centre,  Vector _normVec)
{
	if (_radiusX <= 0 || _radiusY <= 0)
	{
		throw "radiusX <= 0 || radiusY <= 0";
	}
	radiusX = _radiusX;
	radiusY = _radiusY;
	centre = _centre;
	locSystem(_normVec);
}

Vector Ellipse::getPoint(double param)
{

	Vector loc = getPointInPlane(param);
	loc.transform(x0, y0, normVec);
	return  centre + loc;
}

Vector Ellipse::getDeriv(double param)
{
	Vector result(radiusX*sin(param)*(-1), radiusY*cos(param),0);
	result.transform(x0, y0, normVec);
	return result;
}

Vector Ellipse::getCentre()
{
	
	return centre;
}

double Ellipse::getRadiusX()
{
	return radiusX;
}

double Ellipse::getRadiusY()
{
	return radiusY;
}

double Ellipse::getRadius() const
{
	return radiusX + radiusY;
}
