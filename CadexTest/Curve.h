#pragma once
#include<math.h>
#include "GlobalCoord.h"
#include "Vector.h"

class Curve
{
	protected:
		void locSystem(const Vector& _normVec);
	public:
		double virtual getRadius() const = 0;
		Vector virtual getPoint(double param) = 0;
		Vector virtual getDeriv(double param) = 0;
		Vector virtual getCentre() = 0;
		Vector normVec, x0, y0;
};