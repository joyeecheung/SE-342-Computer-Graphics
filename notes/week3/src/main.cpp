#include "main.h"

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

    glColor4f(0.5, 0.3, 1.0, 1.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(x0, y0);

    while (x >= y)
    {
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

void drawTriangles(void) {
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
        glColor4f(colors[i][R], colors[i][G],
                  colors[i][B], colors[i][A]);
    }
    glEnd();
}

void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // White Background
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load an identity matrix
    glLoadIdentity();

    // drawTriangles();
    drawCircle(240, 240, 100);

    // to make the transperancy take effect,
    // this is necessary
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    // display it
    if (doubleBuffer) {
        glutSwapBuffers();
    } else {
        glFlush();
    }
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLfloat)w, 0, (GLfloat)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    // display mode
    GLenum type = GLUT_RGBA | GLUT_DEPTH;
    type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
    glutInitDisplayMode(type);

    // size of window
    glutInitWindowSize(640, 480);

    // create the window
    glutCreateWindow("week3");

    // notice that this function should be placed
    // after createWindow()
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}