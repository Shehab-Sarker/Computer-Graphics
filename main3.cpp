#include <GL/freeglut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 0.7f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.7f, -0.7f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.7f, -0.7f);
	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int, int)
{
	if (key == 27 || key == 'q')
	{
		glutLeaveMainLoop();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Simple GLUT Triangle");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
