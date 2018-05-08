#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>

float f[8][3]={{-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1},{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1}};

float theta[] = {0,0,0};
 int axis = 2;

void polygon(int a,int b,int c,int d)
{
 glBegin(GL_POLYGON);
 glVertex3fv(f[a]);
 glVertex3fv(f[b]);
 glVertex3fv(f[c]);
 glVertex3fv(f[d]);
 glEnd();

}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-5,5);
	glMatrixMode(GL_MODELVIEW);
}
void colorcube()
{
	glColor3f(1,0,0);
	polygon(4,5,6,7);
	glColor3f(1,0,1);
	polygon(0,4,7,3);
	glColor3f(1,1,0);
	polygon(1,5,6,2);
	glColor3f(0,1,0);
	polygon(7,3,2,6);
	glColor3f(1,1,1);
	polygon(0,4,5,1);
	glColor3f(0,1,1);
	polygon(0,1,2,3);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,1);
	glColor3f(0,0,1);
	glRotatef(45,1,0,0);
	colorcube();
	
	glFlush();
}

void main(int argc,char** argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("CUBE");
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	init();
	glutDisplayFunc(display);
        glEnable(GL_DEPTH_TEST);
        glutMainLoop();
}

