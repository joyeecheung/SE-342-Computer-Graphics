#include "Shape.h"

const GLenum doubleBuffer = GL_TRUE;
GLfloat circleColor[4] = {
    0.0, 0.0, 0.0, 1.0  // black
};

int drawCircle(int x0, int y0, int r) {
    int x = -r, y = 0, err = 2 - 2 * r; /* 2nd quadrant */
    int pointCount = 0;

    glColor4f(circleColor[R], circleColor[G],
              circleColor[B], circleColor[A]);

    glBegin(GL_POINTS);

    // center
    glVertex2i(x0, y0);

    do {
        glVertex2i(x0 - x, y0 + y); /* 1st quadrant */
        glVertex2i(x0 - y, y0 - x); /* 2nd quadrant */
        glVertex2i(x0 + x, y0 - y); /* 3rd quadrant */
        glVertex2i(x0 + y, y0 + x); /* 4th quadrant */
        pointCount += 4;

        int olderr = err;
        if (olderr <= y) {  /* e_xy + e_y < 0 */
            ++y;  /* y-step */
            err += y * 2 + 1;
        }

        /* e_xy + e_x > 0 or no 2nd y-step */
        if (olderr > x || err > y) {
            ++x;  /* x-step */
            err += x * 2 + 1;
        }
    } while (x < 0);

    glEnd();

    return pointCount;
}