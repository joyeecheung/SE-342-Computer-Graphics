#include "GLUTWindow.h"

GLUTWindow::GLUTWindow(int w, int h)
  : width(w), height(h), isFullScreen(false) {
    aspect = (GLfloat) width / (GLfloat) height;
    oldWidth = width;
    oldHeight = height;
}

void GLUTWindow::create(const char* title) {
    glutInitWindowSize (width, height);
    id = glutCreateWindow(title);
}

void GLUTWindow::toggleFullScreen() {
    isFullScreen = !isFullScreen;
    if (isFullScreen) {
        glutFullScreen();
        oldWidth = width;
        oldHeight = height;
    } else {
        glutSetWindow(id);
        glutReshapeWindow(oldWidth, oldHeight);
    }
}

void GLUTWindow::update(int w, int h) {
    width = w;
    height = h;
    aspect = (GLfloat)w / (GLfloat)h;
}

