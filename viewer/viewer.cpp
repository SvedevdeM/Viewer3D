#include "viewer.h"

#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent, OpenGLViewer *viewer, Controller *controller)
    : QMainWindow(parent), ui(new Ui::Viewer) {
  ui->setupUi(this);
  glWindow = viewer;
  c = controller;
  setCentralWidget(glWindow);
  loadFont();
  viewSetup();
  connectSlots();
  drawField();
}

Viewer::~Viewer() { delete ui; }

void Viewer::loadFont() {
  QFontDatabase::addApplicationFont(
      QFileInfo("../assets/purisa_font.ttf").absoluteFilePath());
  font = new QFont;
  font->setFamily("Purisa");
  font->setBold(true);
  font->setPixelSize(15);

  setFont(*font);
  ui->menubar->setFont(*font);
  ui->menuFile->setFont(*font);
  ui->menuSettings->setFont(*font);
 // ui->menuModel->setFont(*font);
  ui->menuProjection_type->setFont(*font);
}

void Viewer::viewSetup() {
  dock = new QDockWidget;
  addDockWidget(Qt::RightDockWidgetArea, dock);
  view = new QGraphicsView;
  scene = new QGraphicsScene(this);

  view->setScene(scene);
  view->setRenderHint(QPainter::Antialiasing, true);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  auto content = view->contentsRect();
  view->setSceneRect(0, 0, 200, content.height());
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setFrameShape(QFrame::NoFrame);
  view->setDragMode(QGraphicsView::RubberBandDrag);
  view->setStyleSheet("background-color: rgb(36, 31, 49);");

  dock->setWidget(view);
}

void Viewer::connectSlots() {
  connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
  connect(ui->actionUpload_file, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(ui->actionShow_information, SIGNAL(triggered()), this,
          SLOT(showInfo()));
  connect(ui->actionBackground, SIGNAL(triggered()), this,
          SLOT(changeBackground()));
  connect(ui->actionParallel, SIGNAL(triggered()), glWindow, SLOT(setProj()));
  connect(ui->actionCentral, SIGNAL(triggered()), glWindow, SLOT(setProj()));
}

void Viewer::drawField() {
  scene->clear();
  edges = (glWindow->vertexes.size() + 1) / 2;
  vertices = glWindow->vertexes.size();
  drawStats();
  view->update();
}

void Viewer::openFile() {
  filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home",
                                          tr("Object Files (*.obj)"));
  c->changeFile(filename);
  drawField();
}

void Viewer::showInfo() { dock->setVisible(true); }

void Viewer::drawStats() {
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
  addText(*font, text, 5, 3);
  text = scene->addSimpleText(QString("Edges: %1").arg(QString::number(edges)));
  addText(*font, text, 5, 35);
  text = scene->addSimpleText(
      QString("Vertices: %1").arg(QString::number(vertices)));
  addText(*font, text, 5, 55);
  text = scene->addSimpleText(
      QString("\nControls:\n\n\nRotate:\n\n\nTranslate:\n\n\nScale:"));
  addText(*font, text, 5, 75);
  drawControls();
}

void Viewer::drawControls() {
  int x = 7, y = 125, size = 20, space = 3;
  QString buttons[6] = {"Q", "W", "E", "A", "S", "D"};
  for (int i = 0; i < 6; i++) {
    addButton(x, y, size, size, buttons[i % 6]);
    x += size + space;
    if (x > (size * 3)) {
      y += size + space;
      x = 7;
    }
  }
  auto text = scene->addSimpleText("+");
  addText(*font, text, 50, 275);
  text = scene->addSimpleText("+");
  addText(*font, text, 60, 350);
  addButton(7, 200, size * 4 - 5, size + 5, "Controls");
  addButton(7, 275, size * 2, size + 5, "Alt");
  addButton(65, 275, size * 4 - 5, size + 5, "Controls");
  addButton(7, 350, size * 2 + 10, size + 5, "Shift");
  addButton(75, 350, size * 4 - 5, size + 5, "Controls");
}

void Viewer::addButton(int x, int y, int width, int height, QString text) {
  QPushButton *button = new QPushButton;
  button->setGeometry(QRect(x, y, width, height));
  button->setText(text);
  button->setDisabled(true);
  button->setStyleSheet(
      "background-color: transparent; color: rgb(43, 183, 233); font-family: "
      "'Purisa'; "
      "border: 1px solid rgb(43, 183, 233); border-radius: 5px;");
  scene->addWidget(button);
}

void Viewer::addText(QFont font, QGraphicsSimpleTextItem *text, int x, int y) {
  text->setPos(x, y);
  text->setFont(font);
  text->setBrush(Qt::white);
}

void Viewer::changeBackground() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
  if (color.isValid())
    glWindow->setVec3(color.red(), color.green(), color.blue());
  glWindow->repaint();
  emit glWindow->changeColorSignal();
}

void Viewer::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_S:
      if (event->modifiers() == Qt::ShiftModifier)
        emit glWindow->scaleModelSignalY(-1);
      else if (event->modifiers() == Qt::AltModifier)
        emit glWindow->translateModeleSignalY(-1);
      else
        emit glWindow->rotateModelSignalX(1.0);
      break;
    case Qt::Key_W:
      if (event->modifiers() == Qt::ShiftModifier)
        emit glWindow->scaleModelSignalY(1);
      else if (event->modifiers() == Qt::AltModifier)
        emit glWindow->translateModeleSignalY(1);
      else
        emit glWindow->rotateModelSignalX(-1.0);
      break;
    case Qt::Key_Q:
      if (event->modifiers() == Qt::ShiftModifier)
        emit glWindow->scaleModelSignalX(1);
      else if (event->modifiers() == Qt::AltModifier)
        emit glWindow->translateModeleSignalZ(-1);
      else
        emit glWindow->rotateModelSignalY(-1.0);
      break;
    case Qt::Key_E:
      if (event->modifiers() == Qt::ShiftModifier)
        emit glWindow->scaleModelSignalX(-1);
      else if (event->modifiers() == Qt::AltModifier)
        emit glWindow->translateModeleSignalZ(1);
      else
        emit glWindow->rotateModelSignalY(1.0);
      break;
    case Qt::Key_A:
      if (event->modifiers() == Qt::ShiftModifier)
        emit glWindow->scaleModelSignalZ(1);
      else if (event->modifiers() == Qt::AltModifier)
        emit glWindow->translateModeleSignalX(-1);
      else
        emit glWindow->rotateModelSignalZ(1.0);
      break;
    case Qt::Key_D:
      if (event->modifiers() == Qt::ShiftModifier)
        emit glWindow->scaleModelSignalZ(-1);
      else if (event->modifiers() == Qt::AltModifier)
        emit glWindow->translateModeleSignalX(1);
      else
        emit glWindow->rotateModelSignalZ(-1.0);
      break;
  }
  drawField();
}
