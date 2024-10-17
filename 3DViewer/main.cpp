#include "Viewer.h"
#include "Model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString path = ":/cube.obj";
    Model m(path);
    Viewer v(nullptr, &m);
    v.show();
    return a.exec();
}
