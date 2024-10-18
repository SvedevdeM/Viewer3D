#ifndef VIEWER_H
#define VIEWER_H

#include "Model.h"
#include "VertexData.h"
#include "openglviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  Viewer(QWidget *parent, OpenGLViewer *viewer);
  ~Viewer();

  void connectSlots();
  void drawField();  // model
  void drawStats();  // file, edges, vertices
  void addText(QFont font, QGraphicsSimpleTextItem *text, int x, int y);
  void keyPressEvent(QKeyEvent *event);

 private slots:
  void openFile();
  void showInfo();

 private:
  Ui::Viewer *ui;
  QGraphicsView *view;
  QGraphicsScene *scene;
  QDockWidget *dock;
  int edges = 100;
  int vertices = 300;
  QString filename = QFileInfo("../assets/cube.obj").absoluteFilePath();
  OpenGLViewer *glWindow;
};
#endif  // VIEWER_H
