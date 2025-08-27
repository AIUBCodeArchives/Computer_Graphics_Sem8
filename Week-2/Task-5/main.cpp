#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color



    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // Red

	glVertex2f(0.2f, 0.4f);
	glVertex2f(0.6f, 0.4f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.2f, 0.6f);

	glEnd();

    glBegin(GL_TRIANGLES);//
    // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.6f, 0.8f);    // x, y
	glVertex2f(0.6f,0.2f);
	glVertex2f(0.8f, 0.5f);
	glEnd();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor4f(1.0f, 0.0f, 0.0f, 0.2f); // red with 50% transparency

	glVertex2f(-0.8f, 0.8f);    // x, y
	glVertex2f(-0.2f, 0.8f);
	glVertex2f(-0.2f, 0.2f);    // x, y
	glVertex2f(-0.8f, 0.2f);

	glEnd();



    glBegin(GL_TRIANGLES);//
    // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.2f, -0.1f);    // x, y
	glVertex2f(-0.2f,-0.8f);
	glVertex2f(-0.8f, -0.4f);
	glEnd();


    glBegin(GL_TRIANGLES);//
    // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.2f);    // x, y
	glVertex2f(0.8f,-0.8f);
	glVertex2f(0.2f, -0.8f);
	glEnd();

	glLineWidth(2.5);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-1.0f, 0.0f);   // x, y
	glVertex2f(1.0f, 0.0f);    // x, y
	 // Red
	glVertex2f(0.0f, 1.0f);    // x, y
	glVertex2f(0.0f, -1.0f);

	glEnd();



	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
