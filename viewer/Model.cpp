#include "Model.h"

Model::Model(QObject *parent, QString &p)
    : QObject{parent}, path(p)
{
    loadOBJ();
}

void Model::loadOBJ() {
    fileLines.clear();
    QFile file(QFileInfo(path).absoluteFilePath());
    if (!file.exists()) {
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

void Model::changeModelSendSignal()
{
    emit changeFileSignal();
}
