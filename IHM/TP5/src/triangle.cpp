#include "triangle.h"

int Triangle::ComputeZCoordinate(point p1, point p2, int x, int y)
{
	return p1.x * (p2.y - y) + p2.x * (y - p1.y) + x * (p1.y - p2.y);
}

bool Triangle::IsPointInTriangle(int x, int y)
{
	int z1 = ComputeZCoordinate(p1, p2, x, y);
	int z2 = ComputeZCoordinate(p2, p3, x, y);
	int z3 = ComputeZCoordinate(p3, p1, x, y);

	return (z1 > 0 && z2 > 0 && z3 > 0) || (z1 < 0 && z2 < 0 && z3 < 0);
}
