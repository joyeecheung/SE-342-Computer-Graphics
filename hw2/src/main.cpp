#include "Shape.h"

int width = 480, height = 480;
float angle = 0.0f;

void reshape(int w, int h) {
    h = h == 0 ? 1 : h;  // avoid division by zero
    float ratio =  w * 1.0f / h;

    // use the projection matrix
    glMatrixMode(GL_PROJECTION);

    // reset
    glLoadIdentity();

    // set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // set the correct perspective
    gluPerspective(/* field of view angle */ 45.0f,
                   /* aspect ratio */ ratio,
                   /* near clipping plane */ 0.0f,
                   /* far clipping plane */ 100.0f);

    // go back to the modelview matrix
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // White Background
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load an identity matrix
    glLoadIdentity();

    gluLookAt(0.0f, 0.0f, 3.0f,  // eye
              0.0f, 0.0f, 0.0f,  // center
              0.0f, 1.0f, 0.0f); // up

    // rotate in each frame
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    angle += 0.05f;

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
    glutInitWindowSize(width, height);

    // create the window
    glutCreateWindow("week3");

    // notice that this function should be placed
    // after createWindow()
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();

    return 0;
}