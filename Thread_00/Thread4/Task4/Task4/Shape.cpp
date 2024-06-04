#define _USE_MATH_DEFINES
#include"Shape.h"
#include<cmath>
Shape::Shape()
{
	a = abs(x[1] - x[2]);
	b = abs(y[1] - y[2]);
	c = abs(z[1] - z[2]);
};

line::line() {};
line::line(int _x1, int _y1, int _x2, int _y2) {
	x[1] = _x1; y[1]= _y1;
	x[2] = _x2; y[2] = _y2;
};
sqr::sqr() {};
sqr::sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) {
	x[1] = _x1; y[1] = _y1;
	x[2] = _x2; y[2] = _y2;
	x[3] = _x3; y[3] = _y3;
	x[4] = _x4; y[4] = _y4;
};
double sqr::square1() { return a * b;}
cube::cube() {};
cube::cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2,
	int _x3, int _y3, int _z3, int _x4, int _y4, int _z4,
	int _x5, int _y5, int _z5, int _x6, int _y6, int _z6,
	int _x7, int _y7, int _z7, int _x8, int _y8, int _z8) {
	x[1] = _x1; y[1] = _y1; z[1] = _z1;
	x[2] = _x2; y[2] = _y2; z[2] = _z2;
	x[3] = _x3; y[3] = _y3; z[3] = _z3;
	x[4] = _x4; y[4] = _y4; z[4] = _z4;
	x[5] = _x5; y[5] = _y5; z[5] = _z5;
	x[6] = _x6; y[6] = _y6; z[6] = _z6;
	x[7] = _x7; y[7] = _y7; z[7] = _z7;
	x[8] = _x8; y[8] = _y8; z[8] = _z8;
};
double cube::square1() { return 2 * a * b + 2 * a * c + 2 * b * c;}


circle::circle() {};
circle::circle(int _x1, int _y1, double R) : radius{ R } {

	x[1] = _x1;
	y[1] = _y1;
};
  double circle:: square() {	return M_PI * radius * radius;}


  cylinder::cylinder(int _x1, int _y1, double R, double H) {
	  x[1] = _x1;
	  y[1] = _y1;
	  radius = R;
	  height = H;
	  volume = M_PI * radius * radius * height;
  };
double cylinder::square() { return M_PI * radius * radius + 2 * radius * height;} 

