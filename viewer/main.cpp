#include <QApplication>

#include "viewer.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Viewer w;
  w.setWindowIcon(QIcon(QFileInfo("assets/viewer_icon.png").absoluteFilePath()));
  w.show();
  return a.exec();
}
