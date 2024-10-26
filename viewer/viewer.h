#ifndef VIEWER_H
#define VIEWER_H

#include "Model.h"
#include "VertexData.h"
#include "controller.h"
#include "openglviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  Viewer(QWidget *parent, OpenGLViewer *viewer, Controller *controller);
  ~Viewer();

  void loadFont();
  void viewSetup();
  void connectSlots();
  void drawField();
  void drawStats();
  void drawControls();
  void addText(QFont font, QGraphicsSimpleTextItem *text, int x, int y);
  void addButton(int x, int y, int width, int height, QString text);

 private slots:
  void openFile();
  void showInfo();
  void changeBackground();
  void keyPressEvent(QKeyEvent *event);

 private:
  Ui::Viewer *ui;
  QGraphicsView *view;
  QGraphicsScene *scene;
  QDockWidget *dock;
  QFont *font;
  QString filename;
  OpenGLViewer *glWindow;
  Controller *c;
  int edges;
  int vertices;
};
#endif  // VIEWER_H
