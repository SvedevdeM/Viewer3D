#include "openglviewer.h"

OpenGLViewer::OpenGLViewer(QWidget *parent, Model *model)
    : QOpenGLWidget{parent},
      m_texture(0),
      m_indexBuffer(QOpenGLBuffer::IndexBuffer),
      m(model) {
  connect(m, SIGNAL(changeFileSignal()), this, SLOT(dataProcessing()));
  connect(this, SIGNAL(changeColorSignal()), this,
          SLOT(changeBackgroundColor()));
  connect(this, SIGNAL(rotateModelSignalX(float)), this,
          SLOT(rotateModelX(float)));
  connect(this, SIGNAL(rotateModelSignalY(float)), this,
          SLOT(rotateModelY(float)));
  connect(this, SIGNAL(rotateModelSignalZ(float)), this,
          SLOT(rotateModelZ(float)));
  connect(this, SIGNAL(scaleModelSignalX(int)), this, SLOT(scaleModelX(int)));
  connect(this, SIGNAL(scaleModelSignalY(int)), this, SLOT(scaleModelY(int)));
  connect(this, SIGNAL(scaleModelSignalZ(int)), this, SLOT(scaleModelZ(int)));
  connect(this, SIGNAL(translateModeleSignalX(int)), this,
          SLOT(translateModeleX(int)));
  connect(this, SIGNAL(translateModeleSignalY(int)), this,
          SLOT(translateModeleY(int)));
  connect(this, SIGNAL(translateModeleSignalZ(int)), this,
          SLOT(translateModeleZ(int)));
}

/*virtual*/ void OpenGLViewer::initializeGL() {
  glClearColor(vec3[0] / 255.0, vec3[1] / 255.0, vec3[2] / 255.0, 1.0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  initShaders();
  dataProcessing();
}

/*virtual*/ void OpenGLViewer::resizeGL(int nWidth, int nHeight) {
  float aspect = nWidth / (float)nHeight;
  projectMatrix.setToIdentity();
  if (typeProj == 'c')
    projectMatrix.perspective(45, aspect, 0.1f, 800.0f);
  else if (typeProj == 'p')
    projectMatrix.ortho(-4.0f, 4.0f, -4.0f, 4.0f, 0.1f, 800.0f);
}

/*virtual*/ void OpenGLViewer::paintGL() {
  resizeGL(this->width(), this->height());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(vec3[0] / 255.0, vec3[1] / 255.0, vec3[2] / 255.0, 1.0f);
  modelViewMatrix.setToIdentity();
  modelViewMatrix.translate(0.01 * translateX, 0.01 * translateY,
                            -5.0 + 0.01 * translateZ);
  modelViewMatrix.rotate(rotation);
  QMatrix4x4 scalingMatrix;
  scalingMatrix.scale(1.0f + 0.01 * scaleX, 1.0f + 0.01 * scaleY,
                      1.0f + 0.01 * scaleZ);
  // scalingMatrix.scale(1.0f/60, 1.0f/60, 1.0f/60);
  modelViewMatrix *= scalingMatrix;

  m_texture->bind(0);

  m_program.bind();
  m_program.setUniformValue("qt_ModelViewProjectionMatrix",
                            projectMatrix * modelViewMatrix);

  m_program.setUniformValue("qt_Texture0", 0);

  m_arrayBuffer.bind();
  int offset = 0;
  int vertLoc = m_program.attributeLocation("qt_Vertex");
  m_program.enableAttributeArray(vertLoc);
  m_program.setAttributeBuffer(vertLoc, GL_FLOAT, offset, 3,
                               sizeof(VertexData));

  offset += sizeof(QVector3D);

  int textLoc = m_program.attributeLocation("qt_MultiTexCoord0");
  m_program.enableAttributeArray(textLoc);
  m_program.setAttributeBuffer(textLoc, GL_FLOAT, offset, 2,
                               sizeof(VertexData));

  m_indexBuffer.bind();
  glDrawElements(GL_TRIANGLES, m_indexBuffer.size(), GL_UNSIGNED_INT, 0);
}

void OpenGLViewer::dataProcessing() {
  QVector<QVector3D> vertices;
  QVector<QVector2D> uvs;
  QVector<QVector3D> normals;
  if (m_texture != nullptr) delete m_texture;
  vertexes.clear();
  indexes.clear();
  if (m_arrayBuffer.isCreated()) m_arrayBuffer.destroy();
  if (m_indexBuffer.isCreated()) m_indexBuffer.destroy();
  for (int i = 0; i < m->fileLines.size(); i++) {
    QString str = m->fileLines[i];
    QStringList list = str.split(" ");
    if (list[0] == "#" || list[0] == "mtllib")
      continue;
    else if (list[0] == "v")
      vertices.append(
          QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
    else if (list[0] == "vt")
      uvs.append(QVector2D(list[1].toFloat(), list[2].toFloat()));
    else if (list[0] == "vn")
      normals.append(
          QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
    else if (list[0] == "f") {
      for (int i = 1; i <= 3; i++) {
        QStringList innerList = list[i].split("/");
        vertexes.append(VertexData(vertices[innerList[0].toInt() - 1],
                                   uvs[innerList[1].toInt() - 1],
                                   normals[innerList[2].toInt() - 1]));
        indexes.append(indexes.size());
      }
    }
  }
  m_arrayBuffer.create();
  m_arrayBuffer.bind();
  m_arrayBuffer.allocate(vertexes.constData(),
                         vertexes.size() * sizeof(VertexData));
  m_arrayBuffer.release();

  m_indexBuffer.create();
  m_indexBuffer.bind();
  m_indexBuffer.allocate(indexes.constData(), indexes.size() * sizeof(GLuint));
  m_indexBuffer.release();

  m_texture = new QOpenGLTexture(
      QImage(QFileInfo("../assets/picture.png").absoluteFilePath()).mirrored());
  repaint();
  return;
}

void OpenGLViewer::changeBackgroundColor() { update(); }

void OpenGLViewer::initShaders() {
  m_program.addShaderFromSourceFile(
      QOpenGLShader::Vertex,
      QFileInfo("../assets/vshader.vsh").absoluteFilePath());
  m_program.addShaderFromSourceFile(
      QOpenGLShader::Fragment,
      QFileInfo("../assets/fshader.fsh").absoluteFilePath());
  m_program.link();
}

OpenGLViewer::~OpenGLViewer() {
  if (m_texture != nullptr) delete (m_texture);
}

void OpenGLViewer::setVec3(float red, float green, float blue) {
  vec3 = {red, green, blue};
}

void OpenGLViewer::rotateModelX(float angle) {
  QVector3D axis = QVector3D(1.0, 0.0, 0.0);
  rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;
  update();
}

void OpenGLViewer::rotateModelY(float angle) {
  QVector3D axis = QVector3D(0.0, 1.0, 0.0);
  rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;
  update();
}

void OpenGLViewer::rotateModelZ(float angle) {
  QVector3D axis = QVector3D(0.0, 0.0, 1.0);
  rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;
  update();
}

void OpenGLViewer::scaleModelX(int direction) {
  if (scaleX >= -99 || direction > 0) {
    scaleX += direction;
    update();
  }
}

void OpenGLViewer::scaleModelY(int direction) {
  if (scaleY >= -99 || direction > 0) {
    scaleY += direction;
    update();
  }
}

void OpenGLViewer::scaleModelZ(int direction) {
  if (scaleZ >= -99 || direction > 0) {
    scaleZ += direction;
    update();
  }
}

void OpenGLViewer::translateModeleX(int direction) {
  translateX += direction;
  update();
}

void OpenGLViewer::translateModeleY(int direction) {
  translateY += direction;
  update();
}

void OpenGLViewer::translateModeleZ(int direction) {
  translateZ += direction;
  update();
}

void OpenGLViewer::setProj() {
  if (typeProj == 'c')
    typeProj = 'p';
  else if (typeProj == 'p')
    typeProj = 'c';
  update();
}
