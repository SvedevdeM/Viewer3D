#include "viewer.h"

#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent,  OpenGLViewer *viewer) : QMainWindow(parent), ui(new Ui::Viewer) {
    glWindow = viewer;
    ui->openGLWidget = glWindow;
    ui->setupUi(this);
    //scene = new QGraphicsScene(this);

    //ui->graphicsViewc->setScene(scene);
    //ui->graphicsViewc->setRenderHint(QPainter::Antialiasing, true);
   // ui->graphicsViewc->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    //QRect content = ui->graphicsViewc->contentsRect();
   // ui->graphicsViewc->setSceneRect(0, 0, content.width(), content.height());

    connectSlots();
    //drawField();
}

Viewer::~Viewer() { delete ui; }

void Viewer::connectSlots() {
    // add more slots for existing actions
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionUpload_file, SIGNAL(triggered()), this, SLOT(openFile()));
}

void Viewer::drawField() {
    // add model display
    //scene->clear();
     drawStats();
    //ui->graphicsViewc->update();
}

void Viewer::openFile() {
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home",
                                            tr("Object Files (*.obj)"));
    drawField();
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
        formattedName = QString("/%1/%2/%3. . .%4")
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
}

void Viewer::addText(QFont font, QGraphicsSimpleTextItem *text, int x, int y) {
    text->setPos(x, y);
    text->setFont(font);
    text->setBrush(Qt::gray);
}

void Viewer::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        if (event->modifiers() == Qt::ShiftModifier) {
        }
        // translate clockwise 90
        // else rotate left 90
        break;
    case Qt::Key_W:
        if (event->modifiers() == Qt::ShiftModifier) {
        }
        // scale up
        // else rotate up 90
        break;
    case Qt::Key_S:
        if (event->modifiers() == Qt::ShiftModifier) {
        }
        // scale down
        // else rotate down 90
        break;
    case Qt::Key_D:
        if (event->modifiers() == Qt::ShiftModifier) {
        }
        // translate anti-clockwise 90
        // else rotate right 90
        break;
    case Qt::Key_X:
        if (event->modifiers() == Qt::ShiftModifier) {
        }
        // select x axis
        break;
    case Qt::Key_Y:
        if (event->modifiers() == Qt::ShiftModifier) {
        }
        // select x axis
        break;
    case Qt::Key_Z:
        if (event->modifiers() == Qt::ShiftModifier) {
        }
        // select x axis
        break;
    }
    // if changes --> drawField();
}
