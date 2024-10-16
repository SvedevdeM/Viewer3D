#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>

#include <QFileInfo>
#include <QFileDialog>
#include <QFont>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QKeyEvent>
//#include <QPainter>
//#include <QPainterPath>
#include <QPen>

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
  void drawField(); // model
  void drawStats(); // file, edges, vertices
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
