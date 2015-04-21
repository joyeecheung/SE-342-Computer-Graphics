#include "TracingBall.h"

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

const int VertexCount = 20, SurfaceCount = 12, EdgeCount = 30;

GLfloat colors[VertexCount * 3];

GLfloat vertices[] = {
    1.214124, 0.000000, 1.589309,
    0.375185, 1.154701, 1.589309,
    -0.982247, 0.713644, 1.589309,
    -0.982247, -0.713644, 1.589309,
    0.375185, -1.154701, 1.589309,
    1.964494, 0.000000, 0.375185,
    0.607062, 1.868345, 0.375185,
    -1.589309, 1.154701, 0.375185,
    -1.589309, -1.154701, 0.375185,
    0.607062, -1.868345, 0.375185,
    1.589309, 1.154701, -0.375185,
    -0.607062, 1.868345, -0.375185,
    -1.964494, 0.000000, -0.375185,
    -0.607062, -1.868345, -0.375185,
    1.589309, -1.154701, -0.375185,
    0.982247, 0.713644, -1.589309,
    -0.375185, 1.154701, -1.589309,
    -1.214124, 0.000000, -1.589309,
    -0.375185, -1.154701, -1.589309,
    0.982247, -0.713644, -1.589309
};

GLushort indices[] = {
    0,  1,  2,  3,  4,
    0,  5,  10, 6,  1,
    1,  6,  11, 7,  2,
    2,  7,  12, 8,  3,
    3,  8,  13, 9,  4,
    4,  9,  14, 5,  0,
    15, 10, 5,  14, 19,
    16, 11, 6,  10, 15,
    17, 12, 7,  11, 16,
    18, 13, 8,  12, 17,
    19, 14, 9,  13, 18,
    19, 18, 17, 16, 15
};

float randomIntensity() {
    int r = rand() % 256;
    float res = r / 256.0;
    return r / 256.0;
}

void generateColors() {
    for (int i = 0; i < SurfaceCount; ++i) {
        GLfloat color[3];
        color[0] = randomIntensity();
        color[1] = randomIntensity();
        color[2] = randomIntensity();
        
        for (int j = 0; j < 5; ++j) {
            int vertex = indices[i * 5 + j];

            for (int k = 0; k < 3; ++k)
                colors[vertex * 3 + k] = color[k];
        }
    }
}

void draw(void) {
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glPushMatrix();
    glColor4f(1, 1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_POLYGON, 0, VertexCount);
    // glDrawElements(GL_TRIANGLE_FAN, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_SHORT, indices);
    glPopMatrix();

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}


void display(void) {
    // clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.33, 1.0, 100000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(cameraPosition[0], cameraPosition[1], cameraPosition[2]);

    glRotatef(cameraRotation[0], 1.0f, 0.0f, 0.0f);
    glRotatef(cameraRotation[1], 0.0f, 1.0f, 0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;

    // ------------- Drawings --------------
    if (menuEntry == 1) {
		// glutSolidDodecahedron();
        draw();
    } else if(menuEntry == 2) {
		// glutWireDodecahedron();
        draw();
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

    glClearColor(0, 0, 0, 0);
    generateColors();

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
