#ifndef OpenGLViewer_H
#define OpenGLViewer_H

#include "Model.h"
#include "VertexData.h"

class OpenGLViewer : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit OpenGLViewer(QWidget *parent, Model *model);
  ~OpenGLViewer();

 protected:
  virtual void initializeGL();
  virtual void resizeGL(int nWidth, int nHeight);
  virtual void paintGL();
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

#endif  // OpenGLViewer_H
