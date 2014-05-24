
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Maillage.h
\*======================================================*/

#ifndef _MAILLAGE_H_
#define _MAILLAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glx.h>

#include "Vector.h"


//----------------------

typedef struct
{
	Vector _vertices[4];
} quad;

quad Q_new(Vector p1, Vector p2, Vector p3, Vector p4);

//----------------------

#define M_MAX_QUADS 5000

typedef struct
{
	int _nb_quads;
	quad _quads[M_MAX_QUADS];
	int _is_filled;
} Maillage;

void M_init(Maillage *M);
void M_makeCube(Maillage *M);
void M_draw(Maillage *M);

#endif

