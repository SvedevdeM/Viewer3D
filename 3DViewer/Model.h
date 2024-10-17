#ifndef MODEL_H
#define MODEL_H

#include "VertexData.h"

class Viewer;

class Model
{
    friend class Viewer;
public:
    Model(QString &path);
private:
    QVector<QString> fileLines;
    QString path;
    void loadOBJ();

};

#endif // MODEL_H
