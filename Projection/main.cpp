#include "widget.h"

#include <QApplication>
#include <Gl/glut.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    glutIconifyWindow();
    Widget w;
    w.show();
    return a.exec();
}
