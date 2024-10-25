QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model.cpp \
    controller.cpp \
    main.cpp \
    openglviewer.cpp \
    viewer.cpp

HEADERS += \
    Model.h \
    VertexData.h \
    controller.h \
    openglviewer.h \
    viewer.h

FORMS += \
    viewer.ui

win32: {
    LIBS += -lOpengl32
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

