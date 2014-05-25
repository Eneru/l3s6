
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Polygon.h
\*======================================================*/

#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glx.h>

#include "Vector.h"

#define P_MAX_VERTICES 1000

typedef struct
{
	int _nb_vertices;
	Point _vertices[P_MAX_VERTICES];
	int _is_closed;
	int _is_filled;
	int _is_convex;
} Polygon;

Polygon* P_new();
// initialise un polygone (0 sommets)

void   P_copy(Polygon *original, Polygon *copy);
// original et copie sont deux polygones déjà alloués.
// Cette fonction copie les donnée
// depuis original vers copie de façon à ce que les
// deux polygones soient identiques.

void   P_addVertex(Polygon *P, Vector p);
// ajoute un sommet au polygone P. Ce nouveau sommet est situé en pos.

void   P_removeLastVertex(Polygon *P);
// enlève le dernier sommet de P

void   P_print(Polygon *P, char *message); 
// Affiche sur une console les données de P
// à des fins de debuggage.

void   P_draw(Polygon *P);
// dessine le polygone P

int    P_isConvex(Polygon *P);
// Vérifie si P est convexe

int    P_isOnTheLeftOfAllEdges(Polygon *P, Vector M);
// Vérifie si un vector est à gauche de toutes les arêtes

int    P_nbEdgesIntersectedByRay(Polygon *P, Vector M, Vector u_ray);
// retourne le nombre d'arêtes qui s'intersectent avec une droite

int    P_isInside(Polygon *P, Vector M);
// retourne 1 si M est dans le polygone P

void   P_turnAroundY(Polygon *P, double radians);
// tourne le polygone P de radians radians autour d'Y

Vector P_center(Polygon *P);
// retourne le centre de P

Vector P_normal(Polygon *P);
// retourne la normale au polygone plan P
 
void   P_scale(Polygon *P, double factor);
// applique une modification de la taille de P d'un facteur factor

void   P_translate(Polygon *P, Vector trans);
// applique une translation à P de vecteur trans

void   P_rotate(Polygon *P, Vector normal); 
// applique une rotation de P par rapport à un vecteur


#endif // _POLYGON_H_
