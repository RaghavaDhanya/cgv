#include <stdio.h>
#include <math.h>
#include <gl/glut.h>
GLfloat house[3][9]={{100,100,175,250,250,150,150,200,200},
					{100,300,400,300,100,100,150,150,100},
					{1,1,1,1,1,1,1,1,1}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h=100,k=100,theta;
void multiply()
{
	int i,j,l;
	for(i=0;i<3;++i)
		for(j=0;j<9;++j)
		{
			result[i][j]=0;
			for(l=0;l<3;++l)
				result[i][j]=result[i][j]+rot_mat[i][l]*house[l][j];
		}
}
void rotate()
{
	GLfloat m,n;
	m=-h*(cos(theta)-1)+k*(sin(theta));
	n=-k*(cos(theta)-1)-h*(sin(theta));
	rot_mat[0][0]=cos(theta);
	rot_mat[0][1]=-sin(theta);
	rot_mat[0][2]=m;
	rot_mat[1][0]=sin(theta);
	rot_mat[1][1]=cos(theta);
	rot_mat[1][2]=n;
	rot_mat[2][0]=0;
	rot_mat[2][1]=0;
	rot_mat[2][2]=1;
	multiply();
}
void drawhouse(GLfloat a[][9])
{
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(a[0][0],a[1][0]);
		glVertex2f(a[0][1],a[1][1]);
		glVertex2f(a[0][3],a[1][3]);
		glVertex2f(a[0][4],a[1][4]);
	glEnd();
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(a[0][5],a[1][5]);
		glVertex2f(a[0][6],a[1][6]);
		glVertex2f(a[0][7],a[1][7]);
		glVertex2f(a[0][8],a[1][8]);
	glEnd();
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(a[0][1],a[1][1]);
		glVertex2f(a[0][2],a[1][2]);
		glVertex2f(a[0][3],a[1][3]);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawhouse(house);
	rotate();
	drawhouse(result);
	glFlush();
}
void myinit()
{
	glClearColor(1,1,1,1);
	glColor3f(1,0,0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,499,0,499);
}
void main(int argc, char ** argv)
{
	printf("Enter angle\n");
	scanf("%f",&theta);
	theta=theta*3.141592/180;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("house rotation");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}