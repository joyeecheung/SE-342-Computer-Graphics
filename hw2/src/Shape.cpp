#include "Shape.h"

const GLenum doubleBuffer = GL_TRUE;
const int numTriangles = 12;

GLfloat backgroundColor[4] = {
  1.0f, 1.0f, 1.0f, 1.0f  // White
};

GLfloat triangles[][3][3] = {
  {
    {  0.00f,   0.0f, 0.0f}, // Triangle 1
    {  0.00f,  0.25f, 0.0f},
    {  0.25f,  0.25f, 0.0f}
  }, {
    {  0.25f,  0.25f, 0.0f}, // Triangle 2
    {  0.25f,   0.0f, 0.0f},
    {  0.00f,   0.0f, 0.0f}
  }, {
    {  0.25f,  0.25f, 0.0f}, // Triangle 3
    {  0.25f,   0.0f, 0.0f},
    {  0.50f,   0.0f, 0.0f}
  }, {
    {   0.0f,   0.0f, 0.0f}, // Triangle 4
    {  0.25f,   0.0f, 0.0f},
    {  0.25f, -0.25f, 0.0f}
  }, {
    {   0.0f,   0.0f, 0.0f}, // Triangle 5
    {   0.0f, -0.25f, 0.0f},
    {  0.25f, -0.25f, 0.0f}
  }, {
    {   0.0f, -0.50f, 0.0f}, // Triangle 6
    {   0.0f, -0.25f, 0.0f},
    {  0.25f, -0.25f, 0.0f}
  }, {
    {   0.0f,   0.0f, 0.0f}, // Triangle 7
    {   0.0f, -0.25f, 0.0f},
    { -0.25f, -0.25f, 0.0f}
  }, {
    {   0.0f,   0.0f, 0.0f}, // Triangle 8
    { -0.25f,   0.0f, 0.0f},
    { -0.25f, -0.25f, 0.0f}
  }, {
    { -0.25f,   0.0f, 0.0f}, // Triangle 9
    { -0.50f,   0.0f, 0.0f},
    { -0.25f, -0.25f, 0.0f}
  }, {
    {   0.0f,   0.0f, 0.0f}, // Triangle 10
    { -0.25,    0.0f, 0.0f},
    { -0.25f,  0.25f, 0.0f}
  }, {
    {   0.0f,   0.0f, 0.0f}, // Triangle 11
    {   0.0f,  0.25f, 0.0f},
    { -0.25f,  0.25f, 0.0f}
  }, {
    { -0.25f,  0.25f, 0.0f}, // Triangle 12
    {   0.0f,  0.25f, 0.0f},
    {   0.0f,  0.50f, 0.0f}
  }
};

GLfloat triangleColors[][4] = {
  { 0.83f, 0.94f, 0.65f, 1.0f },
  { 0.48f, 0.82f, 0.71f, 1.0f },
  { 0.59f, 0.85f, 0.62f, 1.0f },
  { 0.65f, 0.92f, 0.93f, 1.0f },
  { 0.62f, 0.81f, 0.97f, 1.0f },
  { 0.52f, 0.69f, 0.95f, 1.0f },
  { 0.78f, 0.64f, 0.92f, 1.0f },
  { 0.95f, 0.77f, 0.92f, 1.0f },
  { 0.93f, 0.55f, 0.71f, 1.0f },
  { 0.98f, 0.60f, 0.60f, 1.0f },
  { 0.98f, 0.84f, 0.61f, 1.0f },
  { 0.98f, 0.72f, 0.60f, 1.0f } 
};

void drawTriangles(GLfloat triangles[][3][3],
                   int numTriangles,
                   GLfloat triangleColors[][4]) {

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numTriangles; ++i) {
      // start specifying triangles
      
        // specify color
        glColor4f(triangleColors[i][R], triangleColors[i][G],
                  triangleColors[i][B], triangleColors[i][A]);
        // specify vertex
        for (int v = 0; v < 3; ++v) {
            glVertex3f(triangles[i][v][X],
                       triangles[i][v][Y],
                       triangles[i][v][Z]);
        }
    }
    glEnd();
}
