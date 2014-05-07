
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Vector.c
\*======================================================*/

#include "Vector.h"

/* dimensions de la fenetre */
int width = 600;
int height = 600;

//------------------------------------------------

Vector V_new(float x, float y, float z)
{
  Vector v;
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}

//------------------------------------------------
// a des fin de debug

void V_print(Vector v, char *message)
{
  fprintf(stderr,"%s : %f %f %f\n",message, v.x,v.y,v.z);
}

Vector V_add(Vector v1, Vector v2)
{
	return V_new(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);	
}

Vector V_substract(Vector v1, Vector v2)
{
	return V_new(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);	
}

Vector V_multiply(double lambda, Vector v)
{
	return V_new(v.x*lambda,v.y*lambda,v.z*lambda);
}

Vector V_cross(Vector v1, Vector v2)
{
	return V_new(v1.y*v2.z-v1.z*v2.y,v1.z*v2.x-v1.x*v2.z,v1.x*v2.y-v1.y*v2.x);
}

float V_dot(Vector v1, Vector v2)
{
	return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

int V_isOnTheRight(Point M, Vector A, Vector B)
{
	return (A.x-M.x/A.x-B.x == A.y-M.y/A.y-B.y) && (A.z-M.z/A.z-B.z == A.y-M.y/A.y-B.y);
}

float V_det(Point a, Point b, Point c)
{
	return a.x*(b.y*c.z-b.z*c.y)-a.y*(b.x*c.z-b.z*c.x)+a.z*(b.x*c.y-b.y*c.x);
}

int V_segmentsIntersect(Vector p1, Vector p2, Vector q1, Vector q2)
{
	float detp1p2q1=V_det(p1,p2,q1);
	float detp1p2q2=V_det(p1,p2,q2);
	float detq1q2p1=V_det(q1,q2,p1);
	float detq1q2p2=V_det(q1,q2,p2);
	
	return (inf_zero(detp1p2q1*detp1p2q2) && inf_zero(detq1q2p1*detq1q2p2))
		|| (zero(detp1p2q1) && ((q1.x <= p2.x && q1.x >= p1.x) || (q1.y >= p2.y && q1.y <= p1.y) || (q1.z >= p2.z && q1.z <= p1.z)))
		|| (zero(detp1p2q2) && ((q2.x <= p2.x && q2.x >= p1.x) || (q2.y >= p2.y && q2.y <= p1.y) || (q2.z >= p2.z && q2.z <= p1.z)))
		|| (zero(detq1q2p1) && ((p1.x <= q2.x && p1.x >= q1.x) || (p1.y >= q2.y && p1.y <= q1.y) || (p1.z >= q2.z && p1.z <= q1.z)))
		|| (zero(detq1q2p2) && ((p2.x <= q2.x && p2.x >= q1.x) || (p2.y >= q2.y && p2.y <= q1.y) || (p2.z >= q2.z && p2.z <= q1.z)));
}

int V_rayIntersectsSegment(Point M, Vector u_ray, Vector p1, Vector p2)
{
	return 0;
}

double V_length(Vector v)
{
	return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

Vector V_unit(Vector v)
{
	return V_new(v.x/V_length(v), v.y/V_length(v), v.z/V_length(v));
}

Vector V_tournerAutourDeLAxeY(Vector p, double radians)
{
	return V_new(p.x,p.y,p.z);
}




