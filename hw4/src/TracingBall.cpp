#include "TracingBall.h"

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

GLUTWindow window;
struct Menu {
    int id;
    int entry;
    bool visible;
} menu;
Tracer tracer;
GLfloat lightpos[4] = { 5.0, 15.0, 10.0, 1.0 };



void init(int argc, char **argv) {
    // create window and menu
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    window.create("Virtual Tracing Ball");

    std::map<std::string, int> entries;
    entries["Solid"] = SOLID;
    entries["Wire Frame"] = WIREFRAME;

    createMenu(GLUT_MIDDLE_BUTTON, entries, SOLID);

    glClearColor(0, 0, 0, 0);
    generateColors(colors, surfaceCount);
    tracer.init();

    // Register callbacks
    glutDisplayFunc (onDisplay);
    glutReshapeFunc (onReshape);
    glutKeyboardFunc(onKeyboard);
    glutMouseFunc   (onMouse);
    glutMotionFunc  (onMotion);
    glutIdleFunc    (onIdle);
}

// aspect, camera.position, camera.rotation, menuEntry
// lightpos
void onDisplay(void) {
    // Clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 3D
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);

    // Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, window.aspect, 1.0, 1000.0);

    // Model view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    tracer.transform();

    // Lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;

    // ------------- Drawings --------------
    draw(menu.entry == SOLID ? GL_POLYGON : GL_LINE_LOOP);
    // ------------- Drawing ends -----------

    glutSwapBuffers();
}

// aspect
void onReshape(int w, int h) {
    // resize viewport
    window.update(w, h);
    glViewport(0, 0, w, h);

    // resize perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, window.aspect, 1.0, 1000.0);

    // reload
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void onIdle(void) {
    glutPostRedisplay();
}

// menuMode
void onMouse(int button, int state, int x, int y) {
    if (!menu.visible) {
        tracer.onMouse(button, state, x, y);
    } else {
        menu.visible = false;
    }
}

void onMotion(int x, int y) {
    tracer.onMouseMotion(x, y);
}

void onKeyboard(unsigned char key, int x, int y) {
    switch (key) {
#if defined(_WIN32) || defined(WIN32)
    // exit on esc
    case '\033':
        exit(0);
        break;
#endif
    // full screen
    case 'f':
        window.toggleFullScreen();
        break;
    }
}

void createMenu(int button, std::map<std::string, int> entries, int defaultEntry) {
    menu.visible = false;
    menu.id = glutCreateMenu(onMenu);
    menu.entry = defaultEntry;
    for (std::map<std::string, int>::iterator it = entries.begin();
        it != entries.end(); ++it) {
        glutAddMenuEntry(it->first.c_str(), it->second);
    }
    glutMenuStateFunc(onMenuState);
    glutAttachMenu(button);
}

void onMenu(int num) {
    menu.entry = num;
}

void onMenuState(int status) {
    if (status == GLUT_MENU_IN_USE)
        menu.visible = true;
}