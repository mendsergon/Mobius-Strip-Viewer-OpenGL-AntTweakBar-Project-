#include <GL/glut.h>
#include <AntTweakBar.h>
#include <cmath>
#include <cstring>
#include "mobius_strip_view_transformation_functions.h"

const float PI = 3.14159f;

// Globals
int windowWidth = 800;
int windowHeight = 600;

float fov = 45.0f;
float aspect = float(windowWidth) / float(windowHeight);
float zNear = 0.1f;
float zFar = 100.0f;

float translateX = 0, translateY = 0, translateZ = -3;
float rotateX = 0, rotateY = 0, rotateZ = 1;
float scaleX = 1, scaleY = 1, scaleZ = 1;

// Initialize GLUT callbacks
void initGLUTCallbacks() {
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(display);
}

// Initialize AntTweakBar GUI
void initAntTweakBar() {
    TwInit(TW_OPENGL, NULL);
    TwWindowSize(windowWidth, windowHeight);
    TwBar* bar = TwNewBar("TweakBar");
    TwAddVarRW(bar, "FOV", TW_TYPE_FLOAT, &fov, "min=10 max=120 step=1");
    TwAddVarRW(bar, "Aspect", TW_TYPE_FLOAT, &aspect, "min=0.1 max=4 step=0.01");
    TwAddVarRW(bar, "Near", TW_TYPE_FLOAT, &zNear, "min=0.01 max=10 step=0.01");
    TwAddVarRW(bar, "Far", TW_TYPE_FLOAT, &zFar, "min=1 max=1000 step=1");
    TwAddVarRW(bar, "TransX", TW_TYPE_FLOAT, &translateX, "min=-10 max=10 step=0.1");
    TwAddVarRW(bar, "TransY", TW_TYPE_FLOAT, &translateY, "min=-10 max=10 step=0.1");
    TwAddVarRW(bar, "TransZ", TW_TYPE_FLOAT, &translateZ, "min=-20 max=0 step=0.1");
    TwAddVarRW(bar, "RotX", TW_TYPE_FLOAT, &rotateX, "min=0 max=360 step=1");
    TwAddVarRW(bar, "RotY", TW_TYPE_FLOAT, &rotateY, "min=0 max=360 step=1");
    TwAddVarRW(bar, "RotZ", TW_TYPE_FLOAT, &rotateZ, "min=0 max=360 step=1");
    TwAddVarRW(bar, "ScaleX", TW_TYPE_FLOAT, &scaleX, "min=0.1 max=5 step=0.1");
    TwAddVarRW(bar, "ScaleY", TW_TYPE_FLOAT, &scaleY, "min=0.1 max=5 step=0.1");
    TwAddVarRW(bar, "ScaleZ", TW_TYPE_FLOAT, &scaleZ, "min=0.1 max=5 step=0.1");
}

// Cleanup AntTweakBar
void cleanup() {
    TwTerminate();
}

// Reshape callback
void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;
    aspect = float(w) / float(h);
    glViewport(0, 0, w, h);
    TwWindowSize(w, h);
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    matrixPerspective(fov, aspect, zNear, zFar);

    // Modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    matrixTranslate(translateX, translateY, translateZ);
    matrixRotate(rotateX, rotateY, rotateZ);
    matrixScale(scaleX, scaleY, scaleZ);

    // Draw Mobius Strip
    drawMobiusStrip();

    TwDraw();
    glutSwapBuffers();
}

// Keyboard callback
void keyboard(unsigned char key, int x, int y) {
    if (TwEventKeyboardGLUT(key, x, y)) return;
    if (key == 27) exit(0); 
}

// Draw Mobius Strip
void drawMobiusStrip() {}

// Matrix utility stubs
void matrixPerspective(float fovY, float aspect, float zNear, float zFar) {
    float fH = tan(fovY / 360.0f * PI) * zNear;
    float fW = fH * aspect;
    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}

void matrixTranslate(float x, float y, float z) {
    float m[16];
    memset(m, 0, sizeof(m));
    m[0] = m[5] = m[10] = m[15] = 1.0f;
    m[12] = x;
    m[13] = y;
    m[14] = z;
    glMultMatrixf(m);
}

void matrixRotate(float angleX, float angleY, float angleZ) {
    float radX = angleX * PI / 180.0f;
    float radY = angleY * PI / 180.0f;
    float radZ = angleZ * PI / 180.0f;

    float rx[16] = {
        1, 0, 0, 0,
        0, cosf(radX), -sinf(radX), 0,
        0, sinf(radX), cosf(radX), 0,
        0, 0, 0, 1
    };
    float ry[16] = {
        cosf(radY), 0, sinf(radY), 0,
        0, 1, 0, 0,
        -sinf(radY), 0, cosf(radY), 0,
        0, 0, 0, 1
    };
    float rz[16] = {
        cosf(radZ), -sinf(radZ), 0, 0,
        sinf(radZ), cosf(radZ), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(rz);
    glMultMatrixf(ry);
    glMultMatrixf(rx);
}

void matrixScale(float x, float y, float z) {
    float m[16];
    memset(m, 0, sizeof(m));
    m[0] = x;
    m[5] = y;
    m[10] = z;
    m[15] = 1.0f;
    glMultMatrixf(m);
}