#pragma once
#include "Curve.h"

class Helix : public Curve
{
	private:
		double radius , step;
		Vector centre;
		Vector getPointInPlane(double param);
	public:
		Helix(double _radius, Vector _centre, double _step, Vector _normVec);
		Vector getHeight();
		Vector getPoint(double param) override;
		Vector getDeriv(double param) override;
		Vector getCentre() override;
		double getRadius() const override;
		
};