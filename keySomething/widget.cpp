#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Anti-Aliasing");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1 ,-1, 1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if(alias)
    {
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
    }
    else
    {
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
    }

    glHint(GL_POINT_SMOOTH_HINT, hint?GL_NICEST:GL_FASTEST);
    glHint(GL_LINE_SMOOTH_HINT, hint?GL_NICEST:GL_FASTEST);
    glHint(GL_POLYGON_SMOOTH_HINT, hint?GL_NICEST:GL_FASTEST);

    glPointSize(10.0);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.8);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8, 0.7);
    glVertex2f(0.8, 0.5);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(0.0, 0.4);
    glColor3f(0,1,0);
    glVertex2f(-0.4, 0.0);
    glColor3f(0,0,1);
    glVertex2f(0.0, -0.4);
    glColor3f(1,1,0);
    glVertex2f(0.4, 0.0);
    glEnd();

    glFlush();
}

void Widget::KeyPressEvent(QKeyEvent* evnet)
{
    switch(evnet -> key())
    {
    case Qt::Key_Up :
        qDebug() << "위버튼 누름";
        alias = TRUE;
        break;
    case Qt::Key_Down:
        alias = FALSE;
        break;
    case Qt::Key_Left:
        hint = TRUE;
        break;
    case Qt::Key_Right:
        hint = FALSE;
        break;
    };

    update();
}

