#include <QApplication>

#include "viewer.h"
#include "openglviewer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString path = "../viewer/assets/cube.obj";
    Model m(path);
    OpenGLViewer v(nullptr, &m);
    Viewer w(nullptr, &v);
    w.setWindowIcon(QIcon(QFileInfo("../viewer/assets/viewer_icon.png").absoluteFilePath()));
    w.show();
    //v.show();
    return a.exec();
}
