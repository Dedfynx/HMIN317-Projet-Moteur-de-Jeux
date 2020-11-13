#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include <iostream>
#include "stdio.h"
#include <QVector2D>
#include <QVector3D>
#include <QImage>
#include <vector>
using namespace std;

#include "Transformation.h"
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

	void virtual input(Transformation transformation);

    void virtual update(Transformation transformation);

	void virtual render(Transformation transformation,QOpenGLShaderProgram *program,QMatrix4x4 projection, QMatrix4x4 matrix);
};

#endif // MESHRENDERER_H
