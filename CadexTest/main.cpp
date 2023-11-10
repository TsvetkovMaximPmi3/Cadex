#define _USE_MATH_DEFINES
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <memory>

#include <thread>
#include <omp.h>

#define numThreads 4
double parallSum(std::vector<std::shared_ptr<Curve>> cVec)
{
	std::vector<double> sum(numThreads);

	#pragma omp parallel num_threads(numThreads)
	{
		#pragma omp for 
		for (int i = 0; i < sum.size(); i++)
		{
			sum[i] = 0;
		}
		#pragma omp for 
		for (int i = 0; i < cVec.size(); i++)
		{
			
			sum[omp_get_thread_num()] += cVec[i].get()->getRadius();
			
		}
	}
	double result = 0;
	for (int i = 0; i < sum.size(); i++)
	{
		std::cout << sum[i] << std::endl;
	}
	for (int i = 0; i < sum.size(); i++)
	{
		result += sum[i];
	}
	return result;
}

double randRange(double maxRand, double minRand)
{
	return (double)rand() / (double)RAND_MAX * (maxRand - minRand) + minRand;
}

std::shared_ptr<Curve> getRandomCircle(double maxRand,double minRand)
{
	return std::shared_ptr<Curve> (new Circle(randRange(maxRand, minRand),
		Vector(randRange(maxRand, minRand), randRange(maxRand, minRand), randRange(maxRand, minRand)),
		Vector(randRange(maxRand, minRand), randRange(maxRand, minRand), randRange(maxRand, minRand))));
}

std::shared_ptr<Curve> getRandomEllipse(double maxRand, double minRand)
{
	return std::shared_ptr<Curve> (new Ellipse(randRange(maxRand, minRand), randRange(maxRand, minRand),
		Vector(randRange(maxRand, minRand), randRange(maxRand, minRand), randRange(maxRand, minRand)),
		Vector(randRange(maxRand, minRand), randRange(maxRand, minRand), randRange(maxRand, minRand))));
}

std::shared_ptr<Curve> getRandomHelix(double maxRand, double minRand)
{
	return std::shared_ptr<Curve>(new Helix(randRange(maxRand, minRand),
		Vector(randRange(maxRand, minRand), randRange(maxRand, minRand), randRange(maxRand, minRand)),
		randRange(maxRand, minRand),
		Vector(randRange(maxRand, minRand), randRange(maxRand, minRand), randRange(maxRand, minRand))));
}

void printCont(std::shared_ptr<Curve> c)
{
	static int count = 0;
	std::cout << "points : C" << count << '\n';
	
	std::cout << c->getPoint(M_PI/4) << '\n';
	std::cout << c->getDeriv(M_PI / 4) << '\n';

	count++;
}

bool compare(double r1, double r2)
{
	return r1 < r2;
}
int main()
{	
	//Task 2
	std::vector<std::shared_ptr<Curve>> cVec;
	for (int i = 0; i < 10; i++)
	{
		int r = rand() % 3;
		switch (r)
		{
		case 0 :
			cVec.push_back(getRandomCircle(10, 1));
			break;
		case 1:
			cVec.push_back(getRandomEllipse(10, 1));
			break;
		case 2:
			cVec.push_back(getRandomHelix(10, 1));
			break;
		default:
			break;
		}

	}

	//Task 3
	for (auto item : cVec)
	{
		printCont(item);
	}

	//Task 4
	std::vector<std::shared_ptr<Curve>> circleVec;
	for (auto item : cVec)
	{
		if (dynamic_cast<Circle*>(item.get()))
		{
			circleVec.push_back(item);
		}
	}

	//Task 5
	std::sort(circleVec.begin(), circleVec.end(), [](const std::shared_ptr<Curve>& c1, const std::shared_ptr<Curve>& c2)
	{
		return c1->getRadius() < c2->getRadius();
	});

	//Task 6
	double sumRadius = 0;
	for (auto item : cVec)
	{
		sumRadius += item.get()->getRadius();
	}
	//Task 8
	double parallelSum = parallSum(cVec);
	return 0;
}
