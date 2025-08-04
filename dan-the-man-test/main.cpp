// Dan the Man-style platformer with sprite, coins, gravity, terrain
// Requirements: stb_image.h and a "dan.png" sprite image

#include <GL/glut.h>
#include <vector>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

struct Rect {
    float x, y, w, h;
    Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}
    bool collidesWith(const Rect& o) const {
        return !(x + w < o.x || x > o.x + o.w || y + h < o.y || y > o.y + o.h);
    }
};

struct Coin {
    Rect rect;
    bool collected = false;
    Coin(float x, float y) : rect(x, y, 15, 15) {}
};

int winW = 800, winH = 600;
Rect player(50, 100, 40, 50);
float gravity = 0.4f, velocityY = 0;
bool isJumping = false, gameOver = false, youWin = false;
Rect enemy(600, 100, 30, 50);
bool enemyDirRight = false;
GLuint danTexture;

std::vector<Rect> platforms = {
    Rect(0, 0, 800, 50),
    Rect(200, 120, 150, 20),
    Rect(400, 200, 150, 20),
    Rect(600, 300, 150, 20)
};

std::vector<Coin> coins = {
    Coin(210, 135),
    Coin(420, 215),
    Coin(610, 315)
};

bool onGround() {
    for (const auto& p : platforms)
        if (player.y <= p.y + p.h && player.y >= p.y + p.h - 5 &&
            player.x + player.w > p.x && player.x < p.x + p.w)
            return true;
    return false;
}

GLuint loadTexture(const char* path) {
    int w, h, ch;
    unsigned char* data = stbi_load(path, &w, &h, &ch, 4);
    if (!data) { std::cout << "Image load failed\n"; exit(1); }
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    stbi_image_free(data);
    return tex;
}

void drawRect(const Rect& r, float R, float G, float B) {
    glColor3f(R, G, B);
    glBegin(GL_QUADS);
        glVertex2f(r.x, r.y);
        glVertex2f(r.x + r.w, r.y);
        glVertex2f(r.x + r.w, r.y + r.h);
        glVertex2f(r.x, r.y + r.h);
    glEnd();
}

void drawDan(const Rect& r) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, danTexture);
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(r.x, r.y);
        glTexCoord2f(1, 0); glVertex2f(r.x + r.w, r.y);
        glTexCoord2f(1, 1); glVertex2f(r.x + r.w, r.y + r.h);
        glTexCoord2f(0, 1); glVertex2f(r.x, r.y + r.h);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto& p : platforms)
        drawRect(p, 0.6f, 0.6f, 0.7f);
    drawDan(player);
    if (!gameOver) drawRect(enemy, 1.0f, 0.2f, 0.2f);
    for (auto& c : coins)
        if (!c.collected) drawRect(c.rect, 1.0f, 0.85f, 0.0f);

    if (gameOver || youWin) {
        glColor3f(1, 1, 1);
        const char* msg = youWin ? "YOU WIN!" : "GAME OVER!";
        glRasterPos2f(winW / 2 - 40, winH / 2);
        for (const char* c = msg; *c; ++c)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glutSwapBuffers();
}

void update(int) {
    if (gameOver || youWin) { glutPostRedisplay(); glutTimerFunc(16, update, 0); return; }
    velocityY -= gravity;
    player.y += velocityY;

    if (onGround()) {
        velocityY = 0;
        isJumping = false;
        for (const auto& p : platforms)
            if (player.y < p.y + p.h &&
                player.x + player.w > p.x && player.x < p.x + p.w)
                player.y = p.y + p.h;
    }

    if (player.y < 0) gameOver = true;
    enemy.x += enemyDirRight ? 2 : -2;
    if (enemy.x < 500 || enemy.x > 750) enemyDirRight = !enemyDirRight;
    if (player.collidesWith(enemy)) gameOver = true;

    for (auto& c : coins)
        if (!c.collected && player.collidesWith(c.rect))
            c.collected = true;

    bool allCollected = true;
    for (auto& c : coins)
        if (!c.collected) allCollected = false;
    if (allCollected && player.x > 750) youWin = true;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void key(unsigned char k, int, int) {
    if (gameOver || youWin) {
        if (k == 'r') {
            player.x = 50; player.y = 100; velocityY = 0; isJumping = false;
            enemy.x = 600; enemyDirRight = false;
            gameOver = false; youWin = false;
            for (auto& c : coins) c.collected = false;
        }
        return;
    }
    if (k == 'a') player.x -= 5;
    if (k == 'd') player.x += 5;
    if (k == 'w' && !isJumping) { isJumping = true; velocityY = 8; }
}

void reshape(int w, int h) {
    winW = w; winH = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(winW, winH);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Dan the Man - Platformer");

    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
    danTexture = loadTexture("dan.png");

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
