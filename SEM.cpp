#include <GL/glut.h>
#include <stdlib.h>

float earthAngle = 0.0f;
float moonAngle = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -8.0f);

    // Sun
    glColor3f(1.0f, 0.5f, 0.0f);
    glutSolidSphere(1.0, 30, 30);

    // Earth orbit
    glPushMatrix();

        glRotatef(earthAngle, 0.0f, 1.0f, 0.0f);
        glTranslatef(3.0f, 0.0f, 0.0f);

        // Earth
        glColor3f(0.0f, 0.3f, 1.0f);
        glutSolidSphere(0.5, 20, 20);

        // Moon orbit
        glPushMatrix();

            glRotatef(moonAngle, 0.0f, 1.0f, 0.0f);
            glTranslatef(1.0f, 0.0f, 0.0f);

            // Moon
            glColor3f(0.7f, 0.7f, 0.7f);
            glutSolidSphere(0.2, 15, 15);

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    float ratio = (float)width / height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, ratio, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int , int )
{
    if (key == 'q' || key == 27)
        exit(0);
}

void idle()
{
    earthAngle += 0.05f;
    moonAngle += 0.2f;

    if (earthAngle >= 360)
        earthAngle = 0;

    if (moonAngle >= 360)
        moonAngle = 0;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 500);

    glutCreateWindow("Simple Solar System");

    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}