#include "TracingBall.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

const int SOLID = 1, WIREFRAME = 2;

// window attribute
bool isFullScreen = false;
int windowID;
int width = 640, height = 480;
GLfloat aspect = (GLfloat) width / (GLfloat) height;

// lighting
GLfloat lightpos[4] = { 5.0, 15.0, 10.0, 1.0 };

// camera attributes
Camera camera;
GLfloat translateFactor = 30.0;

// mouse button states
bool leftActive = false;
bool middleActive = false;
bool rightActive = false;

// position of the mouse when pressed
Vector3 mouse;
Vector3 lastOffset;

// menu attributes
int menuID;
int menuEntry = SOLID;
bool menuMode = false;

// data
const int vertexCount = 20, surfaceCount = 12, edgeCount = 30;
GLfloat colors[surfaceCount][3];

GLfloat vertices[vertexCount][3] = {
    {1.214124, 0.000000, 1.589309},
    {0.375185, 1.154701, 1.589309},
    { -0.982247, 0.713644, 1.589309},
    { -0.982247, -0.713644, 1.589309},
    {0.375185, -1.154701, 1.589309},
    {1.964494, 0.000000, 0.375185},
    {0.607062, 1.868345, 0.375185},
    { -1.589309, 1.154701, 0.375185},
    { -1.589309, -1.154701, 0.375185},
    {0.607062, -1.868345, 0.375185},
    {1.589309, 1.154701, -0.375185},
    { -0.607062, 1.868345, -0.375185},
    { -1.964494, 0.000000, -0.375185},
    { -0.607062, -1.868345, -0.375185},
    {1.589309, -1.154701, -0.375185},
    {0.982247, 0.713644, -1.589309},
    { -0.375185, 1.154701, -1.589309},
    { -1.214124, 0.000000, -1.589309},
    { -0.375185, -1.154701, -1.589309},
    {0.982247, -0.713644, -1.58930}
};

GLushort indices[surfaceCount][5] = {
    {0,  1,  2,  3,  4},
    {0,  5,  10, 6,  1},
    {1,  6,  11, 7,  2},
    {2,  7,  12, 8,  3},
    {3,  8,  13, 9,  4},
    {4,  9,  14, 5,  0},
    {15, 10, 5,  14, 19},
    {16, 11, 6,  10, 15},
    {17, 12, 7,  11, 16},
    {18, 13, 8,  12, 17},
    {19, 14, 9,  13, 18},
    {19, 18, 17, 16, 15}
};

void init(int argc, char **argv) {
    // create window and menu
    glutInit (&argc, argv);
    glutInitWindowSize (width, height);
    glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    windowID = glutCreateWindow ("Virtual Tracing Ball");
    menuID = createMenu();

    glClearColor(0, 0, 0, 0);
    generateColors(colors, surfaceCount);
    initCamera(camera);

    float zeros[3] = {0.0, 0.0, 0.0};
    mouse.set(zeros);
    lastOffset.set(zeros);

    // Register callbacks
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc   (mouseFunc);
    glutMotionFunc  (mouseMotion);
    glutIdleFunc    (idle);
}

void initCamera(Camera &camera) {
    float position[3]  = { 0.0, 0.0, -10.0 };
    float direction[3] = { 0.0, 0.0, 0.0 };
    float rotation[3] = { 0.0, 0.0, 0.0 };

    camera.set(position, direction, rotation);
}

// aspect, camera.position, camera.rotation, menuEntry
// lightpos
void display(void) {
    // Clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 3D
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);

    // Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, aspect, 1.0, 1000.0);

    // Model view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(camera.position.x, camera.position.y, camera.position.z);
    glRotatef(camera.rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(camera.rotation.y, 0.0f, 1.0f, 0.0f);

    // Lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;

    // ------------- Drawings --------------
    draw(menuEntry == SOLID ? GL_POLYGON : GL_LINE_LOOP);
    // ------------- Drawing ends -----------

    glutSwapBuffers();
}

// aspect
void reshape(int w, int h) {
    // resize viewport
    glViewport(0, 0, w, h);

    // resize perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();    
    aspect = (GLfloat)w / (GLfloat)h;
    gluPerspective(50.0, aspect, 1.0, 1000.0);

    // reload
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void idle(void) {
    glutPostRedisplay();
}

int createMenu(void) {
    int menuID = glutCreateMenu(menu);
    menuEntry = SOLID;
    glutAddMenuEntry("Solid", SOLID);
    glutAddMenuEntry("WireFrame", WIREFRAME);
    glutMenuStateFunc(menuState);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    return menuID;
}

void menuState(int status) {
    if (status == GLUT_MENU_IN_USE)
        menuMode = true;
}

void menu(int num) {
    menuEntry = num;
}

// menuMode
void mouseFunc(int button, int state, int x, int y) {
    // get the mouse buttons and initialize offsets
    if (button == GLUT_LEFT_BUTTON && !menuMode) {
        if (state == GLUT_DOWN) {
            leftActive = true;
        } else {
            leftActive = false;
        }
        mouse.x = x;
        mouse.y = y;
    } else if (button == GLUT_RIGHT_BUTTON && !menuMode) {
        if (state == GLUT_DOWN) {
            rightActive = true;
            lastOffset.x = 0.0;
            lastOffset.y = 0.0;
        } else {
            rightActive = false;
        }
        mouse.x = x;
        mouse.y = y;
    } else if (menuMode) {
        menuMode = false;
    }
}

void mouseMotion(int x, int y) {
    float xOffset = 0.0, yOffset = 0.0, zOffset = 0.0;
    if (leftActive) { // rotating
        camera.rotation.x += (mouse.y - y);
        camera.rotation.y += (mouse.x - x);

        mouse.y = y;
        mouse.x = x;
    } else if (rightActive) { // translating
        xOffset = (mouse.x + x);
        if (!fabs(lastOffset.x - 0.0) < 1e-6) {
            camera.position.x  -= (xOffset - lastOffset.x) / translateFactor;
            camera.direction.x -= (xOffset - lastOffset.x) / translateFactor;
        }
        lastOffset.x = xOffset;
        yOffset = (mouse.y + y);
        if (!fabs(lastOffset.y - 0.0) < 1e-6) {
            camera.position.y  += (yOffset - lastOffset.y) / translateFactor;
            camera.direction.y += (yOffset - lastOffset.y) / translateFactor;
        }
        lastOffset.y = yOffset;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
#if defined(_WIN32) || defined(WIN32)
    // exit on esc
    case '\033':
        exit(0);
        break;
#endif
    // full screen
    case 'f':
        isFullScreen = !isFullScreen;
        if (isFullScreen)
            glutFullScreen();
        else {
            glutSetWindow(windowID);
            glutReshapeWindow(width, height);
        }
        break;
    }
}

float randomIntensity(void) {
    return (rand() % 256) / 256.0;
}

void generateColors(GLfloat colors[][3], int number) {
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < 3; ++j) {
            colors[i][j] = randomIntensity();
        }
    }
}

void draw(GLenum type) {
    for (int i = 0; i < surfaceCount; ++i) {
        glBegin(type);
        glColor3fv(colors[i]);

        for (int j = 0; j < 5; ++j) {
            int v = indices[i][j];
            glVertex3fv(vertices[v]);
        }
        glEnd();
    }
}