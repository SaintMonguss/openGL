#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    bDepthTest = GL_TRUE;
    bCullFace = GL_FALSE;
    setWindowTitle("OpenGL Pyramid3D");
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
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glShadeModel(shadeMode);

    qDebug() << "1차 진입";

    if(bDepthTest)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }

    if(bCullFace)
    {
        glEnable(GL_CULL_FACE);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    //흰바닥
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();

    //빨강
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1,1,1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1,0,0);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    //노랑
    glColor3f(1,1,0);
    glVertex2f(-0.5, -0.5);

    //초록
    glColor3f(0,1,0);
    glVertex2f(0.5, -0.5);

    glColor3f(0,0,1);
    glVertex2f(0.5, 0.5);
    glEnd();

    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "키 함수 진입";
    switch (event -> key()) {
    case Qt::Key_Up:
        qDebug() << "키입력";
        bDepthTest = GL_TRUE;
        break;
    case Qt::Key_Down:
        bDepthTest = GL_FALSE;
        break;
    case Qt::Key_Left:
        bCullFace = GL_TRUE;
        break;
    case Qt::Key_Right:
        bCullFace = GL_FALSE;
        break;
    case Qt::Key_1:
        polygonMode = GL_POINT;
        break;
    case Qt::Key_2:
        polygonMode = GL_LINE;
        break;
    case Qt::Key_3:
        polygonMode = GL_FILL;
        break;
    case Qt::Key_4:
        polygonMode = GL_SMOOTH;
        break;
    case Qt::Key_5:
        polygonMode = GL_FLAT;
        break;

    }

    QString str = QString("Pyramid3D:x : %1, y : %2, z : %3")
            .arg(xAngle).arg(yAngle).arg(zAngle);

    setWindowTitle(str);
    update();

}
