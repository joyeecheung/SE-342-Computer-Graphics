#include "Shape.h"

const GLenum doubleBuffer = GL_TRUE;
const int numTriangles = 2;

GLfloat backgroundColor[4] = {
  1.0f, 1.0f, 1.0f, 1.0f  // White
};

GLfloat triangles[][3][3] = {
  {
    { -0.90f, -0.90f, 0.0f}, // Triangle 1
    {  0.85f, -0.90f, 0.0f},
    { -0.90f,  0.85f, 0.0f},
  }, {
    {  0.90f, -0.85f, 0.0f}, // Triangle 2
    {  0.90f,  0.90f, 0.0f},
    { -0.85f,  0.90f, 0.0f}
  }
};

GLfloat triangleColors[][4] = {
  { 0.0f, 0.0f, 1.0f, 0.2f }, // Blue
  { 0.0f, 1.0f, 0.0f, 0.3f }  // Green
};

void drawPoints(int x0, int y0, int x, int y) {
    glVertex2i( x + x0,  y + y0);
    glVertex2i( y + x0,  x + y0);
    glVertex2i(-x + x0,  y + y0);
    glVertex2i(-y + x0,  x + y0);
    glVertex2i(-x + x0, -y + y0);
    glVertex2i(-y + x0, -x + y0);
    glVertex2i( x + x0, -y + y0);
    glVertex2i( y + x0, -x + y0);
}

void drawTriangles(GLfloat triangles[][3][3],
                   int numTriangles,
                   GLfloat triangleColors[][4]) {
    // start specifying triangles
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numTriangles; ++i) {
        // specify vertex
        for (int v = 0; v < 3; ++v) {
            glVertex3f(triangles[i][v][X],
                       triangles[i][v][Y],
                       triangles[i][v][Z]);
        }
        // specify color
        glColor4f(triangleColors[i][R], triangleColors[i][G],
                  triangleColors[i][B], triangleColors[i][A]);
    }
    glEnd();
}
