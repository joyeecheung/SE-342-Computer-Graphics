#ifndef TRACER_H
#define TRACER_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>

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
                rightActive(false), translateFactor(30.0) {}
    void init();
    void transform();
    void onMouse(int button, int state, int x, int y);
    void onMouseMotion(int x, int y);
private:
    Camera camera;
    GLfloat translateFactor;

    bool leftActive;
    bool middleActive;
    bool rightActive;
    Vector3 mouse;
    Vector3 lastOffset;
};

#endif