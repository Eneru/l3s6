#include "Mesh.h"

Quad Q_new (Vector v1, Vector v2, Vector v3, Vector v4)
{
	Quad q;
	q._vertices[0] = v1;
	q._vertices[1] = v2;
	q._vertices[2] = v3;
	q._vertices[3] = v4;
	
	return q;
}

void Q_print(Quad *q, char *message)
{
	int i;
	
	for ( i = 0 ; i < 4 ; i++)
		fprintf(stderr,"\tPoint %d : x = %f, y = %f, z = %f\n",i,V_ConvertVertex_X(q->_vertices[i]),V_ConvertVertex_Y(q->_vertices[i]),q->_vertices[i].z);
	fprintf(stderr,"\n");
}

void Q_draw(Quad *q)
{
	int i;
	double colour;
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    glBegin (GL_POLYGON);

    for ( i = 0 ; i < 4 ; i++)
    {
        colour = 1.0 / 8 * (i + 4);
        glColor3d (colour, colour, colour);
        Vector v = q->_vertices[i];
        glVertex3d (v.x, v.y, v.z);
    }

    glEnd ();
}

void M_init(Mesh *m)
{
	m->_nb_quads = 0;
	m->_is_filled = 0;
}

Mesh* M_new()
{
	Mesh* m = malloc(sizeof(Mesh));
	
	if (m!=NULL)
	{
		fprintf(stderr,"Erreur d'allocation de maillage\n");
		exit(EXIT_FAILURE);
	}
	
	M_init(m);
	
	return m;
}

void M_print(Mesh *M, char *message)
{
	int i;
	
	fprintf(stderr,"M est %splein, et possede %d quads.\n\n",M->_is_filled ? "" : "non-", M->_nb_quads);
	
	for ( i = 0 ; i < M->_nb_quads ; i++)
	{
		fprintf(stderr,"Quad n : %d\n\t",i);
		Q_print(&M->_quads[i],NULL);
		fprintf(stderr,"\n");
	}
}

// Pré : M->_nb_quads < M_MAX_QUADS
void M_addQuad(Mesh *M, Quad q)
{
	if (M->_nb_quads < M_MAX_QUADS)
		M->_quads[M->_nb_quads++] = q;
}

void M_addSlice(Mesh *P, Polygon *p1, Polygon *p2)
{
	int i,j;
	
	if (p1->_nb_vertices == p2->_nb_vertices)
		for ( i = 0 ; i < p1->_nb_vertices ; i++)
		{
			j = (i+1) % p1->_nb_vertices;
			Quad q = Q_new(p1->_vertices[i],p2->_vertices[i],p2->_vertices[j],p1->_vertices[j]);
			M_addQuad(P, q);
		}
}

void M_revolution(Mesh *P, Polygon *p1, unsigned int nb_slices)
{
	int i;
	Polygon pt, pu;
	P_copy (p1, &pt);
	P_copy (p1, &pu);
	
	double angle = (double) 2.0*Mesh_PI / nb_slices;
	
	for ( i = 0 ; i < nb_slices ; i++)
	{
		P_turnAroundY(&pu, angle);
		M_addSlice(P, &pt, &pu);
		P_copy (&pu, &pt);
	}
}

void M_perlinExtrude(Mesh *QM, Polygon *p, unsigned int nb_slices)
{
	int i;
	Polygon pt, pu;
	P_copy (p, &pt);
	P_copy (p, &pu);
	
	for ( i = 0 ; i < nb_slices ; i++)
	{
		Vector centre = P_center (&pu);
        Vector bruit = PRLN_vectorNoise (centre); // récupération du centre après 
                                                   // l'application du bruit de perlin
        P_translate (&pu, bruit);
        P_rotate (&pu, bruit);
        M_addSlice (QM, &pt, &pu);
        P_copy (&pu, &pt);
    }
}
	
void M_draw(Mesh *P)
{
	int i;
	for ( i = 0 ; i < P->_nb_quads ; i++)
		Q_draw(&P->_quads[i]);
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
