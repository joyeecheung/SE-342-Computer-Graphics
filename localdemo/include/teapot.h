#ifndef TEAPOT_H
#define TEAPOT_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

// GLUT callbacks and functions

void initGlut(int argc, char **argv);
void displayFunc(void);
void idleFunc(void);
void reshapeFunc(int width, int height);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);
void keyboardFunc(unsigned char key, int x, int y);
void specialFunc(int key, int x, int y);

// other [OpenGL] functions
void countFrames(void);
void renderBitmapString(float x, float y, float z,
                        void *font, char *string);


bool bUsePredefinedCamera = true;

bool bFullsreen = false;
int nWindowID;

// camera attributes
float viewerPosition[3]  = { 0.0, 0.0, -50.0 };
float viewerDirection[3] = { 0.0, 0.0, 0.0 };
float viewerUp[3]        = { 0.0, 1.0, 0.0 };

// rotation values for the navigation
float navigationRotation[3] = { 0.0, 0.0, 0.0 };

// parameters for the framecounter
char pixelstring[30];
int cframe = 0;
int time = 0;
int timebase = 0;

//-----------------------------------------------------------------------------

// parameters for the navigation

// position of the mouse when pressed
int mousePressedX = 0, mousePressedY = 0;
float lastXOffset = 0.0, lastYOffset = 0.0, lastZOffset = 0.0;
// mouse button states
int leftMouseButtonActive = 0;
int middleMouseButtonActive = 0;
int rightMouseButtonActive = 0;
// modifier state
int shiftActive = 0, altActive = 0, ctrlActive = 0;


bool init = false;

#endif
