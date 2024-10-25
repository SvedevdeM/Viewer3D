/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Viewer
{
public:
    QAction *actionUpload_file;
    QAction *actionExit;
    QAction *action_bmp;
    QAction *action_jpeg;
    QAction *actionMake_screencast;
    QAction *actionRotate_model_2;
    QAction *actionTranslate_model;
    QAction *actionScale_model_2;
    QAction *actionEdges_2;
    QAction *actionVertices_2;
    QAction *actionBackground_2;
    QAction *actionParallel_2;
    QAction *actionCentral_2;
    QAction *actionNone;
    QAction *actionCircle;
    QAction *actionSquare;
    QAction *actionShow_information;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QOpenGLWidget *openGLWidget;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSave_as;
    QMenu *menuEdit;
    QMenu *menuSettings_2;
    QMenu *menuProjection_type_2;
    QMenu *menuDisplay_method;

    void setupUi(QMainWindow *Viewer)
    {
        if (Viewer->objectName().isEmpty())
            Viewer->setObjectName(QString::fromUtf8("Viewer"));
        Viewer->resize(660, 468);
        Viewer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        actionUpload_file = new QAction(Viewer);
        actionUpload_file->setObjectName(QString::fromUtf8("actionUpload_file"));
        actionExit = new QAction(Viewer);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        action_bmp = new QAction(Viewer);
        action_bmp->setObjectName(QString::fromUtf8("action_bmp"));
        action_jpeg = new QAction(Viewer);
        action_jpeg->setObjectName(QString::fromUtf8("action_jpeg"));
        actionMake_screencast = new QAction(Viewer);
        actionMake_screencast->setObjectName(QString::fromUtf8("actionMake_screencast"));
        actionRotate_model_2 = new QAction(Viewer);
        actionRotate_model_2->setObjectName(QString::fromUtf8("actionRotate_model_2"));
        actionTranslate_model = new QAction(Viewer);
        actionTranslate_model->setObjectName(QString::fromUtf8("actionTranslate_model"));
        actionScale_model_2 = new QAction(Viewer);
        actionScale_model_2->setObjectName(QString::fromUtf8("actionScale_model_2"));
        actionEdges_2 = new QAction(Viewer);
        actionEdges_2->setObjectName(QString::fromUtf8("actionEdges_2"));
        actionVertices_2 = new QAction(Viewer);
        actionVertices_2->setObjectName(QString::fromUtf8("actionVertices_2"));
        actionBackground_2 = new QAction(Viewer);
        actionBackground_2->setObjectName(QString::fromUtf8("actionBackground_2"));
        actionParallel_2 = new QAction(Viewer);
        actionParallel_2->setObjectName(QString::fromUtf8("actionParallel_2"));
        actionCentral_2 = new QAction(Viewer);
        actionCentral_2->setObjectName(QString::fromUtf8("actionCentral_2"));
        actionNone = new QAction(Viewer);
        actionNone->setObjectName(QString::fromUtf8("actionNone"));
        actionCircle = new QAction(Viewer);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionSquare = new QAction(Viewer);
        actionSquare->setObjectName(QString::fromUtf8("actionSquare"));
        actionShow_information = new QAction(Viewer);
        actionShow_information->setObjectName(QString::fromUtf8("actionShow_information"));
        centralwidget = new QWidget(Viewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(660, 410));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setStyleSheet(QString::fromUtf8("font-family: \"Purisa\";\n"
"background-color: rgb(36, 31, 49);\n"
""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(400, 400));

        gridLayout->addWidget(openGLWidget, 1, 0, 1, 1);

        Viewer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Viewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Viewer->setStatusBar(statusbar);
        menubar = new QMenuBar(Viewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 660, 19));
        menubar->setStyleSheet(QString::fromUtf8("font-family: \"Purisa\";\n"
"background-color: rgb(192, 191, 188);"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 31, 49);\n"
"font-size: 14px;\n"
"color: white;\n"
"selection-background-color: rgb(94, 92, 100);"));
        menuSave_as = new QMenu(menuFile);
        menuSave_as->setObjectName(QString::fromUtf8("menuSave_as"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 31, 49);\n"
"font-size: 14px;\n"
"color: white;\n"
"selection-background-color: rgb(94, 92, 100);"));
        menuSettings_2 = new QMenu(menubar);
        menuSettings_2->setObjectName(QString::fromUtf8("menuSettings_2"));
        menuSettings_2->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 31, 49);\n"
"font-size: 14px;\n"
"color: white;\n"
"selection-background-color: rgb(94, 92, 100);"));
        menuProjection_type_2 = new QMenu(menuSettings_2);
        menuProjection_type_2->setObjectName(QString::fromUtf8("menuProjection_type_2"));
        menuDisplay_method = new QMenu(menuSettings_2);
        menuDisplay_method->setObjectName(QString::fromUtf8("menuDisplay_method"));
        Viewer->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuSettings_2->menuAction());
        menuFile->addAction(actionUpload_file);
        menuFile->addAction(menuSave_as->menuAction());
        menuFile->addAction(actionMake_screencast);
        menuFile->addAction(actionExit);
        menuSave_as->addSeparator();
        menuSave_as->addAction(action_bmp);
        menuSave_as->addAction(action_jpeg);
        menuEdit->addAction(actionRotate_model_2);
        menuEdit->addAction(actionTranslate_model);
        menuEdit->addAction(actionScale_model_2);
        menuSettings_2->addAction(actionEdges_2);
        menuSettings_2->addAction(actionVertices_2);
        menuSettings_2->addAction(actionBackground_2);
        menuSettings_2->addAction(menuDisplay_method->menuAction());
        menuSettings_2->addAction(menuProjection_type_2->menuAction());
        menuSettings_2->addAction(actionShow_information);
        menuProjection_type_2->addAction(actionParallel_2);
        menuProjection_type_2->addAction(actionCentral_2);
        menuDisplay_method->addAction(actionNone);
        menuDisplay_method->addAction(actionCircle);
        menuDisplay_method->addAction(actionSquare);

        retranslateUi(Viewer);

        QMetaObject::connectSlotsByName(Viewer);
    } // setupUi

    void retranslateUi(QMainWindow *Viewer)
    {
        Viewer->setWindowTitle(QCoreApplication::translate("Viewer", "3D Viewer", nullptr));
        actionUpload_file->setText(QCoreApplication::translate("Viewer", "Upload file", nullptr));
#if QT_CONFIG(shortcut)
        actionUpload_file->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("Viewer", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_bmp->setText(QCoreApplication::translate("Viewer", ".bmp", nullptr));
        action_jpeg->setText(QCoreApplication::translate("Viewer", ".jpeg", nullptr));
        actionMake_screencast->setText(QCoreApplication::translate("Viewer", "Make screencast", nullptr));
#if QT_CONFIG(shortcut)
        actionMake_screencast->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRotate_model_2->setText(QCoreApplication::translate("Viewer", "Rotate model", nullptr));
#if QT_CONFIG(shortcut)
        actionRotate_model_2->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTranslate_model->setText(QCoreApplication::translate("Viewer", "Translate model", nullptr));
#if QT_CONFIG(shortcut)
        actionTranslate_model->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionScale_model_2->setText(QCoreApplication::translate("Viewer", "Scale model", nullptr));
#if QT_CONFIG(shortcut)
        actionScale_model_2->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEdges_2->setText(QCoreApplication::translate("Viewer", "Edges", nullptr));
#if QT_CONFIG(shortcut)
        actionEdges_2->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionVertices_2->setText(QCoreApplication::translate("Viewer", "Vertices", nullptr));
#if QT_CONFIG(shortcut)
        actionVertices_2->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBackground_2->setText(QCoreApplication::translate("Viewer", "Set background", nullptr));
#if QT_CONFIG(shortcut)
        actionBackground_2->setShortcut(QCoreApplication::translate("Viewer", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actionParallel_2->setText(QCoreApplication::translate("Viewer", "Parallel", nullptr));
        actionCentral_2->setText(QCoreApplication::translate("Viewer", "Central", nullptr));
        actionNone->setText(QCoreApplication::translate("Viewer", "None", nullptr));
        actionCircle->setText(QCoreApplication::translate("Viewer", "Circle", nullptr));
        actionSquare->setText(QCoreApplication::translate("Viewer", "Square", nullptr));
        actionShow_information->setText(QCoreApplication::translate("Viewer", "Show information", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Viewer", "File", nullptr));
        menuSave_as->setTitle(QCoreApplication::translate("Viewer", "Save as...", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Viewer", "Edit", nullptr));
        menuSettings_2->setTitle(QCoreApplication::translate("Viewer", "Settings", nullptr));
        menuProjection_type_2->setTitle(QCoreApplication::translate("Viewer", "Projection type", nullptr));
        menuDisplay_method->setTitle(QCoreApplication::translate("Viewer", "Display method", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Viewer: public Ui_Viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
