
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	// Draw a Red 1x1 Square centered at origin
    float a = 0.0f;
    float b = 0.08f;
    float c = 0.1f;

    float r = 1.0f;

    float g = 0.0f;
    float bl = 0.0f;

    //1st row
	for(int i = 0; i<12; i++){
       glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(r, g, bl); // Red

	glVertex2f(a, 0.0f);    // x, y
	glVertex2f(b, 0.0f);
	glVertex2f((a+b)/2,  0.08f);

	a+=0.08;
	b+=0.08;
	glEnd();

	g = r;
	r = bl;
	bl = g;



	}
//2nd row
	for(int i = 0; i<10; i++){
       glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(r, g, bl); // Red

	glVertex2f(a, 0.08f);    // x, y
	glVertex2f(b, 0.08f);
	glVertex2f((a+b)/2,  0.08f);

	a+=0.08;
	b+=0.08;
	glEnd();

	g = r;
	r = bl;
	bl = g;



	}


	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Class Task-2"); // Create a window with the given title
	glutInitWindowSize(500, 500);   // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
