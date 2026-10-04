#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <cmath>

#define PI 3.14159265358979323846

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // -----------------------------
    // Green rectangular flag
    // -----------------------------
    glColor3f(0.0f, 0.42f, 0.20f);

    glBegin(GL_QUADS);
        glVertex2i(-100, 60);
        glVertex2i(100, 60);
        glVertex2i(100, -60);
        glVertex2i(-100, -60);
    glEnd();

    // -----------------------------
    // Red circular approximation
    // -----------------------------
    float centerX = -10.0f;
    float centerY = 0.0f;
    float radius = 35.0f;

    glColor3f(0.85f, 0.05f, 0.05f);

    glBegin(GL_POLYGON);

    // Center point
    glVertex2f(centerX, centerY);

    // Many vertices around the circle
    for (int i = 0; i <= 100; i++)
    {
        float angle = 2.0f * PI * i / 100.0f;

        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-100, 100, -100, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("National Flag Like Composition");

    // Background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}