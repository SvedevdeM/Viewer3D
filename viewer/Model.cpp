#include "Model.h"

Model::Model(QString &p) : path(p) { loadOBJ(); }
void Model::loadOBJ() {
  QFile file(QFileInfo(path).absoluteFilePath());
  if (!file.exists()) {
    qDebug() << "file not found";
    return;
  }
  file.open(QIODevice::ReadOnly);
  QTextStream input(&file);
  while (!input.atEnd()) {
    QString str = input.readLine();
    fileLines.append(str);
  }
  file.close();
  return;
}
