//============================================================================
// Name        : Agus Winarto Pratama
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define TimerMSecs 33
GLenum polygonMode = GL_FILL;

int SpinOn = 0, SpinBreak = 1, startTime, prevTime, Velocity = 1;
static int Mer = 0.0, Ven = 0.0, Ear = 0.0, Moo = 0.0, Moo2 = 0.0, Mar = 0.0, Jup =
0.0, Sat = 0.0, Ura = 0.0, Nep = 0.0, Plu = 0.0;
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0, lastx, lasty;
GLfloat Shine[] = {10};
GLfloat MooCol[] = {2.3, 2.3, 2.3};
GLfloat Moo2Col[] = {0.93, 0.93, 0.93};
GLfloat MerCol[] = {2.05, 1.90, 1.12};
GLfloat VenCol[] = {1.39, 0.54, 0.26};
GLfloat EarCol[] = {0.0, 0.3, 0.6};
GLfloat MarCol[] = {1.39, 0.26, 0.0};
GLfloat JupCol[] = {0.80, 0.53, 0.25};
GLfloat SatCol[] = {0.6, 0.5, 0.09};
GLfloat UraCol[] ={0.40, 0.900, 1.0};
GLfloat NepCol[] = {0.135, 0.115, 0.85};
GLfloat PluCol[] = {0.7, 0.8, 1.00};

void SceneSpin(int value)
{
  int currTime = glutGet(GLUT_ELAPSED_TIME);

  if(SpinOn == 1)
    glutTimerFunc(TimerMSecs, SceneSpin, 0);

  Mer += 11.0 * Velocity;
  if(Mer > 360.0)
    Mer = Mer - 360.0;

  Ven += 7.0 * Velocity;
  if(Ven > 360.0)
    Ven = Ven - 360.0;

  Ear += 5.0 * Velocity;
  if(Ear > 360.0)
    Ear = Ear - 360.0;

  Moo += 0.2 * Velocity;
  if(Moo > 360.0)
    Moo = Moo - 360.0;

  Moo2 += 0.1 * Velocity;
  if(Moo2 > 360.0)
    Moo2 = Moo2 - 360.0;

  Mar += 3.0 * Velocity;
  if(Mar > 360.0)
	  Mar = Mar - 360.0;

  Jup += 5.0 * Velocity;
  if(Jup > 360.0)
    Jup = Jup - 360.0;

  Sat += 1.0 * Velocity;
  if(Sat > 360.0)
    Sat = Sat - 360.0;

  Ura += 2.0 * Velocity;
  if(Ura > 360.0)
    Ura = Ura - 360.0;

  Nep += 1.0 * Velocity;
  if(Nep > 360.0)
    Nep = Nep - 360.0;

  Plu += 0.5 * Velocity;
  if(Plu > 360.0)
    Plu = Plu - 360.0;

glutPostRedisplay();
prevTime = currTime;
}

void draw(void)
{
  GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, Shine);

  glPushMatrix();

    gluLookAt(80.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();

//Membuat Merkurius
      glRotated((GLdouble) Mer, 0.0, 1.0, 0.0);

      glTranslated(0.0, 0.0, 4.9);

      glRotated((GLdouble) Mer, 0.0, 1.0, 0.0);

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MerCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, MerCol);

      glutSolidSphere(0.049, 20, 20);

      glDisable(GL_DIFFUSE);


    glPopMatrix();

    glPushMatrix();

//Membuat Venus
      glRotated((GLdouble) Ven, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 5.2);
glRotated((GLdouble) Ven - 1, 0.0, 1.0, 0.0); //Counter Rotation

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, VenCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, VenCol);

      glutSolidSphere(0.12, 20, 20);

      glDisable(GL_DIFFUSE);

    glPopMatrix();

    glPushMatrix();

//Membuat Bumi
      glRotated((GLdouble) Ear, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 5.6);

      glRotated((GLdouble) Ear, 0.0, 1.0, 0.0);

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, EarCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, EarCol);

      glutSolidSphere(0.13, 20, 20);

      glDisable(GL_DIFFUSE);

      glPushMatrix();

//Membuat Bulan / Satelit Bumi
        glRotated((GLdouble) Moo, 0.0, 1.0, 0.0);

        glTranslated(0.1, 0.0, 0.1);

        glRotated((GLdouble) Moo, 0.0, 1.0, 0.0);

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MooCol);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, MooCol);

        glutSolidSphere(0.02, 20, 20);

        glDisable(GL_DIFFUSE);

      glPopMatrix();

    glPopMatrix();

    glPushMatrix();

//Membuat Mars
      glRotated((GLdouble) Mar, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 6.0);

      glRotated((GLdouble) Mar, 0.0, 1.0, 0.0);

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MarCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, MarCol);

      glutSolidSphere(0.067, 20, 20);
glDisable(GL_DIFFUSE);

      glPushMatrix();

//Membuat Satelit 1 Mars
        glRotated((GLdouble) Moo, 0.0, 1.0, 0.0);

        glTranslated(0.0, 0.0, 0.1);

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MooCol);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, MooCol);

        glRotated((GLdouble) Moo, 0.0, 1.0, 0.0);

        glutSolidSphere(0.015, 20, 10);

      glPopMatrix();

      glPushMatrix();

//Membuat Satelit 2 Mars
        glRotated((GLdouble) Moo2, 0.0, 1.0, 0.0);

        glTranslated(0.0, 0.0, 0.15);

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Moo2Col);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Moo2Col);

        glRotated((GLdouble) Moo2, 0.0, 1.0, 0.0);

        glutSolidSphere(0.01, 20, 10);
      glPopMatrix();

    glPopMatrix();

    glPushMatrix();

//Membuat Jupiter
      glRotated((GLdouble) Jup, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 9.7);

      glRotated((GLdouble) Jup, 0.0, 1.0, 0.0);

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, JupCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, JupCol);

      glutSolidSphere(1.42, 20, 20);

      glDisable(GL_DIFFUSE);

    glPopMatrix();

    glPushMatrix();

//Membuat Saturnus
      glRotated((GLdouble) Sat, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 14.0);

      glRotated((GLdouble) Sat, 0.0, 1.0, 0.0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, SatCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, SatCol);

      glutSolidSphere(1.20, 20, 20);

      glDisable(GL_DIFFUSE);

    glPopMatrix();

    glPushMatrix();


//Membuat Uranus
      glRotated((GLdouble) Ura, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 23.5);

      glRotated((GLdouble) Ura - 1, 1.0, 0.1, 0.0); //Counter rotation
                  //top-to-bottom rotation
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, UraCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, UraCol);

      glutSolidSphere(0.51, 20, 20);

      glDisable(GL_DIFFUSE);

    glPopMatrix();

    glPushMatrix();


//Membuat Neptunus
      glRotated((GLdouble) Nep, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 34.5);

      glRotated((GLdouble) Nep, 0.0, 1.0, 0.0);

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, NepCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, NepCol);

      glutSolidSphere(0.49, 20, 20);

      glDisable(GL_DIFFUSE);

    glPopMatrix();

    glPushMatrix();

//Membuat Pluto
      glRotated((GLdouble) Plu, 0.0, 1.0, 0.0);

      glTranslated(0.1, 0.0, 44.0);

      glRotated((GLdouble) Plu, 0.0, 1.0, 0.0);

      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, PluCol);

      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, PluCol);

      glutSolidSphere(0.1, 20, 20);

      glDisable(GL_DIFFUSE);

      glPopMatrix();

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    GLfloat global_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Emission

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); //Emission

    glDisable(GL_LIGHTING);

    glColor3f(1.0, 1.0, 0.0);

    glRotated((GLdouble) Ear, 0.0, 1.0, 0.0);

    glutSolidSphere(4.00, 20, 20);

    glEnable(GL_LIGHTING);

    glPopMatrix();

}

void enable(void)
{

  glShadeModel(GL_SMOOTH);

  glEnable(GL_LIGHTING);

  glEnable(GL_LIGHT0);

  glEnable(GL_DEPTH_TEST);
}

void camera(void)
{
 glRotatef(xrot,1.0,0.0,0.0);
 glRotatef(yrot,0.0,1.0,0.0);
 glTranslated(-xpos,ypos,-zpos);
 glutPostRedisplay();
}

void display(void)
{
  glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    enable();
    draw();
    glutSwapBuffers();
  glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    angle++;
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 500.0);

  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
}
void WireFrameMode() {
 if (polygonMode == GL_FILL ) {
  polygonMode = GL_LINE;
 }
 else {
  polygonMode = GL_FILL;
 }
}
void Keyboard(unsigned char key, int A, int B)
{
   if(key == 'x')
    {
    xrot += 1;
    if(xrot > 360) xrot -= 360;
    }
  if(key == 'z')
   {
    xrot -= 1;
    if(xrot <-360) xrot += 360;
   }
  if(key == 'w')
   {
    float xrotrad,yrotrad;
    yrotrad = (yrot/180 * 3.141592654f);
      xrotrad = (xrot/180 * 3.141592654f);
      xpos += float(sin(yrotrad));
      zpos -= float(cos(yrotrad));
      ypos -= float(sin(xrotrad));
   }
  if(key == 's')
   {
   float xrotrad,yrotrad;
      yrotrad = (yrot/180 * 3.141592654f);
      xrotrad = (xrot/180 * 3.141592654f);
      xpos -= float(sin(yrotrad));
      zpos += float(cos(yrotrad));
      ypos += float(sin(xrotrad));
   }
  if(key == 'd')
   {
    yrot+=1;
    if(yrot>360) yrot -= 360;
   }
  if(key == 'a')
   {
    yrot -= 1;
    if(yrot<-360) yrot += 360;
   }
switch(key)
  {
  case '1':SpinOn = 1;
    if(SpinBreak == 0){
      SpinOn = 0;
    }
    if(SpinBreak == 1){
      glutTimerFunc(TimerMSecs, SceneSpin, 0);
    }
    if (SpinBreak == 0){
      SpinBreak = 1;
    }
    else SpinBreak = 0;
    break;

  case '2':SpinOn = 1;
    Velocity = Velocity + 1;
    break;

  case '3':SpinOn = 1;
    Velocity = Velocity - 1;
    break;

  case 27: exit(0);
    break;

  default:
    break;
  }
}

void mouseMenu(int value)
{
  if(value == 1)
  SpinOn = 1;
    if(SpinBreak == 0){
      SpinOn = 0;
    }
    if(SpinBreak == 1){
      glutTimerFunc(TimerMSecs, SceneSpin, 0);
    }
    if (SpinBreak == 0){
      SpinBreak = 1;
    }
    else SpinBreak = 0;

  if(value == 2)
    SceneSpin(2);

  if(value == 3)
    WireFrameMode();

  if(value == 4)
    exit(0);
}

void menu(void)
{
  printf("--------MENU--------\n");
  printf("Tekan 1 untuk start/pause\n");
  printf("Tekan 2 untuk meninggkatkan kecepatan\n");
  printf("Tekan 3 untuk menurunkan kecepatan\n");
  printf("Klik kanan untuk informasi lebih\n\n");
  printf("-----KONTROL KAMERA-----\n");
  printf("W A S D untuk maju mundur dan kanan kiri\n");
  printf("x dan z untuk zoom in dan zoom out\n\n");
  printf("-----------------------\n");
  printf("Tekan Esc untuk keluar\n");
  printf("-----------------------\n");
}


int main(int argc, char **argv)
{
  menu();
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(300, 300);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Sistem Tata Surya oleh kelompok 5 - IF 13");

  glutCreateMenu(mouseMenu);
  glutAddMenuEntry("Start/Pause", 1);
  glutAddMenuEntry("Langkah Animasi", 2);
  glutAddMenuEntry("Bingkai Kawat", 3);
  glutAddMenuEntry("Keluar", 4);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glEnable(GL_LIGHT_MODEL_AMBIENT);

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(Keyboard);

  startTime = glutGet(GLUT_ELAPSED_TIME);
  prevTime = startTime;

  glutMainLoop();
  return 0;
}
