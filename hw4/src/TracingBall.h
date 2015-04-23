#ifndef TRACING_BALL_H
#define TRACING_BALL_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

// enums
extern const int SOLID;
extern const int WIREFRAME;

// variables

// window attribute
extern bool isFullScreen;
extern int windowID;
extern int width;
extern GLfloat aspect;

// lighting
extern GLfloat lightpos[4];

// camera attributes
extern float cameraPosition[3];
extern float cameraDirection[3];
extern float cameraRotation[3];
extern GLfloat translateFactor;

// mouse button states
extern bool leftActive;
extern bool middleActive;
extern bool rightActive;

// position of the mouse when pressed
extern int mouseX;
extern float lastX;

// menu attributes
extern int menuID;
extern int menuEntry;
extern bool menuMode;

// data
extern const int vertexCount;
extern const int surfaceCount;
extern const int edgeCount;
extern GLfloat colors[][3];
extern GLfloat vertices[][3];
extern GLushort indices[][5];

// callbacks and functions
void init(int argc, char **argv);
void display(void);
void reshape(int width, int height);
void idle(void);

int createMenu(void);
void menuState(int status);
void menu(int num);

void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char key, int x, int y);

float randomIntensity(void);
void generateColors(GLfloat colors[][3], int surfaceCount);
void draw(GLenum type);
#endif
