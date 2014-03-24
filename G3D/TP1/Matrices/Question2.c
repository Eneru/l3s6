#include <GL/glut.h>
#include <GL/glx.h>
#include <stdlib.h>
#include <stdio.h>

/* Variables globales */
int coef = 5;
int phi = 0;
int theta = 0;

/* dimensions de la fenetre */
int width = 600;
int height = 400;

//------------------------------------------------------------

typedef struct
{
	float x, y, z;
} Vector;

//------------------------------------------------------------

Vector V_new(float x, float y, float z)
{
	Vector p;
	p.x = x;
	p.y = y;
	p.z = z;
	return p;
}

/*************************************************************************/
/* Fonctions de dessin */
/*************************************************************************/

/* rouge vert bleu entre 0 et 1 */
void chooseRandomColor()
{
  glColor3d(drand48(),drand48(),drand48());
}

//------------------------------------------------------------

void chooseColor(double r, double g, double b)
{
  glColor3d(r,g,b);
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

void drawQuad(Vector p1, Vector p2, Vector p3, Vector p4)
{
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_QUADS);
		glVertex3f(p1.x,p1.y,p1.z);
		glVertex3f(p2.x,p2.y,p2.z);
		glVertex3f(p3.x,p3.y,p3.z);
		glVertex3f(p4.x,p4.y,p4.z);
  glEnd();
}

//------------------------------------------------------------

void drawCube()
{
	Vector p1,p2,p3,p4,p5,p6,p7,p8;
	p1 = V_new(-0.5,-0.5,-0.5);
	p2 = V_new(0.5,-0.5,-0.5);
	p3 = V_new(0.5,0.5,-0.5);
	p4 = V_new(-0.5,0.5,-0.5);
	p5 = V_new(-0.5,-0.5,0.5);
	p6 = V_new(0.5,-0.5,0.5);
	p7 = V_new(0.5,0.5,0.5);
	p8 = V_new(-0.5,0.5,0.5);
	
	chooseRandomColor();
	drawQuad(p1,p2,p6,p5);
	
	chooseRandomColor();
	drawQuad(p1,p2,p3,p4);
	
	chooseRandomColor();
	drawQuad(p1,p4,p8,p5);
	
	chooseColor(0,1,0);
	drawQuad(p4,p8,p7,p3);
	
	chooseColor(1,0,0);
	drawQuad(p2,p3,p7,p6);
	
	chooseColor(0,0,1);
	drawQuad(p5,p6,p7,p8);
}


/*************************************************************************/
/* Fonctions callback */
/*************************************************************************/

void dessiner_caractere ()
{		
	//Torse
	glRotatef(phi,0,1,0);
	glPushMatrix();
	glScalef(1,1.5,0.5);
	drawCube();
	glPopMatrix();
	
	//Bras Gauche
	glPushMatrix();
		glTranslatef(-0.5,0.75,0);
		glRotatef(-(theta)-30,0,0,1);
		glTranslatef(0,-0.5,0);
		glScalef(0.35,1,0.5);
		drawCube();
	glPopMatrix();
	
	//Bras Droit
	glPushMatrix();
		glTranslatef(0.5,0.75,0);
		glRotatef(theta+30,0,0,1);
		glTranslatef(0,-0.5,0);
		glScalef(0.35,1,0.5);
		drawCube();
	glPopMatrix();
	
	//Tete
	glPushMatrix();
		glTranslatef(0.0,1.15,0.0);
		glScalef(0.5,0.5,0.25);
		drawCube();
	glPopMatrix();
	
	//Jambe Droite
	glPushMatrix();
		glTranslatef(0.5,-1,0);
		glRotatef(30,0,0,1);
		glScalef(0.5,1.25,0.5);
		drawCube();
	glPopMatrix();
	
	//Jambe Gauche
	glPushMatrix();
		glTranslatef(-0.5,-1,0);
		glRotatef(-30,0,0,1);
		glScalef(0.5,1.25,0.5);
		drawCube();
	glPopMatrix();
	
	//Sol
	glPushMatrix();
		glTranslatef(0,-2,0);
		glScalef(10,0.001,10);
		drawCube();
	glPopMatrix();
}

void display()
{
	srand48(1); // Seulement pour la couleur aleatoire.

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 60, (float)width/height, 1, 100);
	gluLookAt(2,2,4,0,0,0,0,1,0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Repere du monde
	chooseColor(1,0,0);
	drawLine(V_new(0,0,0),V_new(1,0,0));
	chooseColor(0,1,0);
	drawLine(V_new(0,0,0),V_new(0,1,0));
	chooseColor(0,0,1);
	drawLine(V_new(0,0,0),V_new(0,0,1));
		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	dessiner_caractere();
		
	glutSwapBuffers();
}

//------------------------------------------------------------

void keyboard(unsigned char keycode, int x, int y)
{
	printf("Touche frapee : %c (code ascii %d)\n",keycode, keycode);
	switch(keycode)
	{
		case 'a' : coef++; break; // a
		
		case 'A' : coef--; break; // A
		
		case 'q' : // q
		
		case 'Q' : exit(0); break; // Q
		
		case 'f' : phi+=10 ; break; // f
		
		case 'F' : phi-=10 ; break; // F
		
		case 't' : theta+=10 ; break; // t
		
		case 'T' : theta-=10 ; break; // T
	}
	glutPostRedisplay();
}

//------------------------------------------------------------

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("Clic at %d %d\n",x,y);
		glutPostRedisplay();
	}

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
	/* Initialisations globales */
	glutInit(&argc, argv);

	/* Définition des attributs de la fenetre OpenGL */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	/* Placement de la fenetre */
	glutInitWindowSize(width, height);
	glutInitWindowPosition(50, 50);

	/* Création de la fenetre */
    glutCreateWindow("Transformations matricielles");

	/* Choix de la fonction d'affichage */
	glutDisplayFunc(display);

	/* Choix de la fonction de redimensionnement de la fenetre */
//	glutReshapeFunc(reshape);

	/* Choix des fonctions de gestion du clavier */
	glutKeyboardFunc(keyboard);
	//glutSpecialFunc(special);

	/* Choix de la fonction de gestion de la souris */
	glutMouseFunc(mouse);

  /* Choix de la fonction qui sera appelée
     lorsqu'il n'y a pas d'autres événements */
	glutIdleFunc(idle);

	/* Boucle principale */
	glutMainLoop();

	/* Même si glutMainLoop ne rends JAMAIS la main,
	   il faut définir le return, sinon
	   le compilateur risque de crier */
    return 0;
}
