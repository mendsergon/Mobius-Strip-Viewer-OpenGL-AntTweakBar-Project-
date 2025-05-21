#ifndef MOBIUS_STRIP_VIEW_TRANSFORMATION_FUNCTIONS_H
#define MOBIUS_STRIP_VIEW_TRANSFORMATION_FUNCTIONS_H

#include <GL/glut.h>
#include <AntTweakBar.h>

// Window dimensions
extern int windowWidth;
extern int windowHeight;

// Projection Parameters
extern float fov;
extern float aspect;
extern float zNear;
extern float zFar;

// Model transformation parameters
extern float translateX, translateY, translateZ;
extern float rotateX, rotateY, rotateZ;
extern float scaleX, scaleY, scaleZ;

// Initalization and cleanup
void initGLUTCallbacks();
void initAntTweakBar();
void cleanup();

// GLUT callbacks
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

// Drawing 
void drawMobiusStrip();

// Matrix utilities
void matrixPerspective(float fovY, float aspect, float zNear, float zFar);
void matrixTranslate(float x, float y, float z);
void matrixRotate(float angleX, float angleY, float angleZ);
void matrixScale(float x, float y, float z);

#endif  