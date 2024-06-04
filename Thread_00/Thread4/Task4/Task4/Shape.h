#pragma once
#include <vector>
//#include<string>
class Shape
{
public:	
	Shape();	
	int a=0, b=0, c=0;
	std::vector<int> x = { 0,0,0,0,0,0,0,0 };
	std::vector<int> y = { 0,0,0,0,0,0,0,0 };
	std::vector<int> z = { 0,0,0,0,0,0,0,0 };
	double volume=0;
	double square=0;
	double radius=0; 
	double height=0;
};
class line: public Shape {
public:
	line();
	line(int _x1, int _y1, int _x2, int _y2);
};
class sqr: public line {
public:
	sqr();
	sqr(int _x1, int _y1, int _x2, int _y2,  int _x3, int _y3, int _x4, int _y4);
	virtual double square1();
};
class cube: public sqr{
public:
	cube();
	cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, 
		int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, 
		int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, 
		int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
	double square1() override;
	double volume =a * b * c;
};
class circle: public Shape {
public:	
	circle();
	circle(int _x1, int _y1, double R); 
	virtual double square();

	double radius;
};
class cylinder: public circle {
	cylinder(int _x1, int _y1, double R, double H) ;
public:
	double height;
	double square() override;
	double volume;
};