#include "Polygon.h"

extern int width;
extern int height;

float P_ConvertVertex_X (Polygon *P, int i)
{
	return (P->_vertices[i].x/width)*2.-1.;
}

float P_ConvertVertex_Y (Polygon *P, int i)
{
	return -1.*(P->_vertices[i].y/height*2.-1.);
}

void P_init(Polygon *p)
{
	p->_nb_vertices = 0;
	p->_is_closed = 0;
	p->_is_filled = 0;
	p->_is_convex = 0;
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

void P_draw(Polygon *P)
{
	int i;
	if (P->_is_filled)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		if (P->_nb_vertices == 2)
			glBegin(GL_LINES);
		else if (P->_nb_vertices == 3)
			glBegin(GL_TRIANGLES);
		else if (P->_nb_vertices >= 4)
			glBegin(GL_POLYGON);
		
		for (i=0 ; i<P->_nb_vertices ; i++)
			glVertex3f(P_ConvertVertex_X(P,i),P_ConvertVertex_Y(P,i),P->_vertices[i].z);
	}
	
	else
	{
		if (P->_is_closed && P->_nb_vertices>1)
		{
				glBegin(GL_LINE_LOOP);
				for (i=0 ; i<P->_nb_vertices ; i++)
					glVertex3f(P_ConvertVertex_X(P,i),P_ConvertVertex_Y(P,i),P->_vertices[i].z);
		}
		else
			if (P->_nb_vertices>1)
			{
				glBegin(GL_LINE_STRIP);
				for (i=0 ; i<P->_nb_vertices ; i++)
					glVertex3f(P_ConvertVertex_X(P,i),P_ConvertVertex_Y(P,i),P->_vertices[i].z);
			}
	}
	
	glEnd();
}

void P_print(Polygon *P, char *message)
{
	int i;
	fprintf(stderr,"Polygone P\n\tNombre de vertices : %d\n",P->_nb_vertices);
	for (i=0 ; i<P->_nb_vertices ; i++)
		fprintf(stderr,"\tPoint %d : x = %f, y = %f, z = %f\n",i,P_ConvertVertex_X(P,i),P_ConvertVertex_Y(P,i),P->_vertices[i].z);
	fprintf(stderr,"\n");
}

void  P_tournerAutourDeLAxeY(Polygon *P, double radians)
{
	
}









