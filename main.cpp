#include <GL/glut.h>
#include <AntTweakBar.h>
#include "mobius_strip_view_transformation_functions.h"

int main(int argc, char** argv) {
    // Initiate GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobius Strip Viewer");

    // Call setup functions
    initGLUTCallbacks();
    initAntTweakBar();

    // Enter loop
    glutMainLoop();
    cleanup();
    return 0;
}