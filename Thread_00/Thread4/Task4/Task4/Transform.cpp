#include "Transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

Shape transform::shift(int m, int n, int k)
{
	for (auto t : shape.x) t += m;
	for (auto t : shape.y) t += n;
	for (auto t : shape.z) t += k;
	return shape;
}

Shape transform::scaleX(int a)
{
	for (auto t : shape.x) t /= a;
	return shape;
}

Shape transform::scaleY(int d)
{
	for (auto t : shape.y) t /= d;
	return shape;
}

Shape transform::scaleZ(int e)
{
	for (auto t : shape.z) t /= e;
	return shape;
}

Shape transform::scale(int s)
{
	for (auto t : shape.x) t /= s;
	for (auto t : shape.y) t /= s;
	for (auto t : shape.z) t /= s;
	return shape;
}