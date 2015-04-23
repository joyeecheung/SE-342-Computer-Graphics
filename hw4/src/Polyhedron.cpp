#include "Polyhedron.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

void Polyhedron::load(const char *filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        throw "Can not open the specified file\n";
    }

    char buffer[256] = {0};

    // read the first 3 char of the file
    fread(buffer, sizeof(char), 3, fp);
    if (buffer[0] != 'O' || buffer[1] != 'F' || buffer[2] != 'F') {
        throw "Can not handle the file type\n";
    }

    float temp;
    fscanf(fp, "%d %d %d", &vertexCount, &surfaceCount, &edgeCount);

    vertices = (GLfloat **)malloc(sizeof(GLfloat *) * vertexCount);
    for (int i = 0; i < vertexCount; ++i) {
        vertices[i] = (GLfloat *)malloc(sizeof (GLfloat) * 3);
        for (int j = 0; j < 3; ++j) {
            fscanf(fp, "%f", &temp);
            vertices[i][j] = temp;
        }
    }

    indices = (GLushort **)malloc(sizeof(GLushort *) * surfaceCount);
    surfaceVertices = (int *)malloc(sizeof(int) * surfaceCount);

    int tempi;
    for (int i = 0; i < surfaceCount; ++i) {
        fscanf(fp, "%d", &(surfaceVertices[i]));
        indices[i] = (GLushort *)malloc(sizeof (GLushort) * surfaceVertices[i]);
        for (int j = 0; j < surfaceVertices[i]; ++j) {
            fscanf(fp, "%d", &tempi);
            indices[i][j] = tempi;
        }
    }

    fclose(fp);
    generateColors();
}

float Polyhedron::randomIntensity(void) {
    return (rand() % 256) / 256.0;
}

void Polyhedron::generateColors() {
    colors = (GLfloat **)malloc(sizeof(GLfloat *) * surfaceCount);

    for (int i = 0; i < surfaceCount; ++i) {
        colors[i] = (GLfloat *)malloc(sizeof (GLfloat) * 3);
        for (int j = 0; j < 3; ++j) {
            colors[i][j] = randomIntensity();
        }
    }
}

void Polyhedron::draw(GLenum type) {
    for (int i = 0; i < surfaceCount; ++i) {
        glBegin(type);
        glColor3fv(colors[i]);

        for (int j = 0; j < surfaceVertices[i]; ++j) {
            int v = indices[i][j];
            glVertex3fv(vertices[v]);
        }
        glEnd();
    }
}

Polyhedron::~Polyhedron() {
    for (int i = 0; i < vertexCount; ++i) {
        free(vertices[i]);
    }

    for (int i = 0; i < surfaceCount; ++i) {
        free(indices[i]);
        free(colors[i]);
    }

    free(vertices);
    free(colors);
    free(indices);
}