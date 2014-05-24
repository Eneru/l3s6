
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

void V_print(Vector v, char *message)
{
  fprintf(stderr,"%s : %f %f %f\n",message, v.x,v.y,v.z);
}

//------------------------------------------------

Vector V_add(Vector v1, Vector v2)
{
  Vector res;
  res.x = v1.x + v2.x;
  res.y = v1.y + v2.y;
  res.z = v1.z + v2.z;
  return res;
}

//------------------------------------------------

Vector V_substract(Vector v1, Vector v2)
{
  Vector res;
  res.x = v1.x - v2.x;
  res.y = v1.y - v2.y;
  res.z = v1.z - v2.z;
  return res;
}

//------------------------------------------------

Vector V_multiply(double lambda, Vector v)
{
  Vector res;
  res.x = lambda * v.x;
  res.y = lambda * v.y;
  res.z = lambda * v.z;
  return res;
}

//------------------------------------------------

Vector V_cross(Vector v1, Vector v2)
{
  Vector res;
  res.x =   v1.y*v2.z - v1.z*v2.y;
  res.y = - v1.x*v2.z + v1.z*v2.x;
  res.z =   v1.x*v2.y - v1.y*v2.x;
  return res;
}

