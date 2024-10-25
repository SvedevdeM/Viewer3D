#include <QApplication>

#include "openglviewer.h"
#include "viewer.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QString path = "";
  Model m(nullptr, path);
  Controller c(nullptr, &m);
  OpenGLViewer v(nullptr, &m);
  Viewer w(nullptr, &v, &c);
  w.setWindowIcon(
      QIcon(QFileInfo("../assets/viewer_icon.png").absoluteFilePath()));
  w.show();
  return a.exec();
}
