#include <exception>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

// Color structure
struct GLColorRGB {
    float r, g, b;
};

// Vertex structure
struct Vertex {
    float x, y;
};

// Helper function to convert hex color to GL color
GLColorRGB toGLColorRGB(unsigned int hex) {
    return {
        ((hex >> 16) & 0xFF) / 255.0f,
        ((hex >> 8) & 0xFF) / 255.0f,
        (hex & 0xFF) / 255.0f
    };
}

GLColorRGB toGLColorRGB(int r, int g, int b) {
    return {r / 255.0f, g / 255.0f, b / 255.0f};
}

// Helper drawing functions
void drawQuad(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawVertices(const vector<Vertex>& vertices) {
    for (const auto& vertex : vertices) {
        glVertex2f(vertex.x, vertex.y);
    }
}

// Bezier curve calculation
vector<Vertex> getQuadBezierCurvePoints(Vertex* controlPoints, int numPoints = 100) {
    vector<Vertex> points;
    for (int i = 0; i <= numPoints; i++) {
        float t = (float)i / numPoints;
        float x = (1 - t) * (1 - t) * controlPoints[0].x +
                  2 * (1 - t) * t * controlPoints[1].x +
                  t * t * controlPoints[2].x;
        float y = (1 - t) * (1 - t) * controlPoints[0].y +
                  2 * (1 - t) * t * controlPoints[1].y +
                  t * t * controlPoints[2].y;
        points.push_back({x, y});
    }
    return points;
}

void drawBridgeCables(GLColorRGB color) {
    static bool ran_once = false;
    static vector<vector<Vertex>> interpolated_vertices;

    if (!ran_once) {
        vector<Vertex> cables[] = {
            {{455, 256}, {(1469.2 + 455) / 2, 650}, {1469.2, 256}},
            {{480.8, 423}, {(480.8 + 1447.1) / 2, 530}, {1447.1, 423}},
            {{0, 496}, {250, 496}, {405.2, 293.8}},
            {{0, 496}, {300, 496}, {405.2, 377}},
            {{1920, 496}, {1733, 496}, {1522.7, 302.2}},
            {{1920, 496}, {1733, 496}, {1522.7, 384.9}}
        };

        for (auto cable : cables) {
            interpolated_vertices.push_back(getQuadBezierCurvePoints(cable.data()));
        }
        ran_once = true;
    }

    glColor3fv((GLfloat *)&color);
    for (auto vertices : interpolated_vertices) {
        glLineWidth(8);
        glBegin(GL_LINE_STRIP);
        drawVertices(vertices);
        glEnd();

        for (int i = 1; i < vertices.size(); i += 10) {
            auto vertex = vertices[i];
            glLineWidth(5);
            drawLine(vertex.x, vertex.y, vertex.x, 505);
        }
    }
}

void drawBridgeTowers(GLColorRGB color, GLColorRGB shadow_color) {
    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(407.8, 168, 13.5, 76.4);
    glColor3fv((GLfloat *)&color);
    drawQuad(407.8, 168, 9, 76.4);
    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(449.9, 168, 13.5, 76.4);
    glColor3fv((GLfloat *)&color);
    drawQuad(449.9, 168, 9, 76.4);
    glColor3fv((GLfloat *)&color);
    drawQuad(407.8, 183.2, 55.6, 6.4);

    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(396.5, 243.7, 17.4, 65.5);
    glColor3fv((GLfloat *)&color);
    drawQuad(396.5, 243.7, 11.6, 65.5);
    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(450.8, 243.7, 17.4, 65.5);
    glColor3fv((GLfloat *)&color);
    drawQuad(450.8, 243.7, 11.6, 65.5);
    glColor3fv((GLfloat *)&color);
    drawQuad(396.5, 240.6, 71.7, 4.1);

    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(386.1, 313.9, 22.4, 84.4);
    glColor3fv((GLfloat *)&color);
    drawQuad(386.1, 313.9, 15, 84.4);
    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(456.1, 313.9, 22.4, 84.4);
    glColor3fv((GLfloat *)&color);
    drawQuad(456.1, 313.9, 15, 84.4);
    glColor3fv((GLfloat *)&color);
    drawQuad(386.1, 309, 92.5, 5.3);

    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(372.7, 405, 28.9, 108.8);
    glColor3fv((GLfloat *)&color);
    drawQuad(372.7, 405, 19.3, 108.8);
    glColor3fv((GLfloat *)&shadow_color);
    drawQuad(463, 405, 28.9, 108.8);
    glColor3fv((GLfloat *)&color);
    drawQuad(463, 405, 19.3, 108.8);
    glColor3fv((GLfloat *)&color);
    drawQuad(372.7, 398.1, 119.2, 6.9);
}

void drawBridge(GLColorRGB bridge_color, GLColorRGB cables_color, GLColorRGB shadow_color) {
    drawBridgeCables(cables_color);

    // left towers
    drawBridgeTowers(bridge_color, shadow_color);

    // right towers
    glPushMatrix();
    glTranslated(1062, 0, 0);
    drawBridgeTowers(bridge_color, shadow_color);
    glPopMatrix();

    // Main bridge deck
    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(0, 560);
    glVertex2f(1920, 560);
    glVertex2f(1920, 500);
    glVertex2f(0, 500);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(1.0);

    glVertex2f(0, 560);
    glVertex2f(1920, 560);
    glVertex2f(1920, 500);
    glVertex2f(0, 500);
    glEnd();

    glBegin(GL_QUADS); // Upper shadow
    glColor3fv((GLfloat *)&shadow_color);
    glVertex2f(0, 510);
    glVertex2f(1920, 510);
    glVertex2f(1920, 500);
    glVertex2f(0, 500);
    glEnd();

    glBegin(GL_LINES); // Upper shadow
    glColor3f(0,0,0);
    glVertex2f(0, 510);
    glVertex2f(1920, 510);
    glVertex2f(1920, 500);
    glVertex2f(0, 500);
    glEnd();





    // LEFT PILLAR
    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(325, 560);
    glVertex2f(325, 585);
    glVertex2f(415, 585);
    glVertex2f(415, 560);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(325, 560);
    glVertex2f(325, 585);
    glVertex2f(415, 585);
    glVertex2f(415, 560);
    glEnd();

    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(350, 585);
    glVertex2f(350, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(350, 585);
    glVertex2f(350, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();

    glBegin(GL_QUADS); // Shadow
    glColor3fv((GLfloat *)&shadow_color);
    glVertex2f(378, 585);
    glVertex2f(378, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();





    // Second left pillar
    glPushMatrix();
    glTranslated(120, 0, 0);
    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(325, 560);
    glVertex2f(325, 585);
    glVertex2f(415, 585);
    glVertex2f(415, 560);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(1.0);

    glVertex2f(325, 560);
    glVertex2f(325, 585);
    glVertex2f(415, 585);
    glVertex2f(415, 560);
    glEnd();

    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(350, 585);
    glVertex2f(350, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(1.0);

    glVertex2f(350, 585);
    glVertex2f(350, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();


    glBegin(GL_QUADS); // Shadow
    glColor3fv((GLfloat *)&shadow_color);
    glVertex2f(378, 585);
    glVertex2f(378, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();
    glPopMatrix();

    // RIGHT PILLARS
    glPushMatrix();
    glTranslated(1060, 0, 0);
    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(325, 560);
    glVertex2f(325, 585);
    glVertex2f(415, 585);
    glVertex2f(415, 560);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glLineWidth(1.0);

    glVertex2f(325, 560);
    glVertex2f(325, 585);
    glVertex2f(415, 585);
    glVertex2f(415, 560);
    glEnd();

    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(350, 585);
    glVertex2f(350, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();

    glBegin(GL_QUADS); // Shadow
    glColor3fv((GLfloat *)&shadow_color);
    glVertex2f(378, 585);
    glVertex2f(378, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();

    glPushMatrix();
    glTranslated(120, 0, 0);
    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(325, 560);
    glVertex2f(325, 585);
    glVertex2f(415, 585);
    glVertex2f(415, 560);
    glEnd();

    glBegin(GL_QUADS);
    glColor3fv((GLfloat *)&bridge_color);
    glVertex2f(350, 585);
    glVertex2f(350, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();

    glBegin(GL_QUADS); // Shadow
    glColor3fv((GLfloat *)&shadow_color);
    glVertex2f(378, 585);
    glVertex2f(378, 745);
    glVertex2f(390, 745);
    glVertex2f(390, 585);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void resize(int width, int height) {
    if (height == 0) {
        height = 1;
    }

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, -1);

    glMatrixMode(GL_MODELVIEW);
}

void displayFunc() {
    glClearColor(0.5f, 0.7f, 0.9f, 1.0f); // Light blue background
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw the bridge with sunset colors
    drawBridge(toGLColorRGB(149, 36, 49), toGLColorRGB(0xbe1e2d), toGLColorRGB(182, 60, 74));

    glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
    if (key == 27) { // ESC key
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Bridge Standalone");

    glutDisplayFunc(displayFunc);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyPressed);

    cout << "Bridge rendering program started." << endl;
    cout << "Press ESC to exit." << endl;

    glutMainLoop();

    return 0;
}
