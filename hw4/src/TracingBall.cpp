#include "TracingBall.h"

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

void display(void) {
    // clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.33, 1.0, 100000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glTranslatef(cameraPosition[0], cameraPosition[1], cameraPosition[2]);

    glRotatef(cameraRotation[0], 1.0f, 0.0f, 0.0f);
    glRotatef(cameraRotation[1], 0.0f, 1.0f, 0.0f);

    // ------------- Drawings --------------
    if (menuEntry == 1) {
        glutSolidTeapot(10.0);
    } else if(menuEntry == 2) {
        glutWireTeapot(10.0);
    }

    // ------------- Drawing ends -----------
    glutSwapBuffers();
}

void menuState(int status) {
    if (status == GLUT_MENU_IN_USE)
        menuMode = true;
}

void menu(int num) {
    menuEntry = num;
}

void createMenu(void) {
    menuId = glutCreateMenu(menu);
    menuEntry = 1;
    glutAddMenuEntry("Solid", 1);
    glutAddMenuEntry("WireFrame", 2);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

void init(int argc, char **argv) {

    // GLUT Window Initialization:
    glutInit (&argc, argv);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    windowID = glutCreateWindow ("Virtual Tracing Ball");
    createMenu();

    // Register callbacks
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc   (mouse);
    glutMenuStateFunc(menuState);
    glutMotionFunc  (mouseMotion);
    glutIdleFunc    (idle);
}


void idle(void) {
    glutPostRedisplay();
}

void reshape(int width, int height) {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, 1.33, 1.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
}

// mouse callback
void mouse(int button, int state, int x, int y) {

    // get the modifiers
    switch (glutGetModifiers()) {

    case GLUT_ACTIVE_SHIFT:
        shiftActive = 1;
        break;
    case GLUT_ACTIVE_ALT:
        altActive   = 1;
        break;
    case GLUT_ACTIVE_CTRL:
        ctrlActive  = 1;
        break;
    default:
        shiftActive = 0;
        altActive   = 0;
        ctrlActive  = 0;
        break;
    }

    // get the mouse buttons and initialize offsets
    if (button == GLUT_LEFT_BUTTON && !menuMode) {
        if (state == GLUT_DOWN) {
            leftActive += 1;
        } else {
            leftActive -= 1;
        } 
        mouseX = x;
        mouseY = y;
    } else if (button == GLUT_RIGHT_BUTTON&& !menuMode) {
        if (state == GLUT_DOWN) {
            rightActive += 1;
            lastXOffset = 0.0;
            lastYOffset = 0.0;
        } else {
            rightActive -= 1;
        }
        mouseX = x;
        mouseY = y;
    } else if (menuMode) {
        menuMode = false;
    }
}

void mouseMotion(int x, int y) {

    float xOffset = 0.0, yOffset = 0.0, zOffset = 0.0;

    if (leftActive) {
        cameraRotation[0] += ((mouseY - y) * 180.0f) / 200.0f;
        cameraRotation[1] += ((mouseX - x) * 180.0f) / 200.0f;

        mouseY = y;
        mouseX = x;
    } else if (rightActive) { // translating
        xOffset = (mouseX + x);
        if (!lastXOffset == 0.0) {
            cameraPosition[0]   -= (xOffset - lastXOffset) / 8.0;
            cameraDirection[0]  -= (xOffset - lastXOffset) / 8.0;
        }
        lastXOffset = xOffset;

        yOffset = (mouseY + y);
        if (!lastYOffset == 0.0) {
            cameraPosition[1]   += (yOffset - lastYOffset) / 8.0;
            cameraDirection[1]  += (yOffset - lastYOffset) / 8.0;
        }
        lastYOffset = yOffset;

    }
}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {

#if defined(_WIN32) || defined(WIN32)
    // exit on escape
    case '\033':
        exit(0);
        break;
#endif

    // switch to fullscreen
    case 'f':
        isFullScreen = !isFullScreen;
        if (isFullScreen)
            glutFullScreen();
        else {
            glutSetWindow(windowID);
            glutPositionWindow(100, 100);
            glutReshapeWindow(640, 480);
        }
        break;
    }
}


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
