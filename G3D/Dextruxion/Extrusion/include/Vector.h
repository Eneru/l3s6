
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Vector.h
\*======================================================*/

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR_CST 1e-4
#define width 650
#define height 650

static inline int zero(double a) {return a < (0 + ERROR_CST) && a > (0 - ERROR_CST);}
// retourne 1 si a==0

static inline int inf_zero(double a) {return a < (0 - ERROR_CST);}
// retourne 1 si a<0

static inline double max(double a, double b) {return (a<b) ? b : a;}
// retourne le maximum entre a et b

static inline double min(double a, double b) {return (a<b) ? a : b;}
// retourne le minimum entre a et b

static inline int equal(double a, double b) {return ( ((a-b) < (0+ERROR_CST)) && ((a-b) > (0-ERROR_CST)) );}
// retourne 1 si a == b 0 sinon


typedef struct
{
	float x, y, z;
} Vector;

typedef Vector Point;

Vector V_new(float x, float y, float z);
// retourne un vecteur de composantes x, y et z

void   V_print(Vector v, char *message);
// affiche à l'écran les coordonnées de v + un message (debug)

Vector V_add(Vector v1, Vector v2);
// retourne v1+v2

Vector V_substract(Vector v1, Vector v2);
// retourne v1-v2

Vector V_multiply(double lambda, Vector v);
// retourne lambda * v

Vector V_cross(Vector v1, Vector v2);
// retourne le produit vectoriel v1^v2

float  V_dot(Vector v1, Vector v2);
// retourne le produit scalaire : v1.v2

double V_length(Vector v);
// retourne la norme du vecteur v

Vector V_unit(Vector v);
// retourne un vecteur colinéaire à v mais de longueur 1

int    V_isOnTheRight(Point M, Point A, Point B);
// retourne 1 si M est sur la droite (AB) et 0 sinon

int    V_isOnTheSegment(Point M, Point A, Point B);
// même chose que isOnTheRight mais avec un segment

int    V_RightTo(Point M, Point A, Point B);
// retourne 1 si M est à droite de (AB)

int    V_isCoplanar(Point a, Point b, Point c, Point d);
// retourne 1 si [ab] coplanaire à [cd]

int    V_segmentsIntersect(Point p1, Point p2, Point q1, Point q2);
// retourne 1 si le segment [p1p2] intersect le segment [q1q2]

int    V_rayIntersectsSegment(Point M, Vector u_ray, Point p1, Point p2);
// retourne 1 si la demie droite d'origine M et de direction u_ray intersecte [p1p2]

float  V_det(Point a, Point b, Point c);
// retourne le déterminant d'une matrice de 3 points

Vector V_turnAroundY(Vector p, double angle);
// tourne le vecteur p d'un angle de "angle" radians autour de l'axe Y

Vector V_turnAroundZ(Vector p, double angle);
// tourne le vecteur p d'un angle de "angle" radians autour de l'axe Z

Vector V_projectOnPlane(Vector v, Vector normal);

double V_decompose(Vector p, Vector u);
// retourne les coordonnées de p par rapport à u
 
Vector V_recompose(double x, double y, double z, Vector u, Vector v, Vector w);
// retourne le vecteur ayant pour coordonnées (u,v,w) dans la base (x,y,z)
 
void   V_uxUyFromUz(Vector u_z, Vector *u_x, Vector *u_y);
// modifie 2 vecteurs de sorte que (u_x,u_y,u_z) soit un repère orthonormé

Vector V_rotate(Point m, Point o, Point a, Point b);
// effectue une rotation de a en b sur m avec pour centre le point o

int    V_isNullVector(Vector p);
// vérifie si p est le vecteur nul

float V_ConvertVertex_X (Vector v);
float V_ConvertVertex_Y (Vector v);

#endif // __VECTOR_H__
