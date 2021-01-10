#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include <iostream>
#include "stdio.h"
#include <QVector2D>
#include <QVector3D>
#include <QImage>
#include <vector>
using namespace std;

#include "Transform.h"
#include "Mesh.h"
#include "GameComponent.h"

#include <QOpenGLFunctions_3_1>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include <QString>

class MeshRenderer : public GameComponent, protected QOpenGLFunctions_3_1{
private:
	Mesh mesh;

	QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    int nbIndices;

public:
	MeshRenderer(const QString& filename);

	~MeshRenderer();

	void virtual input();

    void virtual update();

	void virtual render(QOpenGLShaderProgram *program);
};

#endif // MESHRENDERER_H