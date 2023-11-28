#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Lector.h"
#include "Matriz.h"
#include "Bezier.h"
#include <random>

int NEstrellas = 228;
float grados = 0;
Modelo xwing, death, sol;
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
Vertice colorXwing(1.0, 0.5, 0.0, -1);
Vertice colorDeath(0.5, 0.5, 0.5, -1);
float intensidadAmb = 0.5;
float intensidadF1 = 0.8;
//origen, objetivo
Vertice f1[2] = { Vertice(0,0,20,-1), Vertice(0,0,0,-1) };

Vertice intensidadColor(Vertice v1, Vertice v2, Vertice v3, float IA, float IF, Vertice* F, Vertice color) {
	Vertice v1v2 = v1.getVector(v2);
	Vertice v1v3 = v1.getVector(v3);
	Vertice normal = v1v2.prodCross(v1v3);
	normal.normalizar();
	Vertice direccion = F[0].getVector(F[1]);
	direccion.normalizar();
	float factor = direccion.prodPoint(normal);
	float R = (IA * color.x) + (IF * factor);
	float G = (IA * color.y) + (IF * factor);
	float B = (IA * color.z) + (IF * factor);
	return Vertice(R, G, B, -1);
	
}

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

	glColor3f(1.0, 1.0, 1.0);
	for (int i = 2; i < NEstrellas; i++) {
		for (Cara cara : modelos[i].caras) {
			Vertice v;
			v = modelos[i].getVertice(cara.v1);
			glVertex3f(v.getX(), v.getY(), v.getZ());
			v = modelos[i].getVertice(cara.v2);
			glVertex3f(v.getX(), v.getY(), v.getZ());
			v = modelos[i].getVertice(cara.v3);
			glVertex3f(v.getX(), v.getY(), v.getZ());
		}
	}
	glColor3f(0.9, 1.0, 0.4);

	for (Cara cara : sol.caras) {
		Vertice v;
		Matriz m(b1.getPoint());
		v = sol.getVertice(cara.v1);
		glVertex3f(v.getX(), v.getY(), v.getZ());
		v = sol.getVertice(cara.v2);
		glVertex3f(v.getX(), v.getY(), v.getZ());
		v = sol.getVertice(cara.v3);
		glVertex3f(v.getX(), v.getY(), v.getZ());
	}

	glColor3f(0.5, 0.5, 0.5);
	for (Cara cara : death.caras) {
		Vertice v1, v2, v3, v;

		v = death.getVertice(cara.v1);
		v1.setPuntos(r.multiplicar(v.getVertices()));
		v = death.getVertice(cara.v2);
		v2.setPuntos(r.multiplicar(v.getVertices()));
		v = death.getVertice(cara.v3);
		v3.setPuntos(r.multiplicar(v.getVertices()));
		Vertice c = intensidadColor(v1, v2, v3, intensidadAmb, intensidadF1, f1, colorDeath);
		glColor3f(c.x, c.y, c.z);
		glVertex3f(v1.getX(), v1.getY(), v1.getZ());
		glVertex3f(v2.getX(), v2.getY(), v2.getZ()); 
		glVertex3f(v3.getX(), v3.getY(), v3.getZ());
		r.incrementar();
	}

	glColor3f(1.0, 0.5, 0.0);

	if (b1.get_t() < 1) {
		for (Cara cara : xwing.caras) {
			Vertice v, v1, v2, v3;
			Matriz m(b1.getPoint());
			v = xwing.getVertice(cara.v1);
			v1.setPuntos(r2.multiplicar(v.getVertices()));
			v1.setPuntos(m.multiplicar(v1.getVertices()));

			v = xwing.getVertice(cara.v2);
			v2.setPuntos(r2.multiplicar(v.getVertices()));
			v2.setPuntos(m.multiplicar(v2.getVertices()));

			v = xwing.getVertice(cara.v3);
			v3.setPuntos(r2.multiplicar(v.getVertices()));
			v3.setPuntos(m.multiplicar(v3.getVertices()));

			Vertice c = intensidadColor(v1, v2, v3, intensidadAmb, intensidadF1, f1, colorXwing);
			glColor3f(c.x, c.y, c.z);

			glVertex3f(v1.getX(), v1.getY(), v1.getZ());
			glVertex3f(v2.getX(), v2.getY(), v2.getZ());
			glVertex3f(v3.getX(), v3.getY(), v3.getZ());
			b1.incrementar();
			r2.incrementar();
		}
	}
	else {
		if (b2.get_t() < 1) {
			for (Cara cara : xwing.caras) {
				Vertice v, v1, v2, v3;
				Matriz m(b2.getPoint());
				v = xwing.getVertice(cara.v1);
				v1.setPuntos(r2.multiplicar(v.getVertices()));
				v1.setPuntos(m.multiplicar(v1.getVertices()));

				v = xwing.getVertice(cara.v2);
				v2.setPuntos(r2.multiplicar(v.getVertices()));
				v2.setPuntos(m.multiplicar(v2.getVertices()));

				v = xwing.getVertice(cara.v3);
				v3.setPuntos(r2.multiplicar(v.getVertices()));
				v3.setPuntos(m.multiplicar(v3.getVertices()));

				Vertice c = intensidadColor(v1, v2, v3, intensidadAmb, intensidadF1, f1, colorXwing);
				glColor3f(c.x, c.y, c.z);

				glVertex3f(v1.getX(), v1.getY(), v1.getZ());
				glVertex3f(v2.getX(), v2.getY(), v2.getZ());
				glVertex3f(v3.getX(), v3.getY(), v3.getZ());
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
	sol = modelos[NEstrellas+2];

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
	gluLookAt(80, 10, 0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//gluLookAt(0, 10,90, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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