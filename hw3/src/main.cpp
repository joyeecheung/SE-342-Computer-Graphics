#include "Shape.h"

int width = 480, height = 480;

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLfloat)w, 0, (GLfloat)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // White Background
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load an identity matrix
    glLoadIdentity();

    int count = drawCircle(240, 240, 100);
    printf("Number of points: %d\n", count);

    // to make the transperancy take effect,
    // this is necessary
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    // display it
    if (doubleBuffer) {
        glutSwapBuffers();
    } else {
        glFlush();
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    // display mode
    GLenum type = GLUT_RGBA | GLUT_DEPTH;
    type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
    glutInitDisplayMode(type);

    // size of window
    glutInitWindowSize(width, height);

    // create the window
    glutCreateWindow("hw3");

    // notice that this function should be placed
    // after createWindow()
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}