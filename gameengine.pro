QT       += core gui widgets

TARGET = gameengine
TEMPLATE = app

SOURCES += main.cpp \
    GameComponent.cpp \
    Mesh.cpp \
    MeshRenderer.cpp \
    Transformation.cpp \
    gameobject.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    GameComponent.h \
    GameObject.h \
    Mesh.h \
    MeshRenderer.h \
    Transformation.h \
    gameobject.h \
    mainwidget.h \
    geometryengine.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
target.path = $$[YOUR_PATH]
INSTALLS += target
