#include "Helix.h"

Vector Helix::getPointInPlane(double param)
{
	return Vector(radius*cos(param), radius*sin(param), 0);
}
Helix::Helix(double _radius, Vector _centre,double _step,Vector _normVec)
{
	if (_radius <= 0)
	{
		throw "_radius <= 0";
	}
	radius = _radius;
	centre = _centre;
	step = _step;
	locSystem(_normVec);
}

double Helix::getRadius() const
{
	return radius;
}

Vector Helix::getCentre()
{
	return centre;
}

Vector Helix::getHeight()
{	
	return Vector();
}

Vector Helix::getPoint(double param)
{
	Vector loc = getPointInPlane(param) + globalZ* param * step;
	loc.transform(x0, y0, normVec);
	return centre + loc;
}

Vector Helix::getDeriv(double param)
{
	Vector result(radius*sin(param)*(-1), radius*cos(param), 0);
	result = result + globalZ * step;
	result.transform(x0, y0, normVec);
	return result;
}
