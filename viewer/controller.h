#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include "Model.h"

class Controller : public QWidget
{
    Q_OBJECT
public:
    Controller(QWidget *parent, Model *model);
    void changeFile(QString &path);
private:
    Model *m;
};

#endif // CONTROLLER_H
