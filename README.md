## Mobius Strip Viewer (OpenGL + AntTweakBar Project)

### Project Summary

This C++ project renders a **3D Mobius strip** using **OpenGL** for graphics and **AntTweakBar** for real-time GUI control. The program allows users to interactively **translate, rotate, and scale** the strip, as well as adjust camera parameters such as **FOV, aspect ratio, and clipping planes**. The application demonstrates **3D graphics transformations**, matrix manipulation, and GUI integration.

---

### Core Features

* Render a 3D Mobius strip with adjustable resolution.
* Real-time **translation, rotation, and scaling** via GUI sliders.
* Adjustable camera parameters: **FOV, aspect ratio, near/far planes**.
* Interactive keyboard and mouse controls with GLUT and AntTweakBar.
* Projection and modelview matrix transformations implemented manually.
* Double-buffered rendering for smooth animation.

---

### Key Methods and Algorithms

* **Parametric Surface Rendering:** Mobius strip defined parametrically with `u` and `v` coordinates.
* **Matrix Transformations:** Custom functions for **perspective projection, translation, rotation, and scaling**.
* **OpenGL Rendering:** Uses `GL_LINE_STRIP` to draw the strip mesh along parametric lines.
* **GUI Integration:** AntTweakBar allows real-time manipulation of all transformation and camera parameters.
* **Event Handling:** GLUT handles display, reshape, keyboard, and mouse callbacks for responsive interaction.

---

### Skills Demonstrated

* 3D graphics programming using **OpenGL**.
* Real-time GUI development with **AntTweakBar**.
* Parametric surface modeling and visualization.
* Manual construction and application of **projection and modelview matrices**.
* Event-driven programming with **GLUT callbacks**.
* Integration of multiple source files and modular design in C++.

---

### File Overview

| File Name                                          | Description                                                                            |
| -------------------------------------------------- | -------------------------------------------------------------------------------------- |
| **main.cpp**                                       | Entry point: initializes GLUT, sets up GUI, and starts loop.                           |
| **mobius_strip_view_transformation_functions.h**   | Header file declaring matrices, callbacks, and drawing routines.                       |
| **mobius_strip_view_transformation_functions.cpp** | Implementation of transformation matrices, Mobius strip rendering, and GLUT callbacks. |

---

### How to Compile and Run

1. Install OpenGL, GLUT, and AntTweakBar libraries.
2. Compile using a C++ compiler (example for g++ on Linux/macOS):

```bash
g++ main.cpp mobius_strip_view_transformation_functions.cpp -o mobius_viewer -lGL -lGLU -lglut -lAntTweakBar
```

3. Run the program:

```bash
./mobius_viewer
```

4. Use the GUI sliders to manipulate the Mobius strip and camera parameters in real time.

---
