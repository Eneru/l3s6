#include "Polygon.h"

extern int width;
extern int height;

Polygon* P_new()
{
	Polygon *p = malloc(sizeof(Polygon));
	
	if (p!=NULL)
	{
		fprintf(stderr,"Erreur d'allocation de polygone\n");
		exit(EXIT_FAILURE);
	}
	
	p->_nb_vertices = 0;
	p->_is_closed = 0;
	p->_is_filled = 0;
	p->_is_convex = 0;
	
	return p;
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
	if (P->_nb_vertices+1 < P_MAX_VERTICES)
		P->_vertices[P->_nb_vertices++] = pos;
}

void P_removeLastVertex(Polygon *P)
{
	if (P->_nb_vertices > 0)
		P->_nb_vertices--;
}

void P_print(Polygon *P, char *message)
{
	int i;
	fprintf(stderr,"Polygone P\n\tNombre de vertices : %d\n",P->_nb_vertices);
	for ( i = 0 ; i < P->_nb_vertices ; i++)
		fprintf(stderr,"\tPoint %d : x = %f, y = %f, z = %f\n",i,V_ConvertVertex_X(P->_vertices[i]),V_ConvertVertex_Y(P->_vertices[i]),P->_vertices[i].z);
	fprintf(stderr,"\n");
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
			glVertex3f(V_ConvertVertex_X(P->_vertices[i]),V_ConvertVertex_Y(P->_vertices[i]),P->_vertices[i].z);
	}
	
	else
	{
		if (P->_is_closed && P->_nb_vertices>1)
		{
				glBegin(GL_LINE_LOOP);
				for (i=0 ; i<P->_nb_vertices ; i++)
					glVertex3f(V_ConvertVertex_X(P->_vertices[i]),V_ConvertVertex_Y(P->_vertices[i]),P->_vertices[i].z);
		}
		else
			if (P->_nb_vertices>1)
			{
				glBegin(GL_LINE_STRIP);
				for (i=0 ; i<P->_nb_vertices ; i++)
					glVertex3f(V_ConvertVertex_X(P->_vertices[i]),V_ConvertVertex_Y(P->_vertices[i]),P->_vertices[i].z);
			}
	}
	
	glEnd();
}

int P_isConvex(Polygon *p)
{
	return p->_is_convex;
}

int P_isOnTheLeftOfAllEdges(Polygon *p, Vector m)
{
	int res, i;
	
	// Si le polygone n'a que 1 coté (ou 0) alors le retour est "faux"
	if (p->_nb_vertices <= 1)
		return 0;
	
	// Tant qu'on ne rencontre pas une arrête du mauvais coté et qu'on a pas fait le parcours de toutes les arêtes
	for (i = 0 ; i < (p->_nb_vertices - 1) && (res == 1) ; i++)
		res = V_RightTo(m,p->_vertices[i],p->_vertices[i+1]);
	
	return !res; // on retourne !res car la fonction "RightTo" précise si des vecteurs sont à droites et non à gauche
}

int P_nbEdgesIntersectedByRay(Polygon *P, Vector M, Vector u_ray)
{
	int nbEdges,i;
	
	// Même chose que pour isOnTheLeftOfAllEdges
	if (P->_nb_vertices <= 1)
		return 0;
		
	for (i = 0 ; i < P->_nb_vertices - 1 ; i++)
		nbEdges += V_rayIntersectsSegment(M,u_ray,P->_vertices[i],P->_vertices[i+1]);
	
	return nbEdges;
}

int P_isInside (Polygon *P, Vector M)
{
	Vector v_i = V_new(1.0,0.0,0.0);
	return ((P_nbEdgesIntersectedByRay(P,M,v_i) % 2) == 1) ? 1 : 0;
}

void P_turnAroundY(Polygon *P, double radians)
{
	int i;
	for (i = 0 ; i < P->_nb_vertices ; i++)
		V_turnAroundY(P->_vertices[i],radians);
}

// Pré : P->_nb_vertices > 0
Vector P_center(Polygon *P)
{
	int i;
	float frequence_vertices = 1./(float)P->_nb_vertices;
	Vector centre = V_new (0.0, 0.0, 0.0);

        for (i = 0 ; i < P->_nb_vertices ; i++)
            centre = V_add (centre, P->_vertices[i]);
        centre = V_multiply (frequence_vertices, centre);
        
    return centre;
}

// Pré : P->_nb_vertices > 2
Vector P_normal(Polygon *P)
{
	Vector res = V_new(0.0,0.0,0.0);
	
	if (P->_nb_vertices > 2) // un plan est composé de 2 droites au minimum
		res = V_unit( V_cross( V_substract(P->_vertices[1],P->_vertices[0]),V_substract(P->_vertices[2],P->_vertices[1]) ) );
		
	return res;
}

// Pré : P->_nb_vertices > 1
void P_scale(Polygon *P, double factor)
{
	int i;
	Vector arete, nouvelle_arete;
	
	if (P->_nb_vertices > 1)
    {
		Vector tmp[P->_nb_vertices]; // Initialisation d'un tableau de vector de taille du nombre de vector dans le polygone
        tmp[0] = P->_vertices[0]; // Assignation de l'indice 0 pour éviter le -1 dans la boucle
        
        for (i = 1 ; i < P->_nb_vertices ; i++)
        {
            arete = V_substract (P->_vertices[i], P->_vertices[i - 1]);
            nouvelle_arete = V_multiply (factor, arete);
            tmp[i] = V_add (tmp[i - 1], nouvelle_arete);
        }

        for (i = 1 ; i < P->_nb_vertices ; i++)
            P->_vertices[i] = tmp[i];
    }
}

void P_translate(Polygon *P, Vector trans)
{
	int i;
	for ( i = 0 ; i < P->_nb_vertices ; i++)
		P->_vertices[i] = V_add(P->_vertices[i],trans);
}

void P_rotate(Polygon *P, Vector normal)
{
	int i;
	Vector centre = P_center(P);
	
	Vector normale_courante = V_add(centre,P_normal(P));
	Vector normale_ciblee = V_add(centre,V_unit(normal));
	
	for ( i = 0 ; i < P->_nb_vertices ; i++)
		P->_vertices[i] = V_rotate (P->_vertices[i], centre, normale_courante, normale_ciblee);
}
