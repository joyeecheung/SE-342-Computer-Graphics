#include "TracingBall.h"

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

int main(int argc, char **argv) {
    printf("Virtual Tracing Ball\n\n");
    printf("keys:\n");
    printf("\tf - toggle fullscreen\n");
    printf("\tesc\t- exit\n\n");

    printf("mouse:\n");
    printf("\tleft button\t- rotation\n");
    printf("\tmiddle button\t- menu\n");
    printf("\tright button\t- translation\n");

    init(argc, argv);
    glutMainLoop();

    return 0;
}
