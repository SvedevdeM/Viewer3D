#ifndef MODEL_H
#define MODEL_H

#include <QObject>

#include "VertexData.h"

class OpenGLViewer;
class Controller;

class Model : public QObject {
  Q_OBJECT
  friend class OpenGLViewer;
  friend class Controller;
 signals:
  void changeFileSignal();

 public:
  Model(QObject *pobj, QString &path);
  void changeModelSendSignal();

 private:
  QVector<QString> fileLines;
  QString path;
  void loadOBJ();

 signals:
};

#endif  // MODEL_H
