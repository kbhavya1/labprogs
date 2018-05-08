#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
float f[8][3]={{-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1},{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1}};
float theta[]={0,0,0};
float viewer[]={0,0,5};
int axis=2;
void polygon(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
	glVertex3fv(f[a]);
	glVertex3fv(f[b]);
	glVertex3fv(f[c]);
	glVertex3fv(f[d]);	
	glEnd();
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
void init()
{
	
	glMatrixMode(GL_PROJECTION);
        glFrustum(-2,2,-2,2,2,20);
	glMatrixMode(GL_MODELVIEW);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glClearColor(0,0,0,1);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
	glRotatef(theta[0],1,0,0);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[2],0,0,1);
	colorcube();
	glEnd();
	glFlush();
	glutSwapBuffers();
}
/*void spincube()
{
	
	theta[axis]+=1.0;
	if(theta[axis]>360)
		theta[axis]-=360;
	glutPostRedisplay();
}*/
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
		axis=0;
	if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
		axis=1;
	if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
		axis=2;
}

void keys(unsigned char key,int x,int y)
{
  if(key=='x') viewer[0]-=1.0;
  if(key=='X') viewer[0]+=1.0;
  if(key=='y') viewer[1]-=1.0;
  if(key=='Y') viewer[1]+=1.0;
  if(key=='z') viewer[2]-=1.0;
  if(key=='Y') viewer[2]+=1.0;
  glutPostRedisplay();
}

/*void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-10,10);
	
	glMatrixMode(GL_MODELVIEW);
}*/



void main(int argc,char** argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("CUBE");
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	init();
	glutDisplayFunc(display);
	//glutIdleFunc(spincube);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	//glutReshapeFunc(reshape);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

}
