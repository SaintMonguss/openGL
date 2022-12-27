#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Lighting");
    resize(600, 600);
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
    GLubyte *data;

    glClear(GL_COLOR_BUFFER_BIT);

    QImage* image = new QImage("sample.bmp");
    data = image -> bits();
    image->mirror();
    if(data != NULL)
    {
        glRasterPos2f(-0.5,-0.5);
        glDrawPixels(image -> width(), image -> height(),
                     GL_BGRA, GL_UNSIGNED_BYTE, data);
    }
    glFlush();
}
