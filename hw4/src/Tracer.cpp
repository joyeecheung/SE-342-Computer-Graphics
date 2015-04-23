#include "Tracer.h"
#include <cmath>

void Tracer::init() {
    float position[3]  = { 0.0, 0.0, -10.0 };
    float direction[3] = { 0.0, 0.0, 0.0 };
    float rotation[3] = { 0.0, 0.0, 0.0 };

    camera.set(position, direction, rotation);

    float zeros[3] = {0.0, 0.0, 0.0};
    mouse.set(zeros);
    lastOffset.set(zeros);
}

void Tracer::transform() {
    glTranslatef(camera.position.x, camera.position.y, camera.position.z);
    glRotatef(camera.rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(camera.rotation.y, 0.0f, 1.0f, 0.0f);
}

void Tracer::onMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            leftActive = true;
        } else {
            leftActive = false;
        }
        mouse.x = x;
        mouse.y = y;
    } else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            rightActive = true;
            lastOffset.x = 0.0;
            lastOffset.y = 0.0;
        } else {
            rightActive = false;
        }
        mouse.x = x;
        mouse.y = y;
    }
}

void Tracer::onMouseMotion(int x, int y) {
    float xOffset = 0.0, yOffset = 0.0, zOffset = 0.0;
    if (leftActive) { // rotating
        camera.rotation.x += (mouse.y - y);
        camera.rotation.y += (mouse.x - x);

        mouse.y = y;
        mouse.x = x;
    } else if (rightActive) { // translating
        xOffset = (mouse.x + x);
        if (fabs(lastOffset.x - 0.0) > 1e-6) {
            camera.position.x  -= (xOffset - lastOffset.x) / translateFactor;
            camera.direction.x -= (xOffset - lastOffset.x) / translateFactor;
        }
        lastOffset.x = xOffset;
        yOffset = (mouse.y + y);
        if (fabs(lastOffset.y - 0.0) > 1e-6) {
            camera.position.y  += (yOffset - lastOffset.y) / translateFactor;
            camera.direction.y += (yOffset - lastOffset.y) / translateFactor;
        }
        lastOffset.y = yOffset;
    }
}