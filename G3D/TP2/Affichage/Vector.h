
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

typedef struct
{
	float x, y, z;
} Vector;

Vector V_new(float x, float y, float z);

void V_print(Vector v, char *message);
Vector V_add(Vector v1, Vector v2);
Vector V_substract(Vector v1, Vector v2);
Vector V_multiply(double lambda, Vector v);
Vector V_cross(Vector v1, Vector v2);




#endif // __VECTOR_H__
