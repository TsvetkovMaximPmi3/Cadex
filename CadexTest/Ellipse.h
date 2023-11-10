#pragma once
#include "Curve.h"


class Ellipse : public Curve
{
	
	private:
		double radiusX, radiusY;
		Vector centre;
		Vector getPointInPlane(double param);
		
	public:
		Ellipse(double _radiusX, double _radiusY,Vector _centre, Vector _normVec);
		Vector getPoint(double param) override;
		Vector getDeriv(double param) override;
		Vector getCentre() override;
		double getRadiusX();
		double getRadiusY();
		double getRadius() const override;
		
};