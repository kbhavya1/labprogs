#include<GL/glut.h>

void init();
void display();

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
  glutCreateWindow("line");
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}

void init()
{
  gluOrtho2D(0,500,0,500);
} 

void display()
{
  glClearColor(1,1,1,1);
  int a,b=100;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  for(a=0;a<100;a++){
  glBegin(GL_POINTS);
         glVertex2f(a,b);
		
    glEnd();
}

glFlush();
   
}
