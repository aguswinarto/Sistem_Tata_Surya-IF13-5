/*
 * cahaya.c
 *
 *  Created on: Jun 19, 2012
 *      Author: Wyne
 */
#include <stdio.h>
#include <GL/glut.h>

void enable(void)
{

  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
}



