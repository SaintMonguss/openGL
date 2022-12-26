#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    nx = 0, ny = 0;
    bScissor = FALSE;
    bStencil = FALSE;
    bEqual = FALSE;

    setWindowTitle("OpenGL Stencil");
    resize(300, 300);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions( );
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0, (GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1 ,-1, 1, -1, 1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    if(bScissor)
    {
        glEnable(GL_SCISSOR_TEST);
    }
    else
    {
        glDisable(GL_SCISSOR_TEST);
    }
    glScissor(10, 10, 150, 150);

    if(bStencil)
    {
        glEnable(GL_STENCIL_TEST);
    }
    else
    {
        glDisable(GL_STENCIL_TEST);
    }

    glStencilFunc(GL_NEVER, 0x0, 0x0);
    glStencilOp(GL_INCR, GL_INCR, GL_INCR);

    glColor3f(1,1,1);
    GLint arFac[] = { 1, 1, 1, 2, 3, 4, 2, 3, 2};
    GLushort arPat[] = { 0xaaaa, 0x33ff, 0x57ff, 0xaaaa, 0xaaaa, 0xaaaa, 0x33ff, 0x33ff, 0x57ff};
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(3);
    GLfloat y;
    GLint idx = 0;
    for(y = 0.8 ; y > -0.8; y -= 0.2)
    {
        glLineStipple(arFac[dx], arPat[idx]);
    }
}
