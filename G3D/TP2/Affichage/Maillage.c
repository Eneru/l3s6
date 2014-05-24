
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Maillage.c
\*======================================================*/

#include "Maillage.h"

//------------------------------------------------------------

quad Q_new(Vector p1, Vector p2, Vector p3, Vector p4)
{
	quad new;
	new._vertices[0] = p1;
	new._vertices[1] = p2;
	new._vertices[2] = p3;
	new._vertices[3] = p4;
	return new;
}

//------------------------------------------------------------

void M_init(Maillage *M)
{
	M->_nb_quads = 0;
	M->_is_filled = 0;
}

//------------------------------------------------------------

void M_makeCube(Maillage *M)
{
	Vector p000 = V_new(-0.5,-0.5,-0.5);
	Vector p001 = V_new(-0.5,-0.5, 0.5);
	Vector p010 = V_new(-0.5, 0.5,-0.5);
	Vector p011 = V_new(-0.5, 0.5, 0.5);
	Vector p100 = V_new( 0.5,-0.5,-0.5);
	Vector p101 = V_new( 0.5,-0.5, 0.5);
	Vector p110 = V_new( 0.5, 0.5,-0.5);
	Vector p111 = V_new( 0.5, 0.5, 0.5);

	M->_nb_quads = 6;
	M->_quads[0] = Q_new(p010,p011,p111,p110);  // top
	M->_quads[1] = Q_new(p000,p100,p101,p001);  // bottom
	M->_quads[2] = Q_new(p110,p111,p101,p100);  // right
	M->_quads[3] = Q_new(p000,p001,p011,p010);  // left
	M->_quads[4] = Q_new(p111,p011,p001,p101);  // front
	M->_quads[5] = Q_new(p000,p010,p110,p100);  // back
}

//------------------------------------------------------------

void M_draw(Maillage *M)
{
	Vector v1, v2, v3, v4;
	Vector v1v2, v2v3, normal;

	srand48(1);

	int i;
	for(i=0;i<M->_nb_quads;i++)
	{
		// Calcul des sommets et des normals
		v1 = M->_quads[i]._vertices[0];
		v2 = M->_quads[i]._vertices[1];
		v3 = M->_quads[i]._vertices[2];
		v4 = M->_quads[i]._vertices[3];
		v1v2 = V_substract(v2,v1);
		v2v3 = V_substract(v3,v2);
		normal = V_cross(v1v2,v2v3);

		if(M->_is_filled)	glBegin(GL_QUADS);
		else				glBegin(GL_LINE_LOOP);

		glNormal3f(normal.x,normal.y,normal.z); // seulement utile pour SHADE
		glColor3f(drand48(), drand48(), drand48()); // seulement utile pour FLAT
													// (couleur au hasard)
		glVertex3f(v1.x,v1.y,v1.z);
		glVertex3f(v2.x,v2.y,v2.z);
		glVertex3f(v3.x,v3.y,v3.z);
		glVertex3f(v4.x,v4.y,v4.z);
		glEnd();
	}
}

//------------------------------------------------------------
