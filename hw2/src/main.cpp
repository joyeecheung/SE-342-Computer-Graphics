#include "Shape.h"

int width = 480, height = 480;


void reshape(int w, int h) {
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // use the projection matrix
    glMatrixMode(GL_PROJECTION);
    // reset
    glLoadIdentity();

    // Set the correct projection
    gluOrtho2D(0, (GLfloat)w, 0, (GLfloat)h);

    // use the modelview matrix
    glMatrixMode(GL_MODELVIEW);

    // reset
    glLoadIdentity();
}

void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // White Background
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load an identity matrix
    glLoadIdentity();

    drawTriangles(triangles, numTriangles, triangleColors);

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
    glutInitWindowSize(480, 480);

    // create the window
    glutCreateWindow("week3");

    // notice that this function should be placed
    // after createWindow()
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}