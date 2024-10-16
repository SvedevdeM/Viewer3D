#ifndef VIEWER_H
#define VIEWER_H

#include <QFileDialog>
#include <QFileInfo>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QPen>
#include <QtOpenGL>

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  Viewer(QWidget *parent = nullptr);
  ~Viewer();

  void connectSlots();
  void drawField();  // model
  void drawStats();  // file, edges, vertices
  void addText(QFont font, QGraphicsSimpleTextItem *text, int x, int y);
  void keyPressEvent(QKeyEvent *event);

 private slots:
  void openFile();

 private:
  Ui::Viewer *ui;
  QGraphicsScene *scene;
  int edges = 100;
  int vertices = 300;
  QString filename = "/home/User/Desktop/test.obj";
};
#endif  // VIEWER_H
