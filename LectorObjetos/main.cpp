#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Lector.h"
#include "Matriz.h"

float grados = 0;
Lector lector;
vector<Modelo> modelos;
Vertice v;
Matriz t(0.0, 0.0, 0.0, t.MATRIZ_TRASLACION);
Matriz r(10, r.EJE_Y);


void display(void)
{

	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*for (Modelo modelo : modelos) {
		for (Cara cara : modelo.caras) {
			v = modelo.getVertice(cara.v1);
			v.setPuntos(t.multiplicar(v.getVertices()));
			v = modelo.getVertice(cara.v2);
			v.setPuntos(t.multiplicar(v.getVertices()));
			v = modelo.getVertice(cara.v3);
			v.setPuntos(t.multiplicar(v.getVertices()));
		}
	}*/
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	for (Modelo modelo : modelos) {
		for (Cara cara : modelo.caras) {
			Vertice v2;
			v = modelo.getVertice(cara.v1);
			v2.setPuntos(r.multiplicar(v.getVertices()));
			glVertex3f(v2.getX(), v2.getY(), v2.getZ());
			v = modelo.getVertice(cara.v2);
			v2.setPuntos(r.multiplicar(v.getVertices()));
			glVertex3f(v2.getX(), v2.getY(), v2.getZ());
			v = modelo.getVertice(cara.v3);
			v2.setPuntos(r.multiplicar(v.getVertices()));
			glVertex3f(v2.getX(), v2.getY(), v2.getZ());
			r.incrementar();
		}
	}
	glEnd();

	glutSwapBuffers();
	glFlush();
}

void init(void)
{
	modelos = lector.leerArchivo("pokemon.obj");

	/*  select clearing (background) color       */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	//gluOrtho2D(0.0, 1.0, 0.0, 1.0);

	gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 27, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glEnable(GL_DEPTH_TEST);

}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();

	glutDisplayFunc(display);
	//glutPostRedisplay();
	glutIdleFunc(display);
	glutMainLoop();

	return 0;   /* ISO C requires main to return int. */
}