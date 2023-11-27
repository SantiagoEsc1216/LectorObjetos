#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Lector.h"
#include "Matriz.h"
#include "Bezier.h"

float grados = 0;
Modelo xwing, death;
vector<Modelo> modelos;
Matriz po1(0.0, 0.0, 10.0, Matriz::MATRIZ_TRASLACION);
Matriz pmModelo1;
Matriz p0(0, 0, 0, Matriz::MATRIZ_TRASLACION);
Matriz r(0.001, r.EJE_Y);
Matriz r2(-0.0016, r.EJE_Y);
Vertice c1[4] = { Vertice(0, 0, -10, -1), Vertice(10, 0, -10, -1), Vertice(10, 0, 10, -1), Vertice(0, 0, 10, -1) };
Vertice c2[4] = { Vertice(0, 0, 10, -1), Vertice(-10, 0, 10, -1),  Vertice(-10, 0, -10, -1),  Vertice(0, 0, -10, -1) };
Bezier b1(c1, 0.00001);
Bezier b2(c2, 0.00001);

void display(void)
{

	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	/*for (Modelo modelo : modelos) {
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
	}*/

	glColor3f(0.5, 0.5, 0.5);
	for (Cara cara : death.caras) {
		Vertice v;
		Vertice v2;
		v = death.getVertice(cara.v1);
		v2.setPuntos(r.multiplicar(v.getVertices()));
		glVertex3f(v2.getX(), v2.getY(), v2.getZ());
		v = death.getVertice(cara.v2);
		v2.setPuntos(r.multiplicar(v.getVertices()));
		glVertex3f(v2.getX(), v2.getY(), v2.getZ());
		v = death.getVertice(cara.v3);
		v2.setPuntos(r.multiplicar(v.getVertices()));
		glVertex3f(v2.getX(), v2.getY(), v2.getZ()); 
		r.incrementar();
	}

	glColor3f(1.0, 0.5, 0.0);

	if (b1.get_t() < 1) {
		for (Cara cara : xwing.caras) {
			Vertice v;
			Vertice v2;
			Matriz m(b1.getPoint());
			v = xwing.getVertice(cara.v1);
			v2.setPuntos(r2.multiplicar(v.getVertices()));
			v2.setPuntos(m.multiplicar(v2.getVertices()));
			glVertex3f(v2.getX(), v2.getY(), v2.getZ());
			v = xwing.getVertice(cara.v2);
			v2.setPuntos(r2.multiplicar(v.getVertices()));
			v2.setPuntos(m.multiplicar(v2.getVertices()));
			glVertex3f(v2.getX(), v2.getY(), v2.getZ());
			v = xwing.getVertice(cara.v3);
			v2.setPuntos(r2.multiplicar(v.getVertices()));
			v2.setPuntos(m.multiplicar(v2.getVertices()));
			glVertex3f(v2.getX(), v2.getY(), v2.getZ());
			b1.incrementar();
			r2.incrementar();
		}
	}
	else {
		if (b2.get_t() < 1) {
			for (Cara cara : xwing.caras) {
				Vertice v;
				Vertice v2;
				Matriz m(b2.getPoint());
				v = xwing.getVertice(cara.v1);
				v2.setPuntos(r2.multiplicar(v.getVertices()));
				v2.setPuntos(m.multiplicar(v2.getVertices()));
				glVertex3f(v2.getX(), v2.getY(), v2.getZ());
				v = xwing.getVertice(cara.v2);
				v2.setPuntos(r2.multiplicar(v.getVertices()));
				v2.setPuntos(m.multiplicar(v2.getVertices()));
				glVertex3f(v2.getX(), v2.getY(), v2.getZ());
				v = xwing.getVertice(cara.v3);
				v2.setPuntos(r2.multiplicar(v.getVertices()));
				v2.setPuntos(m.multiplicar(v2.getVertices()));
				glVertex3f(v2.getX(), v2.getY(), v2.getZ());
				b2.incrementar();
				r2.incrementar();
			}
		}
		else {
			b1.reset();
			b2.reset();
		}
	}

	glEnd();

	glutSwapBuffers();
	glFlush();
}

void init(void)
{
	Lector lector;
	modelos = lector.leerArchivo("proyectoLow.obj");
	float cv = 0;
	float tx, ty, tz, x, y ,z;
	tx = ty = tz = 0;

	death = modelos[1];
	xwing = modelos[0];
	for (Cara cara : xwing.caras) {
		Vertice v;
		Matriz m(b1.getPoint());
		v = xwing.getVertice(cara.v1);
		v.setPuntos(m.multiplicar(v.getVertices()));
		tx += v.getX();
		ty += v.getY();
		tz += v.getZ();
		v = xwing.getVertice(cara.v2);
		v.setPuntos(m.multiplicar(v.getVertices()));
		tx += v.getX();
		ty += v.getY();
		tz += v.getZ();
		v = xwing.getVertice(cara.v3);
		v.setPuntos(m.multiplicar(v.getVertices()));
		tx += v.getX();
		ty += v.getY();
		tz += v.getZ();
		cv += 3;
	}
	x = tx / (cv * 3);
	y = ty / (cv * 3);
	z = tz / (cv * 3);



	pmModelo1.setMatriz(x, y, z, Matriz::MATRIZ_TRASLACION);

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

	//gluLookAt(5, 30, 0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(30, 10, 0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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