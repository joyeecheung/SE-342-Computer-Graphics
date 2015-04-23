#ifndef DODECAHEDRON_H
#define DODECAHEDRON_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>
#include <cstdlib>

// enums
extern const int SOLID;
extern const int WIREFRAME;
// data
extern const int vertexCount;
extern const int surfaceCount;
extern const int edgeCount;
extern GLfloat colors[][3];
extern GLfloat vertices[][3];
extern GLushort indices[][5];

float randomIntensity(void);
void generateColors(GLfloat colors[][3], int surfaceCount);
void draw(GLenum type);
#endif