#include "viewer.h"

#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent) : QMainWindow(parent), ui(new Ui::Viewer) {
  ui->setupUi(this);
  scene = new QGraphicsScene(this);

  ui->graphicsView->setScene(scene);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
  ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  QRect content = ui->graphicsView->contentsRect();
  ui->graphicsView->setSceneRect(0, 0, content.width(), content.height());

  connectSlots();
  drawField();
}

Viewer::~Viewer() { delete ui; }

void Viewer::connectSlots() {
  // add more slots for existing actions
  connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
  connect(ui->actionUpload_file, SIGNAL(triggered()), this, SLOT(openFile()));
}

void Viewer::drawField() {
  // add model display
  scene->clear();
  drawStats();
  ui->graphicsView->update();
}

void Viewer::openFile() {
  QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Object Files (*.obj)"));
  QStringList pieces = file.split("/");
  if (pieces.length() > 5) {
    QList<QString>::iterator it = ++pieces.begin();
    filename = QString("/%1/%2/%3. . .%4").arg(*(it++)).arg(*(it++)).arg(*(it++)).arg(*(--pieces.end()));
  }
  else filename = file;
  drawField();
}

void Viewer::drawStats() {
  QFont font;
  font.setBold(true);
  font.setFamily("Purisa");
  font.setPixelSize(13);

  auto text = scene->addSimpleText(QString("File: %1").arg(filename));
  text->setPos(5, 3);
  text->setFont(font);
  text->setBrush(Qt::gray);

  text = scene->addSimpleText(QString("Edges: %1").arg(QString::number(edges)));
  text->setPos(5, 35);
  text->setFont(font);
  text->setBrush(Qt::gray);

  text = scene->addSimpleText(QString("Vertices: %1").arg(QString::number(vertices)));
  text->setPos(5, 55);
  text->setFont(font);
  text->setBrush(Qt::gray);
}

void Viewer::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_A:
      if (event->modifiers() == Qt::ShiftModifier) {}
        // translate clockwise 90
      // else rotate left 90
      break;
    case Qt::Key_W:
      if (event->modifiers() == Qt::ShiftModifier) {}
        //scale up
      // else rotate up 90
      break;
    case Qt::Key_S:
      if (event->modifiers() == Qt::ShiftModifier) {}
        // scale down
      // else rotate down 90
      break;
    case Qt::Key_D:
      if (event->modifiers() == Qt::ShiftModifier) {}
        // translate anti-clockwise 90
      // else rotate right 90
      break;
    case Qt::Key_X:
      if (event->modifiers() == Qt::ShiftModifier) {}
        // select x axis
      break;
    case Qt::Key_Y:
      if (event->modifiers() == Qt::ShiftModifier) {}
        // select x axis
      break;
    case Qt::Key_Z:
      if (event->modifiers() == Qt::ShiftModifier) {}
        // select x axis
      break;
  }
  // if changes --> drawField();
}

