#include "openglviewer.h"

OpenGLViewer::OpenGLViewer(QWidget *parent, Model *model)
    : QOpenGLWidget{parent}, m_texture(0), m_indexBuffer(QOpenGLBuffer::IndexBuffer), m(model)
{
}

/*virtual*/void  OpenGLViewer::initializeGL()
{
    glClearColor(10, 0, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    initShaders();
    dataProcessing();
}

/*virtual*/void OpenGLViewer::resizeGL(int nWidth, int nHeight)
{
    float aspect = nWidth/(float) nHeight;
    projectMatrix.setToIdentity();
    projectMatrix.perspective(45, aspect, 0.1f, 80.0f);
}

/*virtual*/void OpenGLViewer::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    QMatrix4x4 modelViewMatrix;
    modelViewMatrix.setToIdentity();
    modelViewMatrix.translate(0.0, 0.0, -5.0);
    modelViewMatrix.rotate(70.0, 30.0, 0.0);

    m_texture->bind(0);

    m_program.bind();
    m_program.setUniformValue("qt_ModelViewProjectionMatrix", projectMatrix * modelViewMatrix);

    m_program.setUniformValue("qt_Texture0", 0);

    m_arrayBuffer.bind();
    int offset = 0;
    int vertLoc = m_program.attributeLocation("qt_Vertex");
    m_program.enableAttributeArray(vertLoc);
    m_program.setAttributeBuffer(vertLoc, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    int textLoc = m_program.attributeLocation("qt_MultiTexCoord0");
    m_program.enableAttributeArray(textLoc);
    m_program.setAttributeBuffer(textLoc, GL_FLOAT, offset, 2, sizeof(VertexData));

    m_indexBuffer.bind();
    glDrawElements(GL_TRIANGLES, m_indexBuffer.size(), GL_UNSIGNED_INT, 0);
}

void OpenGLViewer::dataProcessing()
{
    QVector< QVector3D > vertices;
    QVector< QVector2D > uvs;
    QVector< QVector3D > normals;

    for(int i = 0; i < m->fileLines.size();i++)
    {
        QString str = m->fileLines[i];
        QStringList list = str.split(" ");
        if(list[0] == "#" || list[0] == "mtllib")continue;
        else if(list[0] == "v")vertices.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
        else if(list[0] == "vt")uvs.append(QVector2D(list[1].toFloat(), list[2].toFloat()));
        else if(list[0] == "vn")normals.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
        else if(list[0] == "f")
        {
            for(int i = 1; i <= 3; i++)
            {
                QStringList innerList = list[i].split("/");
                vertexes.append(VertexData(vertices[innerList[0].toInt() - 1], uvs[innerList[1].toInt() - 1], normals[innerList[2].toInt() - 1]));
                indexes.append(indexes.size());
            }
        }
    }
    m_arrayBuffer.create();
    m_arrayBuffer.bind();
    m_arrayBuffer.allocate(vertexes.constData(), vertexes.size()*sizeof(VertexData));
    m_arrayBuffer.release();

    m_indexBuffer.create();
    m_indexBuffer.bind();
    m_indexBuffer.allocate(indexes.constData(), indexes.size()*sizeof(GLuint));
    m_indexBuffer.release();

    m_texture = new QOpenGLTexture(QImage(QFileInfo("../viewer/picture.png").absoluteFilePath()).mirrored());
    return;
}

void OpenGLViewer::initShaders()
{
    m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, QFileInfo("../viewer/vshader.vsh").absoluteFilePath());
    m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, QFileInfo("../viewer/fshader.fsh").absoluteFilePath());
    m_program.link();
}

OpenGLViewer::~OpenGLViewer()
{
    if(m_texture != nullptr)delete(m_texture);
}
