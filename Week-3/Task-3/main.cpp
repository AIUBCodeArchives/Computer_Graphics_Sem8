/*
* GL02Primitive.cpp: Vertex, Primitive and Color
* Draw Simple 2D colored Shapes: quad, triangle and polygon.
*/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color


//base
glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.8f, 0.6f); // Red

	glVertex2f(-0.2f, -0.7f);
	glVertex2f(-0.2f, -0.8f);
	glVertex2f(0.2f, -0.8f);
	glVertex2f(0.2f, -0.7f);

	glEnd();




	glLineWidth(7.5);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.0f, -0.7f);    // x, y
	glVertex2f(0.0f, 0.3f);    // x, y

	glEnd();
//light
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red

	glVertex2f(-0.1f, 0.3f);
	glVertex2f(0.1f, 0.3f);
	glVertex2f(0.1f, 0.45f);
	glVertex2f(-0.1f, 0.45f);

	glEnd();


//cover
	glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.8f, 0.6f); // Red

	glVertex2f(-0.15f, 0.45f);    // x, y
	glVertex2f(0.15f, 0.45f);
	glVertex2f(0.0f,  0.6f);

	glEnd();










	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
	glutInitWindowSize(500, 500);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
