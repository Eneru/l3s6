#include "Polygon.h"

void P_init(Polygon *p)
{
	p->_nb_vertices = 0;
}

void P_copy(Polygon *original, Polygon *copie)
{
	int i;
	
	copie->_nb_vertices = original->_nb_vertices;
	copie->_is_closed = original->_is_closed;
	copie->_is_filled = original->_is_filled;
	copie->_is_convex = original->_is_convex;
	
	for (i=0 ; i<original->_nb_vertices ; i++)
		copie->_vertices[i] = original->_vertices[i];
}

void P_addVertex(Polygon *P, Point pos)
{
	P->_vertices[P->_nb_vertices++] = pos;
}

void P_removeLastVertex(Polygon *P)
{
	P->_nb_vertices--;
}











