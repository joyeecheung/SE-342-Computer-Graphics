#ifndef GLUT_WINDOW_H
#define GLUT_WINDOW_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

class GLUTWindow {
public:
    GLUTWindow(int w = 640, int h = 480);
    void create(const char* title);
    void toggleFullScreen();
    void update(int w, int h);

    int width, height;
    GLfloat aspect;

private:
    bool isFullScreen;
    int id;
    int oldWidth, oldHeight;
};

#endif