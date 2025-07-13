This is a simple interactive C++ program that uses OpenGL to render a 3D Möbius strip using only primitive drawing functions (lines) and manually implemented transformation matrices. The main purpose of the project is to allow real-time manipulation of perspective projection parameters and object transformations through a graphical user interface, built with AntTweakBar.

Users can adjust the field of view angle (θ), aspect ratio, and the near and far clipping planes to experiment with different projection setups. Additionally, the object itself can be translated, rotated, and scaled along all three axes. All transformations are performed using custom matrix operations, without relying on OpenGL’s built-in transformation functions like glTranslatef, glRotatef, or glScalef.

The Möbius strip is rendered using only basic OpenGL primitives in 2D, following the project requirement to avoid using complex or high-level 3D drawing methods. Despite the original assignment suggesting a cube, a Möbius strip was chosen instead to provide a more interesting geometric form while still adhering to the project constraints.

The GUI is handled using AntTweakBar, which enables easy real-time tweaking of all projection and transformation parameters. The application supports basic interaction via the keyboard (Esc key to exit) and mouse through the tweak bar. It requires OpenGL, GLUT (such as FreeGLUT), and AntTweakBar to compile and run.

This project demonstrates the fundamentals of manual transformation pipelines in OpenGL and offers an interactive environment for learning and visual experimentation with 3D geometry and perspective.
