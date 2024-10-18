#ifndef MODEL_H
#define MODEL_H

#include "VertexData.h"

class OpenGLViewer;

class Model
{
    friend class OpenGLViewer;
public:
    Model(QString &path);
private:
    QVector<QString> fileLines;
    QString path;
    void loadOBJ();

};

#endif // MODEL_H
