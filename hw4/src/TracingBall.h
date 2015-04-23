#ifndef TRACING_BALL_H
#define TRACING_BALL_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>
#include <map>
#include <string>

class Window {
public:
    Window(int w = 640, int h = 480)
        : width(w), height(h), isFullScreen(false) {
        aspect = (GLfloat) width / (GLfloat) height;
        oldWidth = width;
        oldHeight = height;
    }
    void create(const char* title) {
        glutInitWindowSize (width, height);
        id = glutCreateWindow(title);
    }
    void toggleFullScreen() {
        isFullScreen = !isFullScreen;
        if (isFullScreen) {
            glutFullScreen();
            oldWidth = width;
            oldHeight = height;
        } else {
            glutSetWindow(id);
            glutReshapeWindow(oldWidth, oldHeight);
        }
    }
    void update(int w, int h) {
        width = w;
        height = h;
        aspect = (GLfloat)w / (GLfloat)h;
    }

    int width, height;
    GLfloat aspect;

private:
    bool isFullScreen;
    int id;
    int oldWidth, oldHeight;
};

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

class Tracer {
public:
    Tracer() : leftActive(false), middleActive(false),
                rightActive(false), translateFactor(30.0) {

    }
private:
    Camera camera;
    GLfloat translateFactor;

    bool leftActive;
    bool middleActive;
    bool rightActive;
    Vector3 mouse;
    Vector3 lastOffset;
};

void createMenu(int button, std::map<std::string, int> entries,
            int defaultEntry);
void onMenu(int num);
void menuState(int status);

struct Menu {
    int id;
    int entry;
    bool visible;
};

void onMenu(int num);

extern Window window;
extern Menu menu;

// enums
extern const int SOLID;
extern const int WIREFRAME;
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

void mouseFunc(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char key, int x, int y);

float randomIntensity(void);
void generateColors(GLfloat colors[][3], int surfaceCount);
void draw(GLenum type);
#endif
