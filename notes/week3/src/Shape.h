#ifndef SHAPE_H
#define SHAPE_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

enum Shape { TRIANGLES, CIRCLE };
enum Coordinate { X = 0, Y, Z };
enum RGB { R = 0, G, B, A};

extern Shape toDraw;
extern const GLenum doubleBuffer;
extern const int numTriangles;
extern GLfloat backgroundColor[4];
// vertices of triangles
extern GLfloat triangles[][3][3];
// color of triangles
extern GLfloat triangleColors[][4];
extern GLfloat circleColor[4];

void drawPoints(int x0, int y0, int x, int y);
void drawCircle(int x0, int y0, int r);
void drawTriangles(GLfloat triangles[][3][3], int numTriangles);
void draw(Shape shape);

#endif
