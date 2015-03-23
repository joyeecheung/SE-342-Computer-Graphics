#include "main.h"

void display(void) {
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load an identity matrix
    glLoadIdentity();

    // start specifying an triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numTriangles; ++i) {
        for (int v = 0; v < 3; ++v) {
            glVertex3f(triangles[i][v][X],
                       triangles[i][v][Y],
                       triangles[i][v][Z]);
        }
    }

    glColor3f(BLUE_R, BLUE_G, BLUE_B);
    glEnd();

    // display it
    glutSwapBuffers();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);

    // Color mode
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    // size of window
    glutInitWindowSize(640, 480);

    // create the window
    glutCreateWindow("week3");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}