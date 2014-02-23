#include "triangle.h"

Triangle::Triangle(point x, point y, point z, wxColour * color, float largeur)
{
	p1 = x;
	p2 = y;
	p3 = z;
	colour = color;
	thickness = largeur;
}
