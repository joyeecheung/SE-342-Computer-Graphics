#include "main.h"

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

int main(int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow ("week3");

    glutMainLoop();

    return 0;
}
