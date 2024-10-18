#include <QApplication>

#include "openglviewer.h"
#include "viewer.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QString path = "../assets/cube.obj";
  Model m(path);
  OpenGLViewer v(nullptr, &m);
  Viewer w(nullptr, &v);
  w.setWindowIcon(
      QIcon(QFileInfo("../assets/viewer_icon.png").absoluteFilePath()));
  w.show();
  return a.exec();
}
