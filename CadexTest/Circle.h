#pragma once
#include "Curve.h"

class Circle  : public Curve
{
	private:
		double radius;
		Vector centre;
		Vector getPointInPlane(double param);
	public:
		Circle(double _radius,Vector _centre,Vector _normVec);
		double getRadius() const override;
		Vector getPoint(double param) override;
		Vector getDeriv(double param) override;
		Vector getCentre() override;

};