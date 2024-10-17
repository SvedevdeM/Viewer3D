#ifndef VERTEXDATA_H
#define VERTEXDATA_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include<QMatrix4x4>
#include<QVector>
#include<QVector2D>
#include<QVector3D>
#include<QFile>
#include<QStringList>
#include<QGLFunctions>
#include<QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>

struct VertexData
{
    VertexData()
    {
    }
    VertexData(QVector3D &p, QVector2D &t, QVector3D &n) :
        position(p), texCoord(t), normals(n)
    {
    }
    QVector3D position;
    QVector2D texCoord;
    QVector3D normals;
}typedef VertexData;

#endif // VERTEXDATA_H



