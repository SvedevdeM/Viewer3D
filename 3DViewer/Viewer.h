#ifndef VIEWER_H
#define VIEWER_H

#include "VertexData.h"
#include "Model.h"


class Viewer : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit Viewer(QWidget *parent, Model *model);
    ~Viewer();
protected:
    virtual void initializeGL( ) ;
    virtual void resizeGL (int nWidth, int nHeight);
    virtual void paintGL( ) ;
    void initShaders();
private:
    void dataProcessing();
    QMatrix4x4 projectMatrix;
    QVector<VertexData> vertexes;
    QVector<GLuint> indexes;
    QOpenGLShaderProgram m_program;
    QOpenGLTexture *m_texture;
    QOpenGLBuffer m_arrayBuffer;
    QOpenGLBuffer m_indexBuffer;
    Model *m;
};

#endif // VIEWER_H
