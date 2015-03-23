#ifndef MAIN_H
#define MAIN_H

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

void display(void);
GLfloat Triangle[3][3] = {
  {-0.5, -0.5, 0.0},
  { 0.5, -0.0, 0.0},
  { 0.0,  0.5, 0.0}
};

#endif
