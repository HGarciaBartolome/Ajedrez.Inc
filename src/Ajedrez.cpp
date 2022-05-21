#include "Mundo.h"
#include "freeglut.h"
#include "ETSIDI.h"

Mundo mundo;

void OnDraw(void); //Para dibujar
void OnTimer(int value); //Temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //Para pulsar tecla	
void OnSpecialKeyboardDown(int key, int x, int y);
void onMouse(int button, int state, int x, int y);//Para hacer click

int main(int argc,char* argv[])
{
	//Inicializa Glut y crea ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(OnSpecialKeyboardDown);
	glutMouseFunc(onMouse);
	mundo.inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	mundo.dibuja();
	
	glutSwapBuffers();
}



void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	mundo.tecla(key);

	glutPostRedisplay();
}

void OnSpecialKeyboardDown(int key, int x, int y)
{
}

void OnTimer(int value)
{
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

void onMouse(int button, int state, int x, int y)
{
	mundo.Mouse(button, state, x, y);
}