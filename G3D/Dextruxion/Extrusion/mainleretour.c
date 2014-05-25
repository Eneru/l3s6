/**
* \file main.c
* \brief main
* \author SCHIMCHOWITSCH Raphael
* \author HABIBI Arash
* \date 2014
* \copyright WTFPL version 2
*/
/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glx.h>

#include "Vector.h"
#include "Polygon.h"
#include "Mesh.h"

#define DIM2 0
#define DIM3 1
int dim=DIM2;
Quad q;
/* dimensions de la fenetre */
int width = 650;
int height = 650;

GLfloat p_light[4];

Polygon *p;
Mesh *m;

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

void drawLine(Vector p1, Vector p2)
{
glBegin(GL_LINES);
glVertex3d(p1.x,p1.y,p1.z);
glVertex3d(p2.x,p2.y,p2.z);
glEnd();
}

//------------------------------------------------------------

void initShade()
{
GLfloat mat_diffuse[] = {1,1,1,1.0};
GLfloat mat_ambient[] = {0.1,0.1,0.1,0.0};

glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
glLightfv(GL_LIGHT0, GL_POSITION, p_light);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);
}


/*************************************************************************/
/* Fonctions callback */
/*************************************************************************/

void display()
{
glEnable(GL_DEPTH_TEST);
glDepthMask(GL_TRUE);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

if(dim==DIM2)	glOrtho(-1,1,-1,1,-1,1);
else	gluPerspective( 40, (float)width/height, 1, 100);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

// Dessiner ici
// ...

// Repere du monde
Q_draw(&q);
//M_perlinExtrude(m, p, 4);

//drawRepere();

glutSwapBuffers();
}

//------------------------------------------------------------

void keyboard(unsigned char keycode, int x, int y)
{
printf("Touche frapee : %c (code ascii %d)\n",keycode, keycode);
/* touche ECHAP */
if (keycode==27)
exit(0);
if (keycode==99)
p->_is_closed = !p->_is_closed;
if (keycode==102)
if (p->_is_closed)
p->_is_filled = !p->_is_filled;

glutPostRedisplay();
}

//------------------------------------------------------------

void special(int keycode, int x, int y)
{
int mod = glutGetModifiers();
switch(keycode)
{
case GLUT_KEY_UP : printf("Flèche haut\n"); break;
case GLUT_KEY_DOWN : printf("Flèche bas\n"); break;
case GLUT_KEY_LEFT : printf("Flèche gauche\n"); break;
case GLUT_KEY_RIGHT : printf("Flèche droite\n"); break;
case GLUT_KEY_PAGE_UP : printf("Flèche avant\n"); break;
case GLUT_KEY_PAGE_DOWN : printf("Flèche arriere\n"); break;
default : fprintf(stderr,"function special : unknown keycode %d\n",keycode); break;
}
if(mod==GLUT_ACTIVE_CTRL)
glLightfv(GL_LIGHT0, GL_POSITION, p_light);
}

//------------------------------------------------------------

void ajouterClick(Polygon *p, int x, int y){
Vector v = V_new(x,y,p->_nb_vertices);
P_addVertex(p,v,p->_nb_vertices);
}


void mouse(int button, int state, int x, int y)
{
switch(button)
{
case GLUT_LEFT_BUTTON :
if(state==GLUT_DOWN){
fprintf(stderr,"Clic gauche%d %d\n", x,y);
ajouterClick(p,x,y);
//P_print(p, NULL);

}
break;

case GLUT_MIDDLE_BUTTON :
if(state==GLUT_DOWN)
fprintf(stderr,"Clic milieu\n");
break;

case GLUT_RIGHT_BUTTON :
if(state==GLUT_DOWN){
fprintf(stderr,"Clic droit.\n");
P_removeLastVertex(p);
}
break;
}
glutPostRedisplay();
}

//------------------------------------------------------------

void idle()
{
// animation du personnage ici

glutPostRedisplay();
}

/*************************************************************************/
/* Fonction principale */
/*************************************************************************/

int main(int argc, char *argv[])
{
p=P_new();
m=M_new();
Vector v1= V_new(0.5,0.0,0.3);
Vector v2= V_new(0.500,0.500,0.5);
Vector v3= V_new(0.402,0.3,0);
Vector v4= V_new(0.16,0.88,0);
q=Q_new(v1,v2,v3,v4);
M_addQuad(m, q);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize(width, height);
glutInitWindowPosition(50, 50);
glutCreateWindow("Transformations matricielles");
glViewport(0, 0, width, height);
glClearColor(0,0,0,0);

glutDisplayFunc(display);
// glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutSpecialFunc(special);
glutMouseFunc(mouse);
glutIdleFunc(idle);

p_light[0]=-10.0;
p_light[1]=20.0;
p_light[2]=0.0;
p_light[3]=1.0;

//~ p_aim = V_new(0,0,-2.75);
//~ P = P_new();
//~ M = NULL;

glutMainLoop();

return 0;
}
