#include "Curve.h"

void Curve::locSystem(const Vector& _normVec)
{

	normVec = _normVec;
	normVec.normalize();

	x0 = normVec & globalX;
	if (x0.lenght() < 0.3)
	{
		x0 = normVec & globalY;
	}
	y0 = normVec & x0;
	x0.normalize();
	y0.normalize();

}
