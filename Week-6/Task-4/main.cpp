#include <GL/glut.h>
#include <math.h>

// Angles for rotation
float sunRotate = 0.0f;
float earthOrbit = 0.0f, earthRotate = 0.0f;
float moonOrbit = 0.0f, moonRotate = 0.0f;

void drawSquare(float size) {
    float half = size / 2.0f;
    glBegin(GL_QUADS);
        glVertex2f(-half, -half);
        glVertex2f( half, -half);
        glVertex2f( half,  half);
        glVertex2f(-half,  half);
    glEnd();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // ------------------- SUN -------------------
    glPushMatrix();
        glRotatef(sunRotate, 0, 0, 1);   // Sun rotates on its own axis
        glColor3f(1.0, 1.0, 0.0);        // Yellow Sun
        drawSquare(0.4);                 // Bigger square Sun
    glPopMatrix();

    // ------------------- EARTH -------------------
    glPushMatrix();
        glRotatef(earthOrbit, 0, 0, 1);  // Earth orbits around Sun
        glTranslatef(0.9, 0, 0);         // Distance from Sun

        glPushMatrix();
            glRotatef(earthRotate, 0, 0, 1); // Earth rotates on its axis
            glColor3f(0.0, 0.0, 1.0);        // Blue Earth
            drawSquare(0.2);
        glPopMatrix();

        // ------------------- MOON -------------------
        glPushMatrix();
            glRotatef(moonOrbit, 0, 0, 1); // Moon orbits around Earth
            glTranslatef(0.3, 0, 0);       // Distance from Earth
            glRotatef(moonRotate, 0, 0, 1); // Moon rotates on its axis
            glColor3f(0.7, 0.7, 0.7);       // Grey Moon
            drawSquare(0.1);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    // Increment angles
    sunRotate += 0.5f;
    if (sunRotate > 360) sunRotate -= 360;

    earthOrbit += 0.2f;
    if (earthOrbit > 360) earthOrbit -= 360;

    earthRotate += 1.0f;
    if (earthRotate > 360) earthRotate -= 360;

    moonOrbit += 2.0f;
    if (moonOrbit > 360) moonOrbit -= 360;

    moonRotate += 4.0f;
    if (moonRotate > 360) moonRotate -= 360;

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Mini Solar System - Squares");

    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    gluOrtho2D(-2, 2, -2, 2);

    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}
