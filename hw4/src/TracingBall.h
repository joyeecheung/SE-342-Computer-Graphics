#ifndef TRACING_BALL_H
#define TRACING_BALL_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>
#include <map>
#include <string>

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


struct Menu {
    int id;
    int entry;
    bool visible;
};

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

void createMenu(int button, std::map<std::string, int> entries,
            int defaultEntry);
void onMenu(int num);
void menuState(int status);

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
