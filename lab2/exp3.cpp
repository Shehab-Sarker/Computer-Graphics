#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    // Vertex 1: Red
    glColor3f(1.0f, 0.2f, 0.2f);
    glVertex2f(-0.65f, -0.45f);

    // Vertex 2: Green
    glColor3f(0.2f, 0.8f, 0.3f);
    glVertex2f(0.00f, 0.65f);

    // Vertex 3: Blue
    glColor3f(0.2f, 0.4f, 1.0f);
    glVertex2f(0.65f, -0.45f);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

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

    glutCreateWindow("Experiment 3 - Colored Triangle");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}