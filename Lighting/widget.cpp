#include "widget.h"

#include <GL/glut.h>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    lx = 0, ly =0, lz = -1.0;
    xAngle = 0, yAngle = 0, zAngle = 0;
    bAmbient =FALSE;
    bAttach = FALSE;

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
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();

    if(bAttach)
    {
        glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
        glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
        glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
    }

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightpos[] = {lx, ly, lz, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    if(bAmbient)
    {
        GLfloat ambient[4] = {0,1,0,1};
        glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
    }
    else
    {
        GLfloat ambient[4] ={0,0,0,1};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    }

    if(bAttach == false)
    {
        glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
        glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
        glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
    }

    glutSolidTeapot(0.5);
       glPopMatrix();
       glFlush();
}
