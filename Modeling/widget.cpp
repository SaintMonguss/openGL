#include "widget.h"
#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    Action = 0;

    setWindowTitle("OpenGL Viewing");
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
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glutWireTeapot(0.2);

//    glFlush();
//    glClear(GL_COLOR_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//    glTranslatef(0.5, 0.5, 0.0);
//    glScalef(1.5, 1.5, 1.0);

//    glutWireTeapot(0.2);
//    glPopMatrix();

//    glFlush();

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();

    glRotatef(45.0, 0.0, 0.0, 1.0);

    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.8);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();

    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);

    switch(event -> key()) {
    case Qt::Key_Z: // 무변
        break;
    case Qt::Key_1: // 이동

        break;
    case Qt::Key_2: //엉뚱한 위치에 나타나는 이동

        break;
    case Qt::Key_3: // 단위 행렬로 리셋

        break;
    case Qt::Key_4: //스택에 저장 및 복구

        break;
    case Qt::Key_5:// 확대

    case Qt::Key_6://회전

        break;
    case Qt::Key_7:// 확대 후 이동

        break;
    case Qt::Key_8: //이동 후 확대

        break;
    case Qt::Key_9: // 원점 기준 회전

        break;

    case Qt::Key_0: // 제자리 회전

        break;

    }
    update();
}
