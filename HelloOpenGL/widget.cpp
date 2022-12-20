#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("Hello OpenGL");
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
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, w/this -> size().width(), 0, h/this -> size().height(), -1, 1);
   glViewport(0, 0, (GLint)w, (GLint)h);
}


