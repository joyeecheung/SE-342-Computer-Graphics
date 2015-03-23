#ifndef MAIN_H
#define MAIN_H

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

void display(void);

const GLenum doubleBuffer = GL_TRUE;

const int numTriangles = 2;

GLfloat backgroundColor[4] = {
  1.0, 1.0, 1.0, 1.0
};

// vertices of triangles
GLfloat triangles[numTriangles][3][3] = {
  {
    { -0.90, -0.90, 0.0}, // Triangle 1
    {  0.85, -0.90, 0.0},
    { -0.90,  0.85, 0.0},
  }, {
    {  0.90, -0.85, 0.0}, // Triangle 2
    {  0.90,  0.90, 0.0},
    { -0.85,  0.90, 0.0}
  }
};

// color of triangles
GLfloat colors[numTriangles][4] = {
  { 0.0, 0.0, 1.0, 0.2 }, // BLUE
  { 0.0, 1.0, 0.0, 0.3 }  // GREEN
};

enum Coordinate { X = 0, Y, Z };
enum RGB { R = 0, G, B, A};

#endif
