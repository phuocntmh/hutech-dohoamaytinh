#include <math.h>
#include "GL\glew.h"
#include "GL\freeglut.h"

const int screenWidth = 640;
const int screenHeight = 480;
const double R = 150;
const double R2 = 60;
const double pi = 3.141592654;

struct GLdoublePoint
{
	GLdouble x;
	GLdouble y;
};

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//clear white
	glShadeModel(GL_FLAT);
}


void drawRectangle(GLint x, GLint y, GLint width, GLint height)
{

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f);//dinh co mau hong
	glVertex2i(x, y); //tren trai
	glColor3f(0.0f, 1.0f, 1.0f);//dinh co mau xanh da troi
	glVertex2i(x + width, y); //tren phai
	glColor3f(1.0f, 1.0f, 0.0f);//dinh co mau xanh vang
	glVertex2i(x + width, y + height); //duoi phai
	glColor3f(1.0f, 1.0f, 1.0f);//dinh co mau trang
	glVertex2i(x, y + height); //duoi trai
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	glColor3f(0.0f, 0.0f, 0.0f);//mau trang
	glBegin(GL_POINTS);
	double RR = R / 4;
	GLdoublePoint v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v0, v00;
		v0.x = screenWidth / 2;
		v0.y = screenHeight / 2;
		v1.x = v0.x;
		v1.y = v0.y + R;
		v2.x = v0.x + R * sin(2 * pi / 5);
		v2.y = v0.y + R * cos(2 * pi / 5);
		v3.x = v0.x + R * sin(pi / 5);
		v3.y = v0.y - R * cos(pi / 5);
		v4.x = v0.x - R * sin(pi / 5);
		v4.y = v0.y - R * cos(pi / 5);
		v5.x = v0.x - R * sin(2 * pi / 5);
		v5.y = v0.y + R * cos(2 * pi / 5);
		
		v9.x = v0.x;
		v9.y = v0.y - R2;
		v8.x = v0.x + R2 * sin(2 * pi / 5);
		v8.y = v0.y - R2 * cos(2 * pi / 5);
		v7.x = v0.x + R2 * sin(pi / 5);
		v7.y = v0.y + R2 * cos(pi / 5);
		v6.x = v0.x - R2 * sin(pi / 5);
		v6.y = v0.y + R2 * cos(pi / 5);
		v10.x = v0.x - R2 * sin(2 * pi / 5);
		v10.y = v0.y - R2 * cos(2 * pi / 5);

		glVertex2d(v1.x, v1.y);
		glVertex2d(v2.x, v2.y);
		glVertex2d(v3.x, v3.y);
		glVertex2d(v4.x, v4.y);
		glVertex2d(v5.x, v5.y);
		glVertex2d(v6.x, v6.y);
		glVertex2d(v7.x, v7.y);
		glVertex2d(v8.x, v8.y);
		glVertex2d(v9.x, v9.y);
		glVertex2d(v10.x, v10.y);
	glEnd();
	glFlush();//day buffer ra
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);//optional
	glutInitWindowPosition(100, 100); //optional
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}