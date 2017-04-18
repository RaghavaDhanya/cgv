#include <gl/glut.h>
#include <math.h>
#include <stdio.h>

void drawpixel(GLint cx,GLint cy)
{
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}
void plotpixel(GLint h,GLint k,GLint x,GLint y)
{
	drawpixel(x+h,y+k);
	drawpixel(-x+h,y+k);
	drawpixel(x+h,-y+k);
	drawpixel(-x+h,-y+k);
	drawpixel(y+h,x+k);
	drawpixel(-y+h,x+k);
	drawpixel(y+h,-x+k);
	drawpixel(-y+h,-x+k);
}
void circledraw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixel(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixel(h,k,x,y);
}
void cylinderdraw()
{
	GLint xc=100,yc=100,r=50,i,n=50;
	for(i=0;i<n;i+=3)
		circledraw(xc,yc+i,r);
}
void pp(int x1,int x2,int y1,int y2,int y3,int y4)
{
	glColor3f(0,0,1);
	glPointSize(2);
	glBegin(GL_LINE_LOOP);
		glVertex2i(x1,y1);
		glVertex2i(x2,y3);
		glVertex2i(x2,y4);
		glVertex2i(x1,y2);
	glEnd();
}
void ppdraw()
{
	int x1=200,x2=300,y1=100,y2=175,y3=100,y4=175;
	GLint i,n=40;
	for(i=0;i<n;i+=2)
		pp(x1+i,x2+i,y1+i,y2+i,y3+i,y4+i);
}
void init(void)
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,400,0,300);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glPointSize(2);
	cylinderdraw();
	ppdraw();
	glFlush();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(400,300);
	glutCreateWindow("cylinder &parallelopiped");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}
	
