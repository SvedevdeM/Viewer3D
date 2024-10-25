#ifndef OpenGLViewer_H
#define OpenGLViewer_H

#include "Model.h"
#include "VertexData.h"

class Viewer;

class OpenGLViewer : public QOpenGLWidget {
    friend class Viewer;
    Q_OBJECT
 public:
    explicit OpenGLViewer(QWidget *parent, Model *model);
    void setVec3(float red, float green, float blue);
    ~OpenGLViewer();
 protected:
    virtual void initializeGL();
    virtual void resizeGL(int nWidth, int nHeight);
    virtual void paintGL();
    void initShaders();

private:
    QMatrix4x4 projectMatrix;
    QVector<VertexData> vertexes;
    QVector<GLuint> indexes;
    QOpenGLShaderProgram m_program;
    QOpenGLTexture *m_texture;
    QOpenGLBuffer m_arrayBuffer;
    QOpenGLBuffer m_indexBuffer;
    QMatrix4x4 modelViewMatrix;
    Model *m;
    QVector3D vec3 = {153.0, 34.0, 46.0};
    QQuaternion rotation;
    int scaleX = 0, scaleY = 0, scaleZ = 0;
    int translateX = 0, translateY = 0, translateZ = 0;
    char typeProj = 'c';
private slots:
    void dataProcessing();
    void changeBackgroundColor();
    void rotateModelX(float angle);
    void rotateModelY(float angle);
    void rotateModelZ(float angle);
    void scaleModelX(int direction);
    void scaleModelY(int direction);
    void scaleModelZ(int direction);
    void translateModeleX(int direction);
    void translateModeleY(int direction);
    void translateModeleZ(int direction);
    void setProj();
signals:
    void changeColorSignal();
    void rotateModelSignalX(float angle);
    void rotateModelSignalY(float angle);
    void rotateModelSignalZ(float angle);
    void scaleModelSignalX(int direction);
    void scaleModelSignalY(int direction);
    void scaleModelSignalZ(int direction);
    void translateModeleSignalX(int direction);
    void translateModeleSignalY(int direction);
    void translateModeleSignalZ(int direction);

};

#endif  // OpenGLViewer_H
