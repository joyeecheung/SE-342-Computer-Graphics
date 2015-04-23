#ifndef TRACING_BALL_H
#define TRACING_BALL_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

#include <map>
#include <string>

#include "GLUTWindow.h"
#include "Tracer.h"
#include "Dodecahedron.h"

// callbacks and functions
void init(int argc, char **argv);

// ------- Menu -------
struct Menu {
    int id;
    int entry;
    bool visible;
};
extern Menu menu;
void createMenu(int button, std::map<std::string, int> entries,
            int defaultEntry);
void onMenu(int num);
void menuState(int status);
// --------------------

void display(void);
void reshape(int width, int height);
void idle(void);

void mouseFunc(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char key, int x, int y);

float randomIntensity(void);
void generateColors(GLfloat colors[][3], int surfaceCount);
void draw(GLenum type);
#endif
