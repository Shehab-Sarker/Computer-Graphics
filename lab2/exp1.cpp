#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Increase point size
    glPointSize(8.0f);

    glBegin(GL_POINTS);

    // First color: blue
    glColor3f(0.10f, 0.45f, 0.75f);
    glVertex2f(-0.60f,  0.40f);
    glVertex2f(-0.20f,  0.10f);
    glVertex2f( 0.20f,  0.50f);

    // Second color: orange
    glColor3f(0.85f, 0.45f, 0.10f);
    glVertex2f( 0.45f, -0.10f);
    glVertex2f( 0.70f, -0.45f);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Set coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Experiment 1 - Points and Point Size");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}