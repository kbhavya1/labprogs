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
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  glBegin(GL_TRIANGLES);
		glVertex2f(100,300);
		glVertex2f(150,450);
		glVertex2f(200,300);
    glEnd();
   
  glColor3f(0,1,0);
   glBegin(GL_QUADS);
		glVertex2f(100,300);
		glVertex2f(200,300);
		glVertex2f(200,100);
		glVertex2f(100,100);
		
        glEnd();
  glColor3f(0,0,1);
   glBegin(GL_QUADS);
		glVertex2f(120,200);
		glVertex2f(180,200);
		glVertex2f(180,100);
		glVertex2f(120,100);
		
        glEnd();
	glFlush();
}
