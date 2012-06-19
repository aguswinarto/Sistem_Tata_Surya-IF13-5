/*
 * bola.c
 *
 *  Created on: Jun 19, 2012
 *      Author: Wyne
 */
#include <stdio.h>
#include <GL/glut.h>

void reshape(int w, int h)
{

	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


