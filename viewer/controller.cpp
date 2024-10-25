#include "controller.h"

Controller::Controller(QWidget *parent, Model *model) :  QWidget(parent)
{
    m = model;
}

void Controller::changeFile(QString &path)
{
    m->path = path;
    m->loadOBJ();
    m->changeModelSendSignal();
}


