#ifndef TRACING_BALL_H
#define TRACING_BALL_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

// GLUT callbacks and functions

void init(int argc, char **argv);
void display(void);
void idle(void);
void reshape(int width, int height);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char key, int x, int y);
void menu(int num);
void createMenu(void);

bool isFullScreen = false;
int windowID;

// camera attributes
float cameraPosition[3]  = { 0.0, 0.0, -10.0 };
float cameraDirection[3] = { 0.0, 0.0, 0.0 };

// rotation values for the navigation
float cameraRotation[3] = { 0.0, 0.0, 0.0 };

//-----------------------------------------------------------------------------

// parameters for the navigation

// position of the mouse when pressed
int mouseX = 0, mouseY = 0;
float lastXOffset = 0.0, lastYOffset = 0.0, lastZOffset = 0.0;
// mouse button states
int leftActive = 0;
int middleActive = 0;
int rightActive = 0;
// modifier state
int shiftActive = 0, altActive = 0, ctrlActive = 0;

GLfloat lightpos[4] = { 5.0, 15.0, 10.0, 1.0 };

int menuId;
int menuEntry = 1;
bool menuMode = false;
#endif
