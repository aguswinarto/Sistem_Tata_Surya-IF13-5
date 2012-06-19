/*
 * kamera.c
 *
 *  Created on: Jun 19, 2012
 *      Author: mydle
 */
#include <GL/glut.h>

void camera(void)
{
	float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0;

 glRotatef(xrot,1.0,0.0,0.0);
 glRotatef(yrot,0.0,1.0,0.0);
 glTranslated(-xpos,ypos,-zpos);
 glutPostRedisplay();
}
