#include "widget.h"

#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = 0, yAngle = 0, zAngle = 0;
    red = 0.5, green = 0.5, blue =0.5;
    bColorTrack = GL_FALSE;

    setWindowTitle("OpenGL Lighting");
    resize(300, 300);
}
Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}


void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    GLfloat arLight[] = {red, green, blue, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, arLight);

    if(bColorTrack)
    {
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT,GL_AMBIENT);
    }
    else
    {
        glDisable(GL_COLOR_MATERIAL);
    }

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    GLfloat arbottom[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT,GL_AMBIENT, arbottom);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    GLfloat arMat1[] = {1.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, arMat1);
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1,1,1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1,0,0);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    GLfloat arMat2[] = {0.0, 0.0, 0.5, 1.0};
    glMaterialfv(GL_FRONT,GL_AMBIENT, arMat2);
    glColor3f(1,1,0);
    glVertex2f(-0.5, -0.5);

}

