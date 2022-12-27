#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = 0, yAngle = 0, zAngle = 0;
    EnvMode = GL_REPLACE;
    TexFilter = GL_LINEAR;

    setWindowTitle("OpenGL TextureMapping");
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

    glEnable(GL_TEXTURE_2D);
    QImage* image = new QImage("stone.bmp");
    data = image -> bits();

    //image->mirror();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image ->width(),
                 image->height(), 0 ,GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, EnvMode);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, TexFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, TexFilter);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glTexCoord2f(0.0, 1.0);
    glVertex2f(-0.5, 0.5);

    glTexCoord2f(1.0,1.0);
    glVertex2f(0.5, 0.5);
    glTexCoord2f(1.0, 0.0);
    glVertex2f(0.5, -0.5);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,0,0);
    glTexCoord2f(0.5,0.5);
    glVertex3f(0.0, 0.0, -0.8);
    glTexCoord2f(1.0,1.0);
    glVertex2f(0.5, 0.5);
    glTexCoord2f(0.0,1.0);
    glVertex2f(-0.5, 0.5);



    glFlush();
}
