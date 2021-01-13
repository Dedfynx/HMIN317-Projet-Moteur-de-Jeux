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

    QOpenGLTexture *texture;

public:
	MeshRenderer(const QString& filename,char* pathTexture);
	MeshRenderer(float sizeX,float sizeY,float sizeZ,char* pathTexture); //boite
	MeshRenderer(float sizeX,float sizeY,char* pathTexture); //plan

	~MeshRenderer();

	void virtual input();

    void virtual update();

	void virtual render(QOpenGLShaderProgram *program,QMatrix4x4 mvp);
};

#endif // MESHRENDERER_H
