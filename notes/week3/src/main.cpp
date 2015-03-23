#include "main.h"

void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // White Background
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load an identity matrix
    glLoadIdentity();

    // start specifying a triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numTriangles; ++i) {
        // specify vertex
        for (int v = 0; v < 3; ++v) {
            glVertex3f(triangles[i][v][X],
                       triangles[i][v][Y],
                       triangles[i][v][Z]);
        }
        // specify color
        glColor4f(colors[i][R], colors[i][G],
                  colors[i][B], colors[i][A]);
    }
    glEnd();

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
    glutInitWindowSize(640, 480);

    // create the window
    glutCreateWindow("week3");

    // notice that this function should be placed
    // after createWindow()
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}