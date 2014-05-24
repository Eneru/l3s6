
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Affichage.c
\*======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glx.h>

#include "Vector.h"
#include "Maillage.h"

#define WIREFRAME 0
#define FLAT      1
#define SHADE     2
int draw = WIREFRAME;

/* dimensions de la fenetre */
int width = 600;
int height = 600;

Maillage Cube;

Vector p_aim;
float phi = -20;
float theta = 20;
GLfloat p_light[4];

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

	// glOrtho(-1,1,-1,1,-1,1);
	gluPerspective( 40, (float)width/height, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Pour tourner autour de l'objet
	glTranslatef(p_aim.x,p_aim.y,p_aim.z);
	glRotatef(theta,1,0,0);
	glRotatef(phi,0,1,0);

	// dessiner ici
	M_draw(&Cube);

	// Repere du monde
	glColor3d(1,0,0);
	drawLine(V_new(0,0,0),V_new(1,0,0));
	glColor3d(0,1,0);
	drawLine(V_new(0,0,0),V_new(0,1,0));
	glColor3d(0,0,1);
	drawLine(V_new(0,0,0),V_new(0,0,1));

	glutSwapBuffers();
}

//------------------------------------------------------------

void keyboard(unsigned char keycode, int x, int y)
{
	printf("Touche frapee : %c (code ascii %d)\n",keycode, keycode);
	/* touche ECHAP */
	if (keycode==27)
		exit(0);

	if(keycode=='a')
		switch(draw)
		{
		case WIREFRAME :
			draw = FLAT;
			Cube._is_filled = 0;
			glDisable(GL_LIGHTING);
			glEnable(GL_DEPTH_TEST);
			break;

		case FLAT :
			draw = SHADE;
			Cube._is_filled = 1;
			initShade();
			break;

		case SHADE :
			draw = WIREFRAME;
			Cube._is_filled = 1;
			glDisable(GL_LIGHTING);
			glDisable(GL_DEPTH_TEST);
			break;
		}

	glutPostRedisplay();
}

//------------------------------------------------------------
// Les touches flèches :
// sans autres modificateurs : la camera tourne autour de l'origine
// avec Shift : la camera se translate
// avec Ctrl : c'est la lumière qui se translate.

void special(int keycode, int x, int y)
{
	int mod = glutGetModifiers();
	switch(keycode)
    {
    case GLUT_KEY_UP        : if(mod==GLUT_ACTIVE_CTRL) p_light[1]+=1; else if(mod==GLUT_ACTIVE_SHIFT) p_aim.y+=.1; else theta-= 10; break;
    case GLUT_KEY_DOWN      : if(mod==GLUT_ACTIVE_CTRL) p_light[1]-=1; else if(mod==GLUT_ACTIVE_SHIFT) p_aim.y-=.1; else theta+= 10; break;
    case GLUT_KEY_LEFT      : if(mod==GLUT_ACTIVE_CTRL) p_light[0]-=1; else if(mod==GLUT_ACTIVE_SHIFT) p_aim.x-=.1; else phi-= 10; break;
    case GLUT_KEY_RIGHT     : if(mod==GLUT_ACTIVE_CTRL) p_light[0]+=1; else if(mod==GLUT_ACTIVE_SHIFT) p_aim.x+=.1; else phi+= 10; break;
    case GLUT_KEY_PAGE_UP   : if(mod==GLUT_ACTIVE_CTRL) p_light[2]-=1; else p_aim.z-=1; break;
    case GLUT_KEY_PAGE_DOWN : if(mod==GLUT_ACTIVE_CTRL) p_light[2]+=1; else p_aim.z+=1; break;
    default : fprintf(stderr,"function special : unknown keycode %d\n",keycode); break;
    }
	if(mod==GLUT_ACTIVE_CTRL)
		glLightfv(GL_LIGHT0, GL_POSITION, p_light);

	glutPostRedisplay();
}

//------------------------------------------------------------

void mouse(int button, int state, int x, int y)
{
  switch(button)
    {
    case GLUT_LEFT_BUTTON :
      if(state==GLUT_DOWN)
	  fprintf(stderr,"Clic gauche\n");
      break;

    case GLUT_MIDDLE_BUTTON :
      if(state==GLUT_DOWN)
	  fprintf(stderr,"Clic milieu\n");
      break;

    case GLUT_RIGHT_BUTTON :
      if(state==GLUT_DOWN)
	  fprintf(stderr,"Clic droit.\n");
      break;
    }
  glutPostRedisplay();
}

/*************************************************************************/
/* Fonction principale */
/*************************************************************************/

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Transformations matricielles");
  glutDisplayFunc(display);
  //	glutReshapeFunc(reshape);

  p_aim = V_new(0,0,-2.75);

  p_light[0]=2.0;
  p_light[1]=4.0;
  p_light[2]=1.0;

  M_init(&Cube);
  M_makeCube(&Cube);

  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special);
  glutMouseFunc(mouse);
  glutMainLoop();

  return 0;
}
