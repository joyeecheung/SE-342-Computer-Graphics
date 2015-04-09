#ifndef SHAPE_H
#define SHAPE_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>
#include <cmath>
#include <cstdio>

enum Coordinate { X = 0, Y, Z };
enum RGB { R = 0, G, B, A};

extern const GLenum doubleBuffer;

extern GLfloat circleColor[4];

int drawCircle(int x0, int y0, int r);

#endif
