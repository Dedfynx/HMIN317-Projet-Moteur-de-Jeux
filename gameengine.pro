QT       += core gui widgets

TARGET = gameengine
TEMPLATE = app

SOURCES += main.cpp \
    boundingbox.cpp \
    collision.cpp \
    gamecomponent.cpp \
    gameobject.cpp \
    mesh.cpp \
    meshrenderer.cpp \
    transform.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    BasicIO.h \
    boundingbox.h \
    collision.h \
    gamecomponent.h \
    gameobject.h \
    mainwidget.h \
    geometryengine.h \
    mesh.h \
    meshrenderer.h \
    transform.h

RESOURCES += \
    file.qrc \
    shaders.qrc \
    textures.qrc
# install
target.path = $$[YOUR_PATH]
INSTALLS += target

DISTFILES +=
