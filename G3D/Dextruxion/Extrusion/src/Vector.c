
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Vector.c
\*======================================================*/

#include "Vector.h"


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

//------------------------------------------------

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

double V_length(Vector v)
{
	return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

Vector V_unit(Vector v)
{
	return V_new(v.x/V_length(v), v.y/V_length(v), v.z/V_length(v));
}

int V_isOnTheRight(Point M, Vector A, Vector B)
{
	return (zero(V_det(M,A,B)));
}

int V_isOnTheSegment(Point M, Point A, Point B)
{
	return (V_isOnTheRight(M,A,B)==1
			&& (M.x <= max(A.x,B.x)) && (M.x >= min(A.x,B.x))
			&& (M.y <= max(A.y,B.y)) && (M.y >= min(A.y,B.y))
			&& (M.z <= max(A.z,B.z)) && (M.z >= min(A.z,B.z)));
}

int V_RightTo(Point M, Point A, Point B)
{
	return (V_det(M,A,B)<0);
}

int V_isCoplanar(Point a, Point b, Point c, Point d)
{
	return ( equal( V_det(V_substract(b,a),V_substract(d,c),V_substract(c,a)), 0.) );
}

int V_segmentsIntersect(Point p1, Point p2, Point q1, Point q2)
{
	if(!V_isCoplanar(p1,p2,q1,q2))
		return 0;
	
	float detp1p2q1=V_det(p1,p2,q1);
	float detp1p2q2=V_det(p1,p2,q2);
	float detq1q2p1=V_det(q1,q2,p1);
	float detq1q2p2=V_det(q1,q2,p2);
	
	return ( (inf_zero(detp1p2q1*detp1p2q2) && inf_zero(detq1q2p1*detq1q2p2))
			|| (equal(detp1p2q1,0.) && V_isOnTheSegment (q1,p1,p2))
			|| (equal(detp1p2q2,0.) && V_isOnTheSegment (q2,p1,p2))
			|| (equal(detq1q2p1,0.) && V_isOnTheSegment (p1,q1,q2))
			|| (equal(detq1q2p2,0.) && V_isOnTheSegment (p2,q1,q2)) );
}

int V_rayIntersectsSegment(Point M, Vector u_ray, Vector p1, Vector p2)
{
	Vector tmp;
	double distance_mp1 = sqrt(pow((p1.x-M.x),2) + pow((p1.y-M.y),2) + pow((p1.z-M.z),2));
	double distance_mp2 = sqrt(pow((p2.x-M.x),2) + pow((p2.y-M.y),2) + pow((p2.z-M.z),2));
	
	double max_dist = max(distance_mp1,distance_mp2);
	
	max_dist = max_dist/V_length(u_ray) +1;
	tmp = V_add(M,V_multiply(max_dist,u_ray));
	
	return V_segmentsIntersect(M,tmp,p1,p2);
}

float V_det(Point a, Point b, Point c)
{
	return a.x*(b.y*c.z-b.z*c.y)-a.y*(b.x*c.z-b.z*c.x)+a.z*(b.x*c.y-b.y*c.x);
}

Vector V_turnAroundY(Vector p, double angle)
{
	return V_new(p.x*cos(angle) + p.z*sin(angle), p.y, -p.x*sin(angle) + p.z*cos(angle));
}

Vector V_turnAroundZ(Vector p, double angle)
{
	return V_new(p.x*cos(angle) - p.y*sin(angle), p.x*sin(angle) + p.y*cos(angle), p.z);
}

Vector V_projectOnPlane(Vector v, Vector normal)
{
	Vector u_x = V_new (0.0, 0.0, 0.0);
    Vector u_y = V_new (0.0, 0.0, 0.0);
    
    V_uxUyFromUz(normal, & u_x, & u_y);
    
    double x = V_decompose (v, u_x);
    double y = V_decompose (v, u_y);

    return V_recompose (x, y, 0.0, u_x, u_y, normal);
}

double V_decompose(Vector p, Vector u)
{
	return V_dot(p,u) * V_length(u);
}

Vector V_recompose(double x, double y, double z, Vector u, Vector v, Vector w)
{
	return V_add( V_multiply(x,u), V_add( V_multiply(y,v), V_multiply(z,w) ) );
}

void V_uxUyFromUz(Vector u_z, Vector *u_x, Vector *u_y)
{
	Vector vy=V_new(0.,1.,0.); // vecteur unitaire de l'ordonnée
	
	if ( V_isNullVector( V_cross(vy,u_z) ) )
	{
		u_x->x=1 * V_length(u_z);
		u_x->y=0;
		u_x->z=0;
		u_y->x=0;
		u_y->y=0;
		u_y->z=-1 * V_length(u_z);
	}
	
	else
	{	
		//On crée un nouveau vecteur pas colinéaire a u_z
		Vector new=V_new(u_z.x+1,u_z.y+2,u_z.z+3);

		//Calcul de u_y
		*u_y=V_cross(u_z,new);
		*u_y=V_unit(*u_y);
		//on projette le u_y trouve sur le plan (u_z.(0,1,0))
		*u_y=V_substract(*u_y,V_multiply(V_dot(V_cross(u_z,V_new(0,1,0)),*u_y),V_cross(u_z,V_new(0,1,0))));
		*u_y=V_unit(*u_y);

		//calcul de u_x
		*u_x=V_cross(u_z,*u_y);
		*u_x=V_unit(*u_x);
	}
}

Vector V_rotate(Point m, Point centre, Point v1, Point v2)
{
	double x, y, z;
	Vector u_x_v1, u_y_v1, u_z_v1, u_x_v2, u_y_v2, u_z_v2;
	u_z_v1 = V_unit(v1);
	u_z_v2 = V_unit(v2);

	V_uxUyFromUz(u_z_v1, &u_x_v1, &u_y_v1);
	V_uxUyFromUz(u_z_v2, &u_x_v2, &u_y_v2);

	Vector temp = V_substract(v1, centre);
	x = V_decompose(temp, u_x_v1);
	y = V_decompose(temp, u_y_v1);
	z = V_decompose(temp, u_z_v1);
	return V_add(centre, V_recompose(x, y, z, u_x_v2, u_y_v2, u_z_v2));
}

int V_isNullVector(Vector p)
{
	return ( zero(p.x) && zero(p.y) && zero(p.z) );
}

float V_ConvertVertex_X(Vector v) { return v.x/width*2. -1. ;}

float V_ConvertVertex_Y(Vector v) { return -1.*(v.y/height*2. -1.) ;}
