//#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void) 
{
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void display(void)
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat light_position2[] = { 0.0, 1.0, 1.0, 1.0 };
   GLfloat light_position3[] = { 0.0, 1.0, 1.0, 0.0 };
   GLfloat light_position4[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat light_position5[] = { 1.0, 0.0, 1.0, 1.0 };
   GLfloat light_position6[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat light_position7[] = { 1.0, 0.0, 0.0, 0.0 };
   GLfloat light_position8[] = { 0.0, 0.0, 1.0, 0.0 };

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix();
      glTranslatef (-3.75, 3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (-1.25, 3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (1.25, 3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (3.75, 3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position4);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (-3.75, -3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position5);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (-1.25, -3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position6);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (1.25, -3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position7);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glPushMatrix();
      glTranslatef (3.75, -3.0, 0.0);
      glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position8);
      glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glFlush ();
}

void reshape (int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= (h * 2))
      glOrtho (-6.0, 6.0, -3.0*((GLfloat)h*2)/(GLfloat)w, 
         3.0*((GLfloat)h*2)/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-6.0*(GLfloat)w/((GLfloat)h*2), 
         6.0*(GLfloat)w/((GLfloat)h*2), -3.0, 3.0, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
