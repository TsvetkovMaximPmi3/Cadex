#pragma once
#include<math.h>
#include "GlobalCoord.h"
#include "Vector.h"

class Curve
{
	protected:
		//Local coordinate system for the object
		void locSystem(const Vector& _normVec);
	public:
		//Return radius object (Ellipse return (radX + radY) / 2)
		double virtual getRadius() const = 0;
		//Returns point on object in the global coordinate system
		Vector virtual getPoint(double param) = 0;
		//Returns derivative on object in the global coordinate system
		Vector virtual getDeriv(double param) = 0;
		//Returns center on object in the global coordinate system
		Vector virtual getCentre() = 0;
		//Normal vector and local system coordinate
		Vector normVec, x0, y0;
};