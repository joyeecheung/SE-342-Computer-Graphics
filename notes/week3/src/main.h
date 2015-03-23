#ifndef MAIN_H
#define MAIN_H

#include <cstdio>
#include <cstdlib>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

void display(void);

const int numTriangles = 2;

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

enum Coordinate { X = 0, Y, Z };
const GLfloat BLUE_R = 0.0, BLUE_G = 0.0, BLUE_B = 1.0;


#endif
