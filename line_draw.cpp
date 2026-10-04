#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // ------------------------------------------------
    // (a) Two independent line segments using GL_LINES
    // ------------------------------------------------
    glColor3f(0.10f, 0.45f, 0.75f);

    glBegin(GL_LINES);

        // First line
        glVertex2f(-0.80f, 0.70f);
        glVertex2f(-0.20f, 0.70f);

        // Second line
        glVertex2f(-0.80f, 0.50f);
        glVertex2f(-0.20f, 0.50f);

    glEnd();


    // ------------------------------------------------
    // (b) Open polyline using GL_LINE_STRIP
    // ------------------------------------------------
    glColor3f(0.85f, 0.20f, 0.10f);

    // Change line width before drawing the polyline
    glLineWidth(5.0f);

    glBegin(GL_LINE_STRIP);

        glVertex2f(-0.70f, 0.10f);
        glVertex2f(-0.45f, 0.40f);
        glVertex2f(-0.15f, 0.05f);
        glVertex2f(0.10f, 0.35f);
        glVertex2f(0.35f, 0.00f);

    glEnd();


    // ------------------------------------------------
    // (c) Rectangle outline using GL_LINE_LOOP
    // ------------------------------------------------
    glColor3f(0.10f, 0.65f, 0.25f);

    // Try a different line width
    glLineWidth(3.0f);

    glBegin(GL_LINE_LOOP);

        glVertex2f(0.35f, 0.60f);
        glVertex2f(0.80f, 0.60f);
        glVertex2f(0.80f, 0.25f);
        glVertex2f(0.35f, 0.25f);

    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700, 700);

    glutCreateWindow("Experiment 2 - Lines, Strip and Loop");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}