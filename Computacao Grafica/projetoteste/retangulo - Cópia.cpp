#include <iostream>
#include <GL/glut.h>

const int   A = 500;  /* length of a side of the monitor window */
const float B = 500;  /* length of a side of the clipping rectangle */
const float C = 200;  /* length of a side of the square the program draws */

void myinit(void)
{
  glClearColor(0.62, 0.37, 0.62, 0.0); /* violet blue background */
 
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  gluOrtho2D( -B/2, B/2, -B/2, B/2);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void display( void )
{
                                    
  glClear(GL_COLOR_BUFFER_BIT);     /* clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */
  
	 /*
     glColor3f(0.62, 0.37, 0.62); //azul-violeta
     glBegin (GL_POLYGON); //desenha um losango
         glVertex2f (0.9, 0.5);
         glVertex2f (0.5, 0.9);
         glVertex2f (0.1, 0.5);
         glVertex2f (0.5, 0.1);
     glEnd();
     
     glColor3f (1.0, 0.73, 0.07); //vermelho-laranja
     glRectf (0.25, 0.25, 0.75, 0.75); //desenha um retangulo
	 */
	 
  glBegin(GL_POLYGON) ;             /* draw a filled polygon */
      glColor3f ( 1.0, 0.73, 0.07);       /* draw in orange red */
      glVertex2f( -C/2, -C/2 );         /* (x,y) */
      glVertex2f(  C/2, -C/2 );         /* (x,y) */
      glVertex2f(  C/2,  C/2 );         /* (x,y) */
      glVertex2f( -C/2,  C/2 );         /* (x,y) */
  glEnd();

  glFlush();                        /* send all commands */
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize( A, A );       /* A x A pixel screen window  */

  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
  glutCreateWindow("My Rectangle"); /* window title                   */
  glutDisplayFunc(display);         /* tell OpenGL main loop what     */
  myinit();                         /* set attributes                 */

  glutMainLoop();                   /* pass control to the main loop  */
  return 0;
}
