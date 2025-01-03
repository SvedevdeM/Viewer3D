#ifndef VERTEXDATA_H
#define VERTEXDATA_H

#include <QColorDialog>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFont>
#include <QFontDatabase>
#include <QGLFunctions>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLWidget>
#include <QPen>
#include <QPushButton>
#include <QQuaternion>
#include <QStringList>
#include <QVector2D>
#include <QVector3D>
#include <QVector>
#include <QtOpenGL>

struct VertexData {
  VertexData() {}
  VertexData(QVector3D &p, QVector2D &t, QVector3D &n)
      : position(p), texCoord(t), normals(n) {}
  QVector3D position;
  QVector2D texCoord;
  QVector3D normals;
} typedef VertexData;

#endif  // VERTEXDATA_H
