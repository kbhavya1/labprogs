#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>

float v[4][3] = {{0,0,1},{-1,-1,-1},{1,-1,-1},{0,1,-1}};
float theta[3]={0,0,0};
int axis=2;
int m;

void triangle(float *a,float *b,float *c)
{
	glBegin(GL_TRIANGLES);
	//glColor3f(1,0,1);
	glVertex3fv(a);
	//glColor3f(1,0,0);
	glVertex3fv(b);
	//glColor3f(0,0,1);
	glVertex3fv(c);
	glEnd();
}

void tetrahedran(int m)
{	glColor3f(1,0,1);
	divide_triangle(v[0],v[1],v[3],m);
	glColor3f(1,0,0);
	divide_triangle(v[1],v[2],v[0],m);
	glColor3f(0,0,1);
	divide_triangle(v[0],v[2],v[3],m);
	glColor3f(1,1,0);
	divide_triangle(v[1],v[2],v[3],m);
}


void divide_triangle(float *a,float *b,float *c,int m)
{
	float v1[3],v2[3],v3[3];
	if(m>0)
	{
		for(int i=0;i<3;i++)
		v1[i]=(a[i]+b[i])/2;
		for(int i=0;i<3;i++)	
		v2[i]=(b[i]+c[i])/2;
		for(int i=0;i<3;i++)
		v3[i]=(a[i]+c[i])/2;

		divide_triangle(a,v1,v3,m-1);
		divide_triangle(b,v1,v2,m-1);
		divide_triangle(c,v2,v3,m-1);
	}
	else
	{
		triangle(a,b,c);
	}
}

void init()
{	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-10,20);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	tetrahedran(m);
	
	glFlush();
}	

void spincube()
{
	theta[axis]+=1.0;
	if(theta[axis]>360)
	theta[axis]-=360;
	glutPostRedisplay();
}
void main(int argc,char **argv)
{
	printf("ENTER THE NUMBER OF DIVISIONS\n");
	scanf("%d",&m);	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Tetrahedran");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(spincube);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

