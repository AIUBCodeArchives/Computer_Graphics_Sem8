#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#define PI 3.14159265358979323846
#include<math.h>
using namespace std;

bool isDay = true;
bool nightMode = false;
bool monsoonMode = false;

GLfloat RainPos = 50.0f;

float busPosition = -15.0;
const float speed = 0.25;

float carPosition = 15.0;
const float carSpeed = -0.2;

bool animationsRunning = true;
bool boatsRunning = true;
float animationSpeedFactor = 1.0f;

GLfloat CloudPosition1 = 0.0f;
GLfloat CloudSpeed1 = 0.2f;

GLfloat BoatPositionX = 0.0f;
GLfloat BoatSpeed = 0.2f;
bool BoatMovingRight = true;

float BoatPositionX2 = 0.0f;
float BoatSpeed2 = 0.2f;
bool BoatMovingRight2 = false;

GLfloat WavePosition = 0.0f;
GLfloat WaveSpeed = 0.3f;

float AirshipPositionX = -10.0f;
float AirshipSpeed = 0.25f;

float PlanePositionX = 110.0f;
float PlaneSpeed = 0.5f;

bool planeMovingLeft = true;
bool airshipMovingRight = true;
bool busMovingRight = true;
bool carMovingRight = true;

void drawCircle(float cx, float cy, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * PI / 180.0f;
        glColor3ub(0, 0, 0);
        glVertex2f(cx + radius * cos(theta), cy + radius * sin(theta));
    }
    glEnd();
}

void CircleForCloud(GLfloat a, GLfloat b, GLfloat r){
    int i;
    int tringle1 = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(216, 220, 229);
    glVertex2f(a, b);
    for(i = 0; i <= tringle1; i++)
    {
        glVertex2f(
            a + (r * cos(i * twicePi / tringle1)),
            b + (r * sin(i * twicePi / tringle1))
        );
    }
    glEnd();
}

void CircleForMonsoonCloud(GLfloat a, GLfloat b, GLfloat r){
    int i;
    int tringle1 = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(99,102,106);
    glVertex2f(a, b); // Center point
    for(i = 0; i <= tringle1; i++)
    {
        glVertex2f(
            a + (r * cos(i * twicePi / tringle1)),
            b + (r * sin(i * twicePi / tringle1))
        );
    }
    glEnd();
}

void CircleForAirship(GLfloat a, GLfloat b, GLfloat r){
    int i;
    int tringle1 = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(111,38,61);
    glVertex2f(a, b);
    for(i = 0; i <= tringle1; i++)
    {
        glVertex2f(
            a + (r * cos(i * twicePi / tringle1)),
            b + (r * sin(i * twicePi / tringle1))
        );
    }
    glEnd();
}

void drawStar(float x, float y, float size) {
    glPointSize(size);
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(x, y);
    glEnd();
}

void Cloud1() {
    CircleForCloud(32.0f, 47.0f, 1.0f);
    CircleForCloud(33.0f, 47.5f, 1.0f);
    CircleForCloud(31.0f, 47.5f, 1.0f);
    CircleForCloud(32.0f, 48.0f, 1.0f);
}

void Cloud2() {
    CircleForCloud(25.0f, 47.0f, 2.0f);
    CircleForCloud(27.0f, 48.0f, 1.5f);
    CircleForCloud(24.5f, 48.0f, 1.5f);
    CircleForCloud(25.0f, 49.0f, 1.5f);
    CircleForCloud(26.5f, 46.0f, 1.5f);
}

void Cloud3() {
    CircleForCloud(8.0f, 48.0f, 2.0f);
    CircleForCloud(10.0f, 49.0f, 1.5f);
    CircleForCloud(6.5f, 49.0f, 1.5f);
    CircleForCloud(8.0f, 50.0f, 1.5f);
    CircleForCloud(10.0f, 47.0f, 1.5f);
}

void Cloud4() {
    CircleForCloud(15.0f, 41.0f, 2.5f);
    CircleForCloud(17.5f, 43.0f, 2.0f);
    CircleForCloud(12.5f, 43.0f, 2.0f);
    CircleForCloud(15.0f, 44.5f, 2.0f);
    CircleForCloud(17.5f, 40.0f, 2.0f);
}

void Cloud5() {
    CircleForCloud(27.0f, 45.0f, 1.0f);
    CircleForCloud(28.0f, 46.0f, 0.8f);
    CircleForCloud(26.0f, 46.0f, 0.8f);
    CircleForCloud(27.0f, 47.0f, 0.8f);
    CircleForCloud(28.0f, 44.0f, 0.8f);
}

void clouds() {
    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    Cloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    Cloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    Cloud3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    Cloud4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    Cloud5();
    glPopMatrix();
}

void waves()
{
    glLineWidth(1.6);
    glPushMatrix();
    glTranslatef(WavePosition, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2d(12, 18);
    glVertex2d(18, 18);

    glVertex2d(32, 18);
    glVertex2d(40, 18);

    glVertex2d(28, 16);
    glVertex2d(36, 16);

    glVertex2d(33, 12);
    glVertex2d(38, 12);

    glVertex2d(55, 10);
    glVertex2d(62, 10);

    glVertex2d(39, 8);
    glVertex2d(44, 8);

    glVertex2d(47, 6);
    glVertex2d(52, 6);

    glVertex2d(26, 2);
    glVertex2d(36, 2);

    glEnd();
    glPopMatrix();
}

void sky() {
    glBegin(GL_POLYGON);
    glColor3ub(164,219,232);
    glVertex2f(0.0, 50.0);
    glVertex2f(100.0, 50.0);
    glVertex2f(100.0, 25.0);
    glVertex2f(0.0, 25.0);
    glEnd();
}

void river()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 181, 226);
    glVertex2f(0.0, 20.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(100.0, 0.0);
    glVertex2f(100.0, 20.0);

    glEnd();
}

void Car() {
    glPushMatrix();
    glTranslatef(carPosition, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3ub(87, 45, 45);
    glVertex2f(94.0, 26.5);
    glVertex2f(93.5, 25.5);
    glVertex2f(97.0, 25.5);
    glVertex2f(96.5, 26.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(101, 28, 50);
    glVertex2f(92.5, 25.5);
    glVertex2f(92.5, 24.5);
    glVertex2f(98.0, 24.5);
    glVertex2f(98.0, 25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 240);
    glVertex2f(94.2, 26.3);
    glVertex2f(95, 26.3);
    glVertex2f(95, 25.7);
    glVertex2f(94, 25.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 240);
    glVertex2f(95.6, 26.3);
    glVertex2f(96.4, 26.3);
    glVertex2f(96.6, 25.7);
    glVertex2f(95.6, 25.7);
    glEnd();

    drawCircle(93.6f, 24.5f, 0.5f);
    drawCircle(97.0f, 24.5f, 0.5f);

    glPopMatrix();
}

void Bus() {
    glPushMatrix();
    glTranslatef(busPosition, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3ub(32, 42, 68);
    glVertex2f(5.0, 25.8);
    glVertex2f(5.2, 26.0);
    glVertex2f(13.5, 26.0);
    glVertex2f(13.6, 25.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 181);
    glVertex2f(5.0, 25.8);
    glVertex2f(5.0, 23.0);
    glVertex2f(13.8, 23.0);
    glVertex2f(13.8, 24.2);
    glVertex2f(13.6, 24.6);
    glVertex2f(13.6, 25.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 240);
    glVertex2f(5.2, 25.6);
    glVertex2f(6.2, 25.6);
    glVertex2f(6.2, 24.6);
    glVertex2f(5.2, 24.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 240);
    glVertex2f(7, 25.6);
    glVertex2f(8, 25.6);
    glVertex2f(8, 24.6);
    glVertex2f(7, 24.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 240);
    glVertex2f(8.8, 25.6);
    glVertex2f(9.8, 25.6);
    glVertex2f(9.8, 24.6);
    glVertex2f(8.8, 24.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 240);
    glVertex2f(10.6, 25.6);
    glVertex2f(11.6, 25.6);
    glVertex2f(11.6, 24.6);
    glVertex2f(10.6, 24.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 240);
    glVertex2f(12.4, 25.6);
    glVertex2f(13.4, 25.6);
    glVertex2f(13.4, 24.6);
    glVertex2f(12.4, 24.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75, 104, 184);
    glVertex2f(5.0, 24.6);
    glVertex2f(5.0, 24.2);
    glVertex2f(13.8, 24.2);
    glVertex2f(13.6, 24.6);
    glEnd();

    drawCircle(12.6f, 23.0f, 0.6f);
    drawCircle(6.5f, 23.0f, 0.6f);
    drawCircle(7.7f, 23.0f, 0.6f);

    glPopMatrix();
}

void boat1()
{
    glPushMatrix();
    glTranslatef(BoatPositionX, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(32,42,68);
    glVertex2f(10.0, 10.0);
    glVertex2f(12.8, 9.8);
    glVertex2f(12.9, 8.8);
    glVertex2f(10.6, 8.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(32,42,68);
    glVertex2f(12.8, 9.8);
    glVertex2f(12.8, 8.8);
    glVertex2f(15.2, 8.8);
    glVertex2f(16.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244,52,52);
    glVertex2f(10.24, 9.52);
    glVertex2f(10.2991, 9.40165);
    glVertex2f(12.8, 9.3);
    glVertex2f(12.8, 9.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244,52,52);
    glVertex2f(12.8, 9.4);
    glVertex2f(12.8, 9.3);
    glVertex2f(15.5, 9.4);
    glVertex2f(15.7, 9.52);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(10.4, 10.52);
    glVertex2f(10.56, 10.7);
    glVertex2f(10.4, 10.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(223,215,200);
    glVertex2f(10.4, 10.52);
    glVertex2f(10.56, 10.52);
    glVertex2f(10.56, 10.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(24,52,152);
    glVertex2f(10.32, 10.52);
    glVertex2f(10.4, 10.2);
    glVertex2f(10.65, 10.2);
    glVertex2f(10.76, 10.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(54,69,79);
    glVertex2f(10.3, 10.2);
    glVertex2f(10.7, 10.2);
    glVertex2f(11.076871, 9.92308);
    glVertex2f(10.4360, 9.96885);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81,68,61);
    glVertex2f(9.8, 8.8);
    glVertex2f(10.0, 8.8);
    glVertex2f(10.76, 10.52);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(144,84,47);
    glVertex2f(11.395419, 9.900327);
    glVertex2f(11.49949, 9.892893);
    glVertex2f(11.5, 10.6);
    glVertex2f(11.4, 10.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(144,84,47);
    glVertex2f(11.5, 10.6);
    glVertex2f(11.4, 10.6);
    glVertex2d(11.6, 10.8);
    glVertex2d(11.6, 10.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(144,84,47);
    glVertex2d(11.6, 10.8);
    glVertex2d(11.6, 10.7);
    glVertex2f(11.8, 10.7);
    glVertex2f(11.8, 10.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(144,84,47);
    glVertex2f(11.8, 10.7);
    glVertex2f(11.8, 10.8);
    glVertex2d(12.0, 10.6);
    glVertex2d(11.9, 10.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(144,84,47);
    glVertex2d(12.0, 10.6);
    glVertex2d(11.9, 10.6);
    glVertex2f(11.9023795699758, 9.8641871735732);
    glVertex2f(11.9998089215117, 9.8562537402234);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98,52,18);
    glVertex2f(11.49949, 9.892893);
    glVertex2d(11.5, 10.6);
    glVertex2d(11.6, 10.7);
    glVertex2d(11.8, 10.7);
    glVertex2d(11.9, 10.6);
    glVertex2f(11.9013795699758, 9.8641871735732);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81,68,61);
    glVertex2d(11.8, 10.8);
    glVertex2d(14.4, 10.8);
    glVertex2d(14.6, 10.6);
    glVertex2d(12.0, 10.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81,68,61);
    glVertex2d(12.0, 10.6);
    glVertex2d(14.6, 10.6);
    glVertex2d(14.6070518, 9.920740123);
    glVertex2f(12.85, 9.8);
    glVertex2f(11.9998089215117, 9.8562537402234);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(60,19,33);
    glVertex2d(12.8, 10.8);
    glVertex2d(13.0, 10.8);
    glVertex2d(13.0, 12.8);
    glVertex2d(12.8, 12.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(84,11,12);
    glVertex2d(12.2, 12.6);
    glVertex2d(12.4, 12.12);
    glVertex2d(14.4, 12.0);
    glVertex2d(14.2, 12.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(84,11,12);
    glVertex2d(12.4, 12.12);
    glVertex2d(12.0, 11.2);
    glVertex2d(14.2, 11.2);
    glVertex2d(14.4, 12.0);
    glEnd();

    glPopMatrix();
}

void boat2() {
    glPushMatrix();
    glTranslatef(BoatPositionX2 - 37.0f, 0.0f, 0.0f );

    glBegin(GL_POLYGON);
    glColor3ub(32, 42, 68);
    glVertex2f(42.8, 4.2);
    glVertex2f(46.2, 3.9);
    glVertex2f(46.2, 3.0);
    glVertex2f(43.6, 3.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(32, 42, 68);
    glVertex2f(46.2, 3.9);
    glVertex2f(46.2, 3.0);
    glVertex2f(48.5, 3.0);
    glVertex2f(49.6, 4.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244, 52, 52);
    glVertex2f(43.12, 3.72);
    glVertex2f(46.2, 3.6);
    glVertex2f(46.2, 3.5);
    glVertex2f(43.2, 3.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244, 52, 52);
    glVertex2f(46.2, 3.6);
    glVertex2f(46.2, 3.5);
    glVertex2f(49.05, 3.6);
    glVertex2f(49.1581212876, 3.7179504955);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 5);
    glVertex2f(49.0, 5.4);
    glVertex2f(49.2, 5.4);
    glVertex2f(49.2, 5.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(213, 163, 114);
    glVertex2f(49.0, 5.4);
    glVertex2f(49.0, 5.2);
    glVertex2f(49.2, 5.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72, 60, 50);
    glVertex2f(48.8, 5.2);
    glVertex2f(49.4, 5.2);
    glVertex2f(49.3, 4.8);
    glVertex2d(49.0, 4.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(119, 7, 55);
    glVertex2f(49.0, 4.8);
    glVertex2d(49.3, 4.8);
    glVertex2f(48.20804619, 4.07718054);
    glVertex2f(49.487168141, 4.19004424);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(48.8, 5.2);
    glVertex2d(49.2, 2.9);
    glVertex2f(49.5, 3.0);
    glEnd();

    glPopMatrix();
}

void boat3() {
    glPushMatrix();
    glTranslatef(BoatPositionX , 0.0f, 0.0f );

    glBegin(GL_POLYGON);
    glColor3ub(32, 42, 68);
    glVertex2f(7.2, 18.0);
    glVertex2f(6.2, 17.0);
    glVertex2f(4.0, 17.0);
    glVertex2f(4.0, 17.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(32, 42, 68);
    glVertex2f(1.0, 18.0);
    glVertex2f(2.0, 17.0);
    glVertex2f(4.0, 17.0);
    glVertex2f(4.0, 17.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244, 52, 52);
    glVertex2f(1.4, 17.6);
    glVertex2f(4.0, 17.5);
    glVertex2f(4.0, 17.3);
    glVertex2f(1.6, 17.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244, 52, 52);
    glVertex2f(4.0, 17.5);
    glVertex2f(4.0, 17.3);
    glVertex2f(6.6, 17.4);
    glVertex2f(6.8, 17.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 5);
    glVertex2f(1.4, 19.1);
    glVertex2f(1.4, 18.8);
    glVertex2f(1.8, 19.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(213, 163, 114);
    glVertex2f(1.8, 19.1);
    glVertex2f(1.8, 18.8);
    glVertex2f(1.4, 18.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72, 60, 50);
    glVertex2f(1.3, 18.8);
    glVertex2f(2.0, 18.8);
    glVertex2f(1.8, 18.4);
    glVertex2d(1.4, 18.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(119, 7, 55);
    glVertex2f(1.6, 18.4);
    glVertex2d(1.4, 18.4);
    glVertex2f(1.2, 18.0);
    glVertex2f(2.301, 17.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(2.2, 19.0);
    glVertex2d(1.2, 16.8);
    glVertex2f(0.6, 16.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(5.6, 18.8);
    glVertex2d(5.6, 18.6);
    glVertex2f(5.4, 18.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(213, 163, 114);
    glVertex2f(5.4, 18.8);
    glVertex2d(5.6, 18.6);
    glVertex2f(5.2, 18.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(65,117,113);
    glVertex2f(5.2, 18.6);
    glVertex2d(5.8, 18.6);
    glVertex2f(5.6, 18.0);
    glVertex2f(5.4, 18.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(124,131,188);
    glVertex2f(5.00033, 17.8625);
    glVertex2d(5.697599, 17.9060999);
    glVertex2f(5.4, 18.2);
    glEnd();

    glPopMatrix();
}

void land()
{
    glBegin(GL_POLYGON);
    glColor3ub(0,154,23);
    glVertex2f(0.0, 15.0);
    glVertex2f(10.0, 15.0);
    glVertex2f(12.0, 12.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70,58,50);
    glVertex2f(10.0, 15.0);
    glVertex2f(10.05, 15.0);
    glVertex2f(12.0, 12.02);
    glVertex2f(12.0, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70,58,50);
    glVertex2f(12.0, 12.0);
    glVertex2f(12.0, 11.8);
    glVertex2f(2.2, 0.0);
    glVertex2f(2.0, 0.0);
    glEnd();
}

void Hills() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 154, 23);
    glVertex2f(0.0, 36.0);
    glVertex2f(10.0, 25.0);
    glVertex2f(0.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113, 169, 44);
    glVertex2f(0.0, 25.0);
    glVertex2f(5.0, 35.0);
    glVertex2f(12.0, 32.0);
    glVertex2f(15.0, 25.0);
    glColor3ub(0, 135, 62);
    glVertex2f(10.0, 25.0);
    glVertex2f(17.0, 37.0);
    glVertex2f(32.0, 30.0);
    glVertex2f(32.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 154, 23);
    glVertex2f(20.0, 25.0);
    glVertex2f(32, 30.0);
    glVertex2f(40.0, 36.0);
    glVertex2f(50.0, 32.0);
    glVertex2f(54.0, 25.0);
    glColor3ub(0, 110, 51);
    glVertex2f(20.0, 25.0);
    glVertex2f(25.0, 35.0);
    glVertex2f(32.0, 32.0);
    glVertex2f(54.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113, 169, 44);
    glVertex2f(45.0, 25.0);
    glVertex2f(50.0, 35.0);
    glVertex2f(60.0, 25.0);
    glColor3ub(113, 169, 44);
    glVertex2f(65.0, 25.0);
    glVertex2f(70.0, 35.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 110, 51);
    glVertex2f(54.0, 25.0);
    glVertex2f(62.0, 36.0);
    glVertex2f(80.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 135, 62);
    glVertex2f(44.0, 25.0);
    glVertex2f(52.0, 30.0);
    glVertex2f(60.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 135, 62);
    glVertex2f(65.0, 25.0);
    glVertex2f(70.0, 35.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 25.0);
    glColor3ub(0, 110, 51);
    glVertex2f(72.0, 25.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 36.0);
    glVertex2f(88.0, 32.0);
    glVertex2f(93.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 135, 62);
    glVertex2f(93.0, 25.0);
    glVertex2f(100.0, 32.0);
    glVertex2f(100.0, 25.0);
    glColor3ub(113, 169, 44);
    glVertex2f(80.0, 25.0);
    glVertex2f(89.5, 36.0);
    glVertex2f(100.0, 25.0);
    glEnd();
}

void sun() {
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float theta = i * PI / 180.0f;
        glColor3ub(255, 255, 0);
        glVertex2f(60.0f + 5.0f * cos(theta), 44.0f + 5.0f * sin(theta));
    }
    glEnd();
}

void treesAndHouse()
{
    glBegin(GL_POLYGON);
    glColor3ub(21,71,52);
    glVertex2f(0.0, 17.0);
    glVertex2f(1.0, 15.0);
    glVertex2f(0.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(21,71,52);
    glVertex2f(0.0, 16.0);
    glVertex2f(1.0, 14.0);
    glVertex2f(0.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(101,56,24);
    glVertex2f(0.0, 14.0);
    glVertex2f(0.2, 14.0);
    glVertex2f(0.2, 10.0);
    glVertex2f(0.5, 9.5);
    glVertex2f(0.0, 9.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(119,75,58);
    glVertex2f(2.0, 15.5);
    glVertex2f(9.0, 15.5);
    glVertex2f(10.0, 13.5);
    glVertex2f(1.0, 13.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(195,176,144);
    glVertex2f(2.0, 13.5);
    glVertex2f(9.0, 13.5);
    glVertex2f(9.0, 11.0);
    glVertex2f(2.0, 11.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98,52,18);
    glVertex2f(10.0, 13.5);
    glVertex2f(9.0, 15.5);
    glVertex2f(10.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98,52,18);
    glVertex2f(9.0, 13.5);
    glVertex2f(9.5, 13.5);
    glVertex2f(9.5, 12.0);
    glVertex2f(9.0, 11.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,60,50);
    glVertex2f(2.0, 13.0);
    glVertex2f(9.0, 13.0);
    glVertex2f(9.0, 12.0);
    glVertex2f(2.0, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,60,50);
    glVertex2f(5.0, 12.0);
    glVertex2f(6.0, 12.0);
    glVertex2f(6.0, 11.0);
    glVertex2f(5.0, 11.0);
    glEnd();
}

void bridge()
{
    glBegin(GL_POLYGON);
    glColor3ub(217,217,214);
    glVertex2f(0.0, 22.0);
    glVertex2f(0.0, 20.0);
    glVertex2f(100.0, 20.0);
    glVertex2f(100.0, 22.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(26.0, 20.0);
    glVertex2d(24.0, 18.0);
    glVertex2d(22.0, 18.0);
    glVertex2d(20.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(24.0, 18.0);
    glVertex2d(24.0, 12.0);
    glVertex2d(22.0, 12.0);
    glVertex2d(22.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(24.0, 17.5);
    glVertex2d(24.0, 17.0);
    glVertex2d(22.0, 17.0);
    glVertex2d(22.0, 17.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(21.5, 14.0);
    glVertex2d(24.5, 14.0);
    glVertex2d(24.5, 12.0);
    glVertex2d(21.5, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(50.0, 20.0);
    glVertex2d(48.0, 18.0);
    glVertex2d(46.0, 18.0);
    glVertex2d(44.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(48.0, 18.0);
    glVertex2d(48.0, 12.0);
    glVertex2d(46.0, 12.0);
    glVertex2d(46.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(48.0, 17.5);
    glVertex2d(48.0, 17.0);
    glVertex2d(46.0, 17.0);
    glVertex2d(46.0, 17.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(45.5, 14.0);
    glVertex2d(48.5, 14.0);
    glVertex2d(48.5, 12.0);
    glVertex2d(45.5, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(74.0, 20.0);
    glVertex2d(72.0, 18.0);
    glVertex2d(70.0, 18.0);
    glVertex2d(68.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(72.0, 18.0);
    glVertex2d(72.0, 12.0);
    glVertex2d(70.0, 12.0);
    glVertex2d(70.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(72.0, 17.5);
    glVertex2d(72.0, 17.0);
    glVertex2d(70.0, 17.0);
    glVertex2d(70.0, 17.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(69.5, 14.0);
    glVertex2d(72.5, 14.0);
    glVertex2d(72.5, 12.0);
    glVertex2d(69.5, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(96.0, 20.0);
    glVertex2d(94.0, 18.0);
    glVertex2d(92.0, 18.0);
    glVertex2d(90.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 214);
    glVertex2f(94.0, 18.0);
    glVertex2d(94.0, 12.0);
    glVertex2d(92.0, 12.0);
    glVertex2d(92.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(94.0, 17.5);
    glVertex2d(94.0, 17.0);
    glVertex2d(92.0, 17.0);
    glVertex2d(92.0, 17.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96,98,99);
    glVertex2f(91.5, 14.0);
    glVertex2d(94.5, 14.0);
    glVertex2d(94.5, 12.0);
    glVertex2d(91.5, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(31,32,34);
    glVertex2f(0.0, 22.0);
    glVertex2f(0.0, 25.0);
    glVertex2f(100.0, 25.0);
    glVertex2f(100.0, 22.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(5.0, 23.8);
    glVertex2f(5.0, 23.6);
    glVertex2f(9.8, 23.6);
    glVertex2f(9.8, 23.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(16.0, 23.8);
    glVertex2f(16.0, 23.6);
    glVertex2f(19.8, 23.6);
    glVertex2f(19.8, 23.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(27.0, 23.8);
    glVertex2f(27.0, 23.6);
    glVertex2f(30.8, 23.6);
    glVertex2f(30.8, 23.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(40.0, 23.8);
    glVertex2f(40.0, 23.6);
    glVertex2f(45.8, 23.6);
    glVertex2f(45.8, 23.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(55.0, 23.8);
    glVertex2f(55.0, 23.6);
    glVertex2f(59.8, 23.6);
    glVertex2f(59.8, 23.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(70.0, 23.8);
    glVertex2f(70.0, 23.6);
    glVertex2f(75.8, 23.6);
    glVertex2f(75.8, 23.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(84.0, 23.8);
    glVertex2f(84.0, 23.6);
    glVertex2f(89.8, 23.6);
    glVertex2f(89.8, 23.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(97.0, 23.8);
    glVertex2f(97.0, 23.6);
    glVertex2f(100.8, 23.6);
    glVertex2f(100.8, 23.8);
    glEnd();
}

void backBridgeTower()
{
    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(-2.0, 25.0);
    glVertex2f(-1.5, 25.0);
    glVertex2f(10.0, 34.5);
    glVertex2f(10.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(10.0, 35.0);
    glVertex2f(10.0, 34.5);
    glVertex2f(22.5, 25.0);
    glVertex2f(23.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(23.0, 25.0);
    glVertex2f(23.5, 25.0);
    glVertex2f(36.0, 34.5);
    glVertex2f(36.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(36.0, 35.0);
    glVertex2f(36.0, 34.5);
    glVertex2f(47.5, 25.0);
    glVertex2f(48.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(48.0, 25.0);
    glVertex2f(48.5, 25.0);
    glVertex2f(60.0, 34.5);
    glVertex2f(60.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(60.0, 35.0);
    glVertex2f(60.0, 34.5);
    glVertex2f(72.5, 25.0);
    glVertex2f(73.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(73.0, 25.0);
    glVertex2f(73.5, 25.0);
    glVertex2f(86.0, 34.5);
    glVertex2f(86.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(86.0, 35.0);
    glVertex2f(86.0, 34.5);
    glVertex2f(97.5, 25.0);
    glVertex2f(98.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(98.0, 25.0);
    glVertex2f(98.5, 25.0);
    glVertex2f(111.0, 34.5);
    glVertex2f(111.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(111.0, 35.0);
    glVertex2f(111.0, 34.5);
    glVertex2f(122.5, 25.0);
    glVertex2f(123.0, 25.0);
    glEnd();

    glLineWidth(1.6);
    glBegin(GL_LINES);
    glColor3f(140.0f / 255.0f, 146.0f / 255.0f, 172.0f / 255.0f);

    glVertex2d(-0.5, 25.0);
    glVertex2d(-0.516, 25.8134);

    glVertex2d(0.9924, 27.0714);
    glVertex2d(1.0, 25.0);

    glVertex2d(3.978, 29.5258);
    glVertex2d(4.0, 25.0);

    glVertex2d(6.989, 32.012);
    glVertex2d(7.0, 25.0);

    glVertex2d(10.0, 34.5);
    glVertex2d(10.0, 25.0);

    glVertex2d(13.029, 32.19);
    glVertex2d(13.0, 25.0);

    glVertex2d(15.97, 29.96);
    glVertex2d(16.0, 25.0);

    glVertex2d(19.02, 27.66);
    glVertex2d(19.0, 25.0);

    glVertex2d(21.016, 26.12);
    glVertex2d(21.0, 25.0);

    glVertex2d(25.022, 26.15);
    glVertex2d(25.0, 25.0);

    glVertex2d(26.98, 27.64);
    glVertex2d(27.0, 25.0);

    glVertex2d(30.0, 29.64);
    glVertex2d(30.0, 25.0);

    glVertex2d(33.016, 32.24);
    glVertex2d(33.0, 25.0);

    glVertex2d(36.0, 34.31);
    glVertex2d(36.0, 25.0);

    glVertex2d(39.0106, 32.0064);
    glVertex2d(39.0, 25.0);

    glVertex2d(42.015, 29.54);
    glVertex2d(42.0, 25.0);

    glVertex2d(45.03, 27.064);
    glVertex2d(45.0, 25.0);

    glVertex2d(50.967, 27.064);
    glVertex2d(51.0, 25.0);

    glVertex2d(54.0967, 29.54);
    glVertex2d(54.0, 25.0);

    glVertex2d(56.967, 32.064);
    glVertex2d(57.0, 25.0);

    glVertex2d(60.0, 34.5);
    glVertex2d(60.0, 25.0);

    glVertex2d(62.97, 32.23);
    glVertex2d(63.0, 25.0);

    glVertex2d(65.97, 29.9);
    glVertex2d(66.0, 25.0);

    glVertex2d(68.99, 27.66);
    glVertex2d(69.0, 25.0);

    glVertex2d(77.0, 27.688);
    glVertex2d(77.0, 25.0);

    glVertex2d(79.96, 29.96);
    glVertex2d(80.0, 25.0);

    glVertex2d(83.096, 32.36);
    glVertex2d(83.0, 25.0);

    glVertex2d(86.0, 34.6);
    glVertex2d(86.0, 25.0);

    glVertex2d(88.96, 32.113);
    glVertex2d(89.0, 25.0);

    glVertex2d(91.999, 29.66);
    glVertex2d(92.0, 25.0);

    glVertex2d(95.0096, 27.096);
    glVertex2d(95.0, 25.0);
    glEnd();
}

void frontBridgeTower()
{
    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(0.0, 22.0);
    glVertex2f(0.5, 22.0);
    glVertex2f(12.0, 31.5);
    glVertex2f(12.0, 32.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(12.0, 32.0);
    glVertex2f(12.0, 31.5);
    glVertex2f(24.5, 22.0);
    glVertex2f(25.0, 22.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(25.0, 22.0);
    glVertex2f(25.5, 22.0);
    glVertex2f(38.0, 31.5);
    glVertex2f(38.0, 32.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(38.0, 32.0);
    glVertex2f(38.0, 31.5);
    glVertex2f(49.5, 22.0);
    glVertex2f(50.0, 22.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(50.0, 22.0);
    glVertex2f(50.5, 22.0);
    glVertex2f(62.0, 31.5);
    glVertex2f(62.0, 32.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(62.0, 32.0);
    glVertex2f(62.0, 31.5);
    glVertex2f(74.5, 22.0);
    glVertex2f(75.0, 22.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(75.0, 22.0);
    glVertex2f(75.5, 22.0);
    glVertex2f(88.0, 31.5);
    glVertex2f(88.0, 32.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(75,54,95);
    glVertex2f(88.0, 32.0);
    glVertex2f(88.0, 31.5);
    glVertex2f(99.5, 22.0);
    glVertex2f(100.0, 22.0);
    glEnd();

    glLineWidth(1.6);
    glBegin(GL_LINES);
    glColor3f(140.0f / 255.0f, 146.0f / 255.0f, 172.0f / 255.0f);

    glVertex2d(1.5, 22.0);
    glVertex2d(1.484, 22.8134);

    glVertex2d(3.0076, 24.0714);
    glVertex2d(3.0, 22.0);

    glVertex2d(5.978, 26.5258);
    glVertex2d(6.0, 22.0);

    glVertex2d(8.989, 29.012);
    glVertex2d(9.0, 22.0);

    glVertex2d(12.0, 31.5);
    glVertex2d(12.0, 22.0);

    glVertex2d(15.029, 29.19);
    glVertex2d(15.0, 22.0);

    glVertex2d(17.97, 26.96);
    glVertex2d(18.0, 22.0);

    glVertex2d(21.02, 24.66);
    glVertex2d(21.0, 22.0);

    glVertex2d(23.016, 23.12);
    glVertex2d(23.0, 22.0);

    glVertex2d(27.022, 23.15);
    glVertex2d(27.0, 22.0);

    glVertex2d(28.98, 24.64);
    glVertex2d(29.0, 22.0);

    glVertex2d(32.0, 26.64);
    glVertex2d(32.0, 22.0);

    glVertex2d(35.016, 29.24);
    glVertex2d(35.0, 22.0);

    glVertex2d(38.0, 31.31);
    glVertex2d(38.0, 22.0);

    glVertex2d(41.0106, 29.0064);
    glVertex2d(41.0, 22.0);

    glVertex2d(44.015, 26.54);
    glVertex2d(44.0, 22.0);

    glVertex2d(47.03, 24.064);
    glVertex2d(47.0, 22.0);

    glVertex2d(52.967, 24.064);
    glVertex2d(53.0, 22.0);

    glVertex2d(56.0967, 26.54);
    glVertex2d(56.0, 22.0);

    glVertex2d(58.967, 29.064);
    glVertex2d(59.0, 22.0);

    glVertex2d(62.0, 31.5);
    glVertex2d(62.0, 22.0);

    glVertex2d(64.97, 29.23);
    glVertex2d(65.0, 22.0);

    glVertex2d(67.97, 26.9);
    glVertex2d(68.0, 22.0);

    glVertex2d(70.99, 24.66);
    glVertex2d(71.0, 22.0);

    glVertex2d(79.0, 24.688);
    glVertex2d(79.0, 22.0);

    glVertex2d(81.96, 26.96);
    glVertex2d(82.0, 22.0);

    glVertex2d(85.096, 29.36);
    glVertex2d(85.0, 22.0);

    glVertex2d(88.0, 31.6);
    glVertex2d(88.0, 22.0);

    glVertex2d(90.96, 29.113);
    glVertex2d(91.0, 22.0);

    glVertex2d(93.999, 26.66);
    glVertex2d(94.0, 22.0);

    glVertex2d(97.0096, 24.096);
    glVertex2d(97.0, 22.0);
    glEnd();

}

void plain() {
    glPushMatrix();
    glTranslatef(PlanePositionX -76.f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(137, 142, 140);
    glVertex2f(78.0f, 45.5f);
    glVertex2f(91.0f, 45.5f);
    glVertex2f(91.0f, 45.0f);
    glVertex2f(90.0f, 44.0f);
    glVertex2f(78.0f, 44.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(54, 69, 79);
    glVertex2f(78.0f, 45.5f);
    glVertex2f(78.0f, 44.0f);
    glVertex2f(77.6f, 44.2f);
    glVertex2f(77.6f, 45.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(219, 226, 233);
    glVertex2f(81.4f, 44.8f);
    glVertex2f(84.0f, 44.8f);
    glVertex2f(91.0f, 43.5f);
    glVertex2f(90.0f, 43.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 46, 82);
    glVertex2f(78.0f, 45.2f);
    glVertex2f(78.0f, 44.8f);
    glVertex2f(89.463f, 44.896f);
    glVertex2f(89.2f, 45.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 46, 82);
    glVertex2f(90.0f, 47.0f);
    glVertex2f(91.0f, 47.0f);
    glVertex2f(91.0f, 45.0f);
    glVertex2f(90.0f, 44.0f);
    glVertex2f(89.0f, 45.5f);
    glEnd();

    glPopMatrix();
}


void airship() {
    glLineWidth(1.6);

    glPushMatrix();
    glTranslatef(AirshipPositionX, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(2.5, 38.0);
    glVertex2f(2.2, 38.6);

    glVertex2f(3.0, 38.0);
    glVertex2f(3.0, 38.4);

    glVertex2f(3.8, 38.6);
    glVertex2f(3.5, 38.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100, 71, 65);
    glVertex2f(2.0, 38.0);
    glVertex2f(4.0, 38.0);
    glVertex2f(4.0, 36.0);
    glVertex2f(2.0, 36.0);
    glEnd();

    CircleForAirship(3.0f, 40.5f, 2.062f);

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(7.2, 37.0);
    glVertex2f(6.9984, 37.77);

    glVertex2f(7.997, 37.5);
    glVertex2f(8.0, 37.0);

    glVertex2f(8.8, 37.0);
    glVertex2f(8.89676, 37.7118);
    glEnd();

    CircleForAirship(8.0f, 39.5f, 2.0f);

    glBegin(GL_POLYGON);
    glColor3ub(100, 71, 65);
    glVertex2f(7.2, 37.0);
    glVertex2f(9.0, 37.0);
    glVertex2f(9.0, 35.5);
    glVertex2f(7.0, 35.5);
    glEnd();

    glPopMatrix();
}

void nightSky() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 51);
    glVertex2f(0.0, 50.0);
    glVertex2f(0.0, 20.0);
    glVertex2f(100.0, 20.0);
    glVertex2f(100.0, 50.0);
    glEnd();

    drawStar(10.0, 45.0, 3.0);
    drawStar(20.0, 40.0, 3.0);
    drawStar(30.0, 47.0, 3.0);
    drawStar(50.0, 43.0, 3.0);
    drawStar(70.0, 45.0, 3.0);
    drawStar(80.0, 42.0, 3.0);
    drawStar(90.0, 46.0, 3.0);

    drawStar(15.0, 35.0, 3.0);
    drawStar(25.0, 38.0, 3.0);
    drawStar(35.0, 36.0, 3.0);
    drawStar(45.0, 39.0, 3.0);
    drawStar(55.0, 34.0, 3.0);
    drawStar(65.0, 37.0, 3.0);
    drawStar(75.0, 35.0, 3.0);
    drawStar(85.0, 38.0, 3.0);
    drawStar(95.0, 36.0, 3.0);

    drawStar(12.0, 48.0, 3.0);
    drawStar(22.0, 43.0, 3.0);
    drawStar(32.0, 46.0, 3.0);
    drawStar(42.0, 44.0, 3.0);
    drawStar(52.0, 47.0, 3.0);
    drawStar(62.0, 45.0, 3.0);
    drawStar(72.0, 48.0, 3.0);
    drawStar(82.0, 46.0, 3.0);
    drawStar(92.0, 44.0, 3.0);

    drawStar(5.0, 32.0, 3.0);
    drawStar(15.0, 34.0, 3.0);
    drawStar(25.0, 30.0, 3.0);
    drawStar(35.0, 33.0, 3.0);
    drawStar(45.0, 31.0, 3.0);
    drawStar(55.0, 34.0, 3.0);
    drawStar(65.0, 32.0, 3.0);
    drawStar(75.0, 33.0, 3.0);
    drawStar(85.0, 30.0, 3.0);
    drawStar(95.0, 32.0, 3.0);

    drawStar(8.0, 28.0, 3.0);
    drawStar(18.0, 27.0, 3.0);
    drawStar(28.0, 26.0, 3.0);
    drawStar(38.0, 29.0, 3.0);
    drawStar(48.0, 25.0, 3.0);
    drawStar(58.0, 28.0, 3.0);
    drawStar(68.0, 27.0, 3.0);
    drawStar(78.0, 29.0, 3.0);
    drawStar(88.0, 26.0, 3.0);
    drawStar(98.0, 28.0, 3.0);
}

void moon() {
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 179);
    for (int i = 0; i < 360; i++) {
        float theta = i * PI / 180.0f;
        glVertex2f(80.0f + 5.0f * cos(theta), 44.0f + 5.0f * sin(theta));
    }
    glEnd();
}

void night_land()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(0.0, 15.0);
    glVertex2f(10.0, 15.0);
    glVertex2f(12.0, 12.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70,58,50);
    glVertex2f(10.0, 15.0);
    glVertex2f(10.05, 15.0);
    glVertex2f(12.0, 12.02);
    glVertex2f(12.0, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70,58,50);
    glVertex2f(12.0, 12.0);
    glVertex2f(12.0, 11.8);
    glVertex2f(2.2, 0.0);
    glVertex2f(2.0, 0.0);
    glEnd();
}

void night_Hills() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(0.0, 36.0);
    glVertex2f(10.0, 25.0);
    glVertex2f(0.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(50, 90, 10);
    glVertex2f(0.0, 25.0);
    glVertex2f(5.0, 35.0);
    glVertex2f(12.0, 32.0);
    glVertex2f(15.0, 25.0);
    glColor3ub(0, 80, 0);
    glVertex2f(10.0, 25.0);
    glVertex2f(17.0, 37.0);
    glVertex2f(32.0, 30.0);
    glVertex2f(32.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(20.0, 25.0);
    glVertex2f(32, 30.0);
    glVertex2f(40.0, 36.0);
    glVertex2f(50.0, 32.0);
    glVertex2f(54.0, 25.0);
    glColor3ub(0, 80, 0);
    glVertex2f(20.0, 25.0);
    glVertex2f(25.0, 35.0);
    glVertex2f(32.0, 32.0);
    glVertex2f(54.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(50, 90, 10);
    glVertex2f(45.0, 25.0);
    glVertex2f(50.0, 35.0);
    glVertex2f(60.0, 25.0);
    glColor3ub(50, 90, 10);
    glVertex2f(65.0, 25.0);
    glVertex2f(70.0, 35.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(54.0, 25.0);
    glVertex2f(62.0, 36.0);
    glVertex2f(80.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(44.0, 25.0);
    glVertex2f(52.0, 30.0);
    glVertex2f(60.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(65.0, 25.0);
    glVertex2f(70.0, 35.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 25.0);
    glColor3ub(50, 90, 10);
    glVertex2f(72.0, 25.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 36.0);
    glVertex2f(88.0, 32.0);
    glVertex2f(93.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(93.0, 25.0);
    glVertex2f(100.0, 32.0);
    glVertex2f(100.0, 25.0);
    glColor3ub(50, 90, 10);
    glVertex2f(80.0, 25.0);
    glVertex2f(89.5, 36.0);
    glVertex2f(100.0, 25.0);
    glEnd();
}

void night_treesAndHouse()
{
    glBegin(GL_POLYGON);
    glColor3ub(21,71,52);
    glVertex2f(0.0, 17.0);
    glVertex2f(1.0, 15.0);
    glVertex2f(0.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(21,71,52);
    glVertex2f(0.0, 16.0);
    glVertex2f(1.0, 14.0);
    glVertex2f(0.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(101,56,24);
    glVertex2f(0.0, 14.0);
    glVertex2f(0.2, 14.0);
    glVertex2f(0.2, 10.0);
    glVertex2f(0.5, 9.5);
    glVertex2f(0.0, 9.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(119,75,58);
    glVertex2f(2.0, 15.5);
    glVertex2f(9.0, 15.5);
    glVertex2f(10.0, 13.5);
    glVertex2f(1.0, 13.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(195,176,144);
    glVertex2f(2.0, 13.5);
    glVertex2f(9.0, 13.5);
    glVertex2f(9.0, 11.0);
    glVertex2f(2.0, 11.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98,52,18);
    glVertex2f(10.0, 13.5);
    glVertex2f(9.0, 15.5);
    glVertex2f(10.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98,52,18);
    glVertex2f(9.0, 13.5);
    glVertex2f(9.5, 13.5);
    glVertex2f(9.5, 12.0);
    glVertex2f(9.0, 11.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,60,50);
    glVertex2f(2.0, 13.0);
    glVertex2f(9.0, 13.0);
    glVertex2f(9.0, 12.0);
    glVertex2f(2.0, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,60,50);
    glVertex2f(5.0, 12.0);
    glVertex2f(6.0, 12.0);
    glVertex2f(6.0, 11.0);
    glVertex2f(5.0, 11.0);
    glEnd();
}

void nightRiver() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 102);
    glVertex2f(0.0, 20.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(100.0, 0.0);
    glVertex2f(100.0, 20.0);
    glEnd();
}

void MonsoonCloud1() {
    CircleForMonsoonCloud(32.0f, 47.0f, 1.0f);
    CircleForMonsoonCloud(33.0f, 47.5f, 1.0f);
    CircleForMonsoonCloud(31.0f, 47.5f, 1.0f);
    CircleForMonsoonCloud(32.0f, 48.0f, 1.0f);
}

void MonsoonCloud2() {
    CircleForMonsoonCloud(25.0f, 47.0f, 2.0f);
    CircleForMonsoonCloud(27.0f, 48.0f, 1.5f);
    CircleForMonsoonCloud(24.5f, 48.0f, 1.5f);
    CircleForMonsoonCloud(25.0f, 49.0f, 1.5f);
    CircleForMonsoonCloud(26.5f, 46.0f, 1.5f);
}

void MonsoonCloud3() {
    CircleForMonsoonCloud(8.0f, 48.0f, 2.0f);
    CircleForMonsoonCloud(10.0f, 49.0f, 1.5f);
    CircleForMonsoonCloud(6.5f, 49.0f, 1.5f);
    CircleForMonsoonCloud(8.0f, 50.0f, 1.5f);
    CircleForMonsoonCloud(10.0f, 47.0f, 1.5f);
}

void MonsoonCloud4() {
    CircleForMonsoonCloud(15.0f, 41.0f, 2.5f);
    CircleForMonsoonCloud(17.5f, 43.0f, 2.0f);
    CircleForMonsoonCloud(12.5f, 43.0f, 2.0f);
    CircleForMonsoonCloud(15.0f, 44.5f, 2.0f);
    CircleForMonsoonCloud(17.5f, 40.0f, 2.0f);
}

void MonsoonCloud5() {
    CircleForMonsoonCloud(27.0f, 45.0f, 1.0f);
    CircleForMonsoonCloud(28.0f, 46.0f, 0.8f);
    CircleForMonsoonCloud(26.0f, 46.0f, 0.8f);
    CircleForMonsoonCloud(27.0f, 47.0f, 0.8f);
    CircleForMonsoonCloud(28.0f, 44.0f, 0.8f);
}

void monsoonClouds() {
    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    MonsoonCloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    MonsoonCloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    MonsoonCloud3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    MonsoonCloud4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(CloudPosition1, 0.0f, 0.0f);
    MonsoonCloud5();
    glPopMatrix();
}

void monsoonSky() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 51);
    glVertex2f(0.0, 50.0);
    glVertex2f(56.0, 50.0);
    glVertex2f(45.0, 25.0);
    glVertex2f(0.0, 25.0);

    glBegin(GL_POLYGON);
    glColor3ub(0,51,153);
    glVertex2f(56.0, 50.0);
    glVertex2f(45.0, 25.0);
    glVertex2f(100.0, 25.0);
    glVertex2f(100.0, 50.0);

    glBegin(GL_POLYGON);
    glColor3ub(15,82,186);
    glVertex2f(0.0, 50.0);
    glVertex2f(0.0, 25.0);
    glVertex2f(100.0, 25.0);
    glVertex2f(100.0, 50.0);
    glEnd();
}

void monsoon_land()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(0.0, 15.0);
    glVertex2f(10.0, 15.0);
    glVertex2f(12.0, 12.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70,58,50);
    glVertex2f(10.0, 15.0);
    glVertex2f(10.05, 15.0);
    glVertex2f(12.0, 12.02);
    glVertex2f(12.0, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70,58,50);
    glVertex2f(12.0, 12.0);
    glVertex2f(12.0, 11.8);
    glVertex2f(2.2, 0.0);
    glVertex2f(2.0, 0.0);
    glEnd();
}

void monsoon_Hills() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(0.0, 36.0);
    glVertex2f(10.0, 25.0);
    glVertex2f(0.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(50, 90, 10);
    glVertex2f(0.0, 25.0);
    glVertex2f(5.0, 35.0);
    glVertex2f(12.0, 32.0);
    glVertex2f(15.0, 25.0);
    glColor3ub(0, 80, 0);
    glVertex2f(10.0, 25.0);
    glVertex2f(17.0, 37.0);
    glVertex2f(32.0, 30.0);
    glVertex2f(32.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(20.0, 25.0);
    glVertex2f(32, 30.0);
    glVertex2f(40.0, 36.0);
    glVertex2f(50.0, 32.0);
    glVertex2f(54.0, 25.0);
    glColor3ub(0, 80, 0);
    glVertex2f(20.0, 25.0);
    glVertex2f(25.0, 35.0);
    glVertex2f(32.0, 32.0);
    glVertex2f(54.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(50, 90, 10);
    glVertex2f(45.0, 25.0);
    glVertex2f(50.0, 35.0);
    glVertex2f(60.0, 25.0);
    glColor3ub(50, 90, 10);
    glVertex2f(65.0, 25.0);
    glVertex2f(70.0, 35.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(54.0, 25.0);
    glVertex2f(62.0, 36.0);
    glVertex2f(80.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(44.0, 25.0);
    glVertex2f(52.0, 30.0);
    glVertex2f(60.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(65.0, 25.0);
    glVertex2f(70.0, 35.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 25.0);
    glColor3ub(50, 90, 10);
    glVertex2f(72.0, 25.0);
    glVertex2f(76.0, 32.0);
    glVertex2f(80.0, 36.0);
    glVertex2f(88.0, 32.0);
    glVertex2f(93.0, 25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 80, 0);
    glVertex2f(93.0, 25.0);
    glVertex2f(100.0, 32.0);
    glVertex2f(100.0, 25.0);
    glColor3ub(50, 90, 10);
    glVertex2f(80.0, 25.0);
    glVertex2f(89.5, 36.0);
    glVertex2f(100.0, 25.0);
    glEnd();
}

void monsoon_treesAndHouse()
{
    glBegin(GL_POLYGON);
    glColor3ub(21,71,52);
    glVertex2f(0.0, 17.0);
    glVertex2f(1.0, 15.0);
    glVertex2f(0.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(21,71,52);
    glVertex2f(0.0, 16.0);
    glVertex2f(1.0, 14.0);
    glVertex2f(0.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(101,56,24);
    glVertex2f(0.0, 14.0);
    glVertex2f(0.2, 14.0);
    glVertex2f(0.2, 10.0);
    glVertex2f(0.5, 9.5);
    glVertex2f(0.0, 9.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(119,75,58);
    glVertex2f(2.0, 15.5);
    glVertex2f(9.0, 15.5);
    glVertex2f(10.0, 13.5);
    glVertex2f(1.0, 13.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(195,176,144);
    glVertex2f(2.0, 13.5);
    glVertex2f(9.0, 13.5);
    glVertex2f(9.0, 11.0);
    glVertex2f(2.0, 11.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98,52,18);
    glVertex2f(10.0, 13.5);
    glVertex2f(9.0, 15.5);
    glVertex2f(10.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98,52,18);
    glVertex2f(9.0, 13.5);
    glVertex2f(9.5, 13.5);
    glVertex2f(9.5, 12.0);
    glVertex2f(9.0, 11.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,60,50);
    glVertex2f(2.0, 13.0);
    glVertex2f(9.0, 13.0);
    glVertex2f(9.0, 12.0);
    glVertex2f(2.0, 12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(72,60,50);
    glVertex2f(5.0, 12.0);
    glVertex2f(6.0, 12.0);
    glVertex2f(6.0, 11.0);
    glVertex2f(5.0, 11.0);
    glEnd();
}

void monsoontRiver() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 102);
    glVertex2f(0.0, 20.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(68.0, 0.0);
    glVertex2f(62.0, 8.0);
    glVertex2f(62.0, 20.0);

    glBegin(GL_POLYGON);
    glColor3ub(15,82,186);
    glVertex2f(100.0, 20.0);
    glVertex2f(100.0, 0.0);

    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 20.0);
    glEnd();
}

void Rain(GLfloat a, GLfloat b) {
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(0, 94, 184);
    glVertex2f(a, b);
    glVertex2f(a - 0.2, b - 0.5);
    glEnd();
}
void CloudAnimation1(int value) {
    if (animationsRunning) {
        CloudPosition1 += CloudSpeed1 * animationSpeedFactor;
        if (CloudPosition1 > 100) {
            CloudPosition1 = -30.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(40 / animationSpeedFactor, CloudAnimation1, 0);
}

void BoatAnimation(int value) {
    if (animationsRunning && boatsRunning) {
        if (BoatMovingRight) {
            BoatPositionX += BoatSpeed * animationSpeedFactor;
            if (BoatPositionX > 100.0f) {
                BoatMovingRight = false;
            }
        } else {
            BoatPositionX -= BoatSpeed * animationSpeedFactor;
            if (BoatPositionX < 0.0f) {
                BoatMovingRight = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(40 / animationSpeedFactor, BoatAnimation, 0);
}

void BoatAnimation2(int value) {
    if (animationsRunning && boatsRunning) {
        if (BoatMovingRight2) {
            BoatPositionX2 += BoatSpeed2 * animationSpeedFactor;
            if (BoatPositionX2 > 100.0f) {
                BoatMovingRight2 = false;
            }
        } else {
            BoatPositionX2 -= BoatSpeed2 * animationSpeedFactor;
            if (BoatPositionX2 < 0.0f) {
                BoatMovingRight2 = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(40 / animationSpeedFactor, BoatAnimation2, 0);
}

void WaveAnimation(int value) {
    WavePosition += WaveSpeed;
    if (WavePosition > 100) {
        WavePosition = -30.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(40, WaveAnimation, 0);
}


void PlaneAnimation(int value) {
    if (animationsRunning) {
        if (planeMovingLeft) {
            PlanePositionX -= PlaneSpeed * animationSpeedFactor;
            if (PlanePositionX < -10.0f) {
                PlanePositionX = 110.0f;
            }
        } else {
            PlanePositionX += PlaneSpeed * animationSpeedFactor;
            if (PlanePositionX > 110.0f) {
                PlanePositionX = -10.0f;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(40 / animationSpeedFactor, PlaneAnimation, 0);
}

void AirshipAnimation(int value) {
    if (animationsRunning) {
        if (airshipMovingRight) {
            AirshipPositionX += AirshipSpeed * animationSpeedFactor;
            if (AirshipPositionX > 110.0f) {
                AirshipPositionX = -10.0f;
            }
        } else {
            AirshipPositionX -= AirshipSpeed * animationSpeedFactor;
            if (AirshipPositionX < -10.0f) {
                AirshipPositionX = 110.0f;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(40 / animationSpeedFactor, AirshipAnimation, 0);
}

void updateBus(int value) {
    if (animationsRunning) {
        if (busMovingRight) {
            busPosition += speed * animationSpeedFactor;
            if (busPosition > 100.0) {
                busPosition = -15.0;
            }
        } else {
            busPosition -= speed * animationSpeedFactor;
            if (busPosition < -15.0) {
                busPosition = 100.0;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16 / animationSpeedFactor, updateBus, 0);
}

void updateCar(int value) {
    if (animationsRunning) {
        if (carMovingRight) {
            carPosition += carSpeed * animationSpeedFactor;
            if (carPosition > 100.0) {
                carPosition = -15.0;
            }
        } else {
            carPosition -= carSpeed * animationSpeedFactor;
            if (carPosition < -15.0) {
                carPosition = 100.0;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16 / animationSpeedFactor, updateCar, 0);
}

void RainFall() {
    float X, Y;
    for (Y = 50.0f; Y >= 0.0f; Y -= 1.0f) {
        for (X = 0.0f; X <= 100.0f; X += 2.0f) {
            Rain(X, RainPos);
        }
        RainPos -= 1.0f;
    }
}

void RainAnimation(int value) {
    glutTimerFunc(150, RainAnimation, 0);
    if (monsoonMode) {
        RainPos = 50.0f;
    }
    glutPostRedisplay();
}

void nightScene() {
    nightRiver();
    waves();
    nightSky();
    boat3();
    moon();
    plain();
    clouds();
    airship();
    night_land();
    night_treesAndHouse();
    night_Hills();
    bridge();
    backBridgeTower();
    Car();
    Bus();
    frontBridgeTower();
    boat1();
    boat2();
    glFlush();
}

void day() {
    river();
    waves();
    sky();
    sun();
    plain();
    clouds();
    airship();
    land();
    treesAndHouse();
    Hills();
    boat3();
    bridge();
    backBridgeTower();
    Car();
    Bus();
    frontBridgeTower();
    boat1();
    boat2();
}

void Monsoon()
{
    monsoontRiver();
    waves();
    monsoonSky();
    boat3();
    monsoonClouds();
    monsoon_land();
    monsoon_treesAndHouse();
    monsoon_Hills();
    bridge();
    backBridgeTower();
    Car();
    Bus();
    frontBridgeTower();
    boat1();
    boat2();
    RainFall();
    glFlush();
}
void init() {
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 50);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);

    if (nightMode) {
        nightScene();
    } else {
        day();
    }
    if (monsoonMode) {
        Monsoon();
    }
    glFlush();
}

void handleKeyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'D':
      isDay = true;
      glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
      break;
    case 'N':
      isDay = false;
      glClearColor(0.2f, 0.2f, 0.5f, 1.0f);
      break;
  glutPostRedisplay();
}
}
void InstructionsDisplay() {
    cout << "-INSTRUCTIONS OF CONTROL-" << endl;
    cout << "->Mouse: " << endl;
    cout << "Mouse Left Button -> Increase the speed." << endl;
    cout << "Mouse Right Button -> Decrease the speed." << endl;
    cout << "->Keyboard:" << endl;
    cout << "For 'N' -> 'Night Mode'" << endl;
    cout << "For 'D' -> 'Day Mode'" << endl;
    cout << "For 'M' -> 'Monsoon Mode'" << endl;
    cout << "For 'S' -> 'Stop All Animations'" << endl;
    cout << "For 'I' -> 'Start All Animations'" << endl;
    cout << "For 'B' -> 'Stop Boat Animations'" << endl;
    cout << "For 'V' -> 'Start Boat Animations'" << endl;
    cout << "For 'Q' -> 'Speed Up All Animations'" << endl;
    cout << "For 'W' -> 'Slow Down All Animations'\n\n" << endl;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'n':
        case 'N':
            nightMode = true;
            monsoonMode = false;
            break;
        case 'd':
        case 'D':
            nightMode = false;
            monsoonMode = false;
            break;
        case 'm':
        case 'M':
            monsoonMode = true;
            break;
        case 's':
        case 'S':
            animationsRunning = false;
            break;
        case 'i':
        case 'I':
            animationsRunning = true;
            break;
        case 'b':
        case 'B':
            boatsRunning = false;
            break;
        case 'v':
        case 'V':
            boatsRunning = true;
            break;
        case 'q':
        case 'Q':
            animationSpeedFactor *= 1.2f;
            break;
        case 'w':
        case 'W':
            animationSpeedFactor /= 1.2f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Animated Natural Scene with Bridge, River and Mountain");
    glClearColor(0.7, 0.9, 1.0, 1.0);
    gluOrtho2D(0.0, 100.0, 0.0, 50.0);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    InstructionsDisplay();

    glutTimerFunc(40 / animationSpeedFactor, CloudAnimation1, 0);
    glutTimerFunc(40 / animationSpeedFactor, BoatAnimation, 0);
    glutTimerFunc(40 / animationSpeedFactor, BoatAnimation2, 0);
    glutTimerFunc(40 / animationSpeedFactor, WaveAnimation, 0);
    glutTimerFunc(40 / animationSpeedFactor, PlaneAnimation, 0);
    glutTimerFunc(40 / animationSpeedFactor, AirshipAnimation, 0);
    glutTimerFunc(250 / animationSpeedFactor, RainAnimation, 0);
    glutTimerFunc(16 / animationSpeedFactor, updateBus, 0);
    glutTimerFunc(16 / animationSpeedFactor, updateCar, 0);

    glutMainLoop();
    return 0;
}
