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
extern int width, height;
extern GLfloat aspect;

// lighting
extern GLfloat lightpos[4];

struct Vector3 {
    float x;
    float y;
    float z;

    void set(const float arr[3]) {
        x = arr[0];
        y = arr[1];
        z = arr[2];
    }
};

// camera attributes
struct Camera {
    Vector3 position;
    Vector3 direction;
    Vector3 rotation;

    void set(float pos[3], float dir[3], float rot[3]) {
        position.set(pos);
        direction.set(dir);
        rotation.set(rot);
    }
};

extern Camera camera;
extern GLfloat translateFactor;

// mouse button states
extern bool leftActive;
extern bool middleActive;
extern bool rightActive;
extern bool startRotation;
extern bool startTranslation;

extern Vector3 mouse;
extern Vector3 lastOffset;

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
void initCamera(Camera &camera);

void display(void);
void reshape(int width, int height);
void idle(void);

int createMenu(void);
void menuState(int status);
void menu(int num);

void mouseFunc(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char key, int x, int y);

float randomIntensity(void);
void generateColors(GLfloat colors[][3], int surfaceCount);
void draw(GLenum type);
#endif
