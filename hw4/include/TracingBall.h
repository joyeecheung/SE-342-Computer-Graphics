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
#include "Polyhedron.h"

// callbacks and functions
void init(int argc, char **argv);

void onDisplay(void);
void onReshape(int width, int height);
void onMouse(int button, int state, int x, int y);
void onMotion(int x, int y);
void onKeyboard(unsigned char key, int x, int y);
void onIdle(void);

void createMenu(int button, std::map<std::string, int> entries,
            int defaultEntry);
void onMenu(int num);
void onMenuState(int status);
#endif
