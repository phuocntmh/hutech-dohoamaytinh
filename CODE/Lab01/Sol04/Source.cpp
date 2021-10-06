#include <windows.h>
#include <GL/glut.h>

const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glShadeModel(GL_FLAT);
}

void triangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(160, 80);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(480, 80);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(320, 400);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0, 1.0, 1.0);
	triangle();
	glFlush();
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
	glutInitWindowSize(screenWidth, screenHeight); //optional
	glutInitWindowPosition(100, 100);//optional
	glutCreateWindow("Points");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
