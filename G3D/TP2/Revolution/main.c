
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Question1.c
  \*======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Polygon.h"

extern int width;
extern int height;

Polygon * P;

//------------------------------------------------------------

void drawRepere()
{
	glColor3d(1,0,0);
	glBegin(GL_LINES);
	glVertex3d(0,0,0);
	glVertex3d(1,0,0);
	glEnd();

	glColor3d(0,1,0);
	glBegin(GL_LINES);
	glVertex3d(0,0,0);
	glVertex3d(0,1,0);
	glEnd();

	glColor3d(0,0,1);
	glBegin(GL_LINES);
	glVertex3d(0,0,0);
	glVertex3d(0,0,1);
	glEnd();
}

//------------------------------------------------------------

void drawQuadBorder()
{
	glColor3f(0.2,0.5,0.3);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
		glVertex3f(-1,1,-0.5);
		glVertex3f(1,1,-0.5);
		glVertex3f(1,-1,-0.5);
		glVertex3f(-1,-1,-0.5);
	glEnd();
}

//------------------------------------------------------------

void display()
{
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1,1,-1,1,-1,1);
	// gluPerspective( 60, (float)width/height, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// dessiner ici
	drawQuadBorder();
	drawRepere();
	P_draw(P);

	glutSwapBuffers();
}

//------------------------------------------------------------

void keyboard(unsigned char keycode, int x, int y)
{
	printf("Touche frapee : %c (code ascii %d)\n",keycode, keycode);
	
	switch (keycode)
	{
		case 27 : exit(0);	break; /* touche ECHAP */
		
		case 99 : P->_is_closed = !P->_is_closed; /* touche c et C */
		
		case 73 : break;			
	}

	glutPostRedisplay();
}

//------------------------------------------------------------

void special(int keycode, int x, int y)
{
	switch(keycode)
    {
    case GLUT_KEY_UP   : fprintf(stderr,"Fleche haut"); break;
    case GLUT_KEY_DOWN : fprintf(stderr,"Fleche bas"); break;
    case GLUT_KEY_LEFT : fprintf(stderr,"Fleche gauche"); break;
    case GLUT_KEY_RIGHT: fprintf(stderr,"Fleche droit"); break;
    case GLUT_KEY_PAGE_UP : fprintf(stderr,"Fleche qui s'éloigne"); break;
    case GLUT_KEY_PAGE_DOWN : fprintf(stderr,"Fleche qui s'approche"); break;
    default : fprintf(stderr,"function special : unknown keycode %d\n",keycode); break;
    }
}

//------------------------------------------------------------

void mouse(int button, int state, int x, int y)
{
	switch(button)
    {
    case GLUT_LEFT_BUTTON :
		if(state==GLUT_DOWN)
		{
			fprintf(stderr,"Clic gauche\n");
			P_addVertex(P,V_new(x,y,0));
		}
		break;

    case GLUT_MIDDLE_BUTTON :
		if(state==GLUT_DOWN)
			fprintf(stderr,"Clic milieu\n");
		break;

    case GLUT_RIGHT_BUTTON :
		if(state==GLUT_DOWN)
		{
			fprintf(stderr,"Clic droit.\n");
			if(P->_nb_vertices>0)
				P_removeLastVertex(P);
		}
		break;
    }
	glutPostRedisplay();
}

/*************************************************************************/
/* Fonction principale */
/*************************************************************************/

int main(int argc, char *argv[])
{
	P=malloc(sizeof(Polygon));
	P_init(P);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Transformations matricielles");
	glutDisplayFunc(display);
	//	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}
