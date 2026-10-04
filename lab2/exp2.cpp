#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //Draw two independent line segments
    glLineWidth(5.0f);

    glBegin(GL_LINES);

    //First line: blue
    glColor3f(0.10f, 0.45f, 0.75f);
    glVertex2f(-0.80f, 0.50f);
    glVertex2f(-0.20f, 0.10f);

    // Second line: orange
    glColor3f(0.85f, 0.45f, 0.10f);
    
    glVertex2f(0.20f, -0.20f);
    glVertex2f(0.75f, 0.50f);

    glEnd();

    glFlush();
}

void init(){
    glClearColor(1.0f, 1.0f, 1.0f,1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);

    glutCreateWindow("Experiment 2 - GL_LINES");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}