#ifndef DODECAHEDRON_H
#define DODECAHEDRON_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>
#include <cstdlib>

class Polyhedron {
public:
  void load(const char *filename);
  float randomIntensity(void);
  void generateColors(void);
  void draw(GLenum type);
  ~Polyhedron();
private:

  int vertexCount;
  int surfaceCount;
  int edgeCount;

  GLfloat **colors;
  GLfloat **vertices;
  GLushort **indices;
  int *surfaceVertices;
};

#endif