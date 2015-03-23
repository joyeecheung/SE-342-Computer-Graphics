#include "Shape.h"

const GLenum doubleBuffer = GL_TRUE;
const int numTriangles = 2;

GLfloat backgroundColor[4] = {
  1.0, 1.0, 1.0, 1.0  // White
};

GLfloat triangles[][3][3] = {
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

GLfloat triangleColors[][4] = {
  { 0.0, 0.0, 1.0, 0.2 }, // Blue
  { 0.0, 1.0, 0.0, 0.3 }  // Green
};

GLfloat circleColor[4] = {
  0.5, 0.5, 1.0, 1.0  // Purple
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

void drawCircle(int x0, int y0, int r) {
    int x = r, y = 0;
    int err = 1 - x;

    glColor4f(circleColor[R], circleColor[G],
              circleColor[B], circleColor[A]);

    glBegin(GL_POINTS);

    // The cross
    glVertex2i(x0, y0 + r);
    glVertex2i(x0, y0 - r);
    glVertex2i(x0 + r, y0);
    glVertex2i(x0 - r, y0);

    while (x >= y) {
        drawPoints(x0, y0, x, y);
        y++;
        if (err < 0) {
            err += 2 * y + 1;
        } else {
            x--;
            err += 2 * (y - x) + 1;
        }
    }

    glEnd();
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

void draw(Shape shape) {
    if (shape == TRIANGLES) {
        drawTriangles(triangles, numTriangles, triangleColors);
    } else if (shape == CIRCLE) {
        drawCircle(240, 240, 100);
        
    }
}
