#include "viewer.h"

#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent, OpenGLViewer *viewer, Controller *controller)
    : QMainWindow(parent), ui(new Ui::Viewer) {
  ui->setupUi(this);
  glWindow = viewer;
  c = controller;
  setCentralWidget(glWindow);

  dock = new QDockWidget;
  addDockWidget(Qt::RightDockWidgetArea, dock);
  view = new QGraphicsView;
  scene = new QGraphicsScene(this);

  view->setScene(scene);
  view->setRenderHint(QPainter::Antialiasing, true);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  auto content = view->contentsRect();
  view->setSceneRect(0, 0, 150, content.height());
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  dock->setWidget(view);

  connectSlots();
  drawField();
}

Viewer::~Viewer() { delete ui; }

void Viewer::connectSlots() {
  // add more slots for existing actions
  connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
  connect(ui->actionUpload_file, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(ui->actionShow_information, SIGNAL(triggered()), this, SLOT(showInfo()));
  connect(ui->actionBackground_2, SIGNAL(triggered()), this, SLOT(changeBackground()));
  connect(ui->actionParallel_2, SIGNAL(triggered()), glWindow, SLOT(setProj()));
  connect(ui->actionCentral_2, SIGNAL(triggered()), glWindow, SLOT(setProj()));
}

void Viewer::drawField() {
  scene->clear();
  drawStats();
  view->update();
}

void Viewer::openFile() {
  filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home",
                                          tr("Object Files (*.obj)"));
  c->changeFile(filename);
  drawField();
}

void Viewer::showInfo() {
  dock->setVisible(true);
}

void Viewer::drawStats() {
  QFont font;
  font.setBold(true);
  font.setFamily("Purisa");
  font.setPixelSize(13);

  QStringList pieces = filename.split("/");
  QString formattedName;
  if (pieces.length() > 5) {
    QList<QString>::iterator it = ++pieces.begin();
    formattedName = QString("/%1/%2/%3/.../%4")
                        .arg(*(it++))
                        .arg(*(it++))
                        .arg(*(it++))
                        .arg(*(--pieces.end()));
  } else
    formattedName = filename;

  auto text = scene->addSimpleText(QString("File: %1").arg(formattedName));
  addText(font, text, 5, 3);
  text = scene->addSimpleText(QString("Edges: %1").arg(QString::number(edges)));
  addText(font, text, 5, 35);
  text = scene->addSimpleText(
      QString("Vertices: %1").arg(QString::number(vertices)));
  addText(font, text, 5, 55);
  text = scene->addSimpleText(
      QString("\nRotate 90:\nA  ← D  →\nW  ↑  S  ↓\n\nSelect axis:\nShift+X  "
              "X\nShift+Y  Y\nShift+Z  Z\n\nTranslate 90:\nShift+A  "
              "↻\nShift+D  ↺\n\nScale:\nShift+W up\nShift+S down"));
  addText(font, text, 5, 75);
}

void Viewer::addText(QFont font, QGraphicsSimpleTextItem *text, int x, int y) {
  text->setPos(x, y);
  text->setFont(font);
  text->setBrush(Qt::gray);
}



void Viewer::changeBackground()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет");
    if (color.isValid())glWindow->setVec3(color.red(), color.green(), color.blue());
    glWindow->repaint();
    emit glWindow->changeColorSignal();
}

void Viewer::keyPressEvent(QKeyEvent *event)  {
    switch (event->key()) {
    case Qt::Key_S:
        if (event->modifiers() == Qt::ShiftModifier)emit glWindow->scaleModelSignalY(-1);
        else if(event->modifiers() == Qt::AltModifier)emit glWindow->translateModeleSignalY(-1);
        else emit glWindow->rotateModelSignalX(1.0);
        break;
    case Qt::Key_W:
        if (event->modifiers() == Qt::ShiftModifier)emit glWindow->scaleModelSignalY(1);
        else if(event->modifiers() == Qt::AltModifier)emit glWindow->translateModeleSignalY(1);
        else emit glWindow->rotateModelSignalX(-1.0);
        break;
    case Qt::Key_Q:
        if(event->modifiers() == Qt::ShiftModifier)emit glWindow->scaleModelSignalX(1);
        else if(event->modifiers() == Qt::AltModifier)emit glWindow->translateModeleSignalZ(-1);
        else emit glWindow->rotateModelSignalY(-1.0);
        break;
    case Qt::Key_E:
        if(event->modifiers() == Qt::ShiftModifier)emit glWindow->scaleModelSignalX(-1);
        else if(event->modifiers() == Qt::AltModifier)emit glWindow->translateModeleSignalZ(1);
        else emit glWindow->rotateModelSignalY(1.0);
        break;
    case Qt::Key_A:
        if(event->modifiers() == Qt::ShiftModifier)emit glWindow->scaleModelSignalZ(1);
        else if(event->modifiers() == Qt::AltModifier)emit glWindow->translateModeleSignalX(-1);
        else emit glWindow->rotateModelSignalZ(1.0);
        break;
    case Qt::Key_D:
        if(event->modifiers() == Qt::ShiftModifier)emit glWindow->scaleModelSignalZ(-1);
        else if(event->modifiers() == Qt::AltModifier)emit glWindow->translateModeleSignalX(1);
        else emit glWindow->rotateModelSignalZ(-1.0);
        break;
    }
}
