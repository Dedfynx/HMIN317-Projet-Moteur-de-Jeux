#ifndef MESH_H
#define MESH_H

#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector3D>
#include "BasicIO.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>
#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

class Mesh{
public:
	//std::vector<VertexData> points;
	std::vector<QVector3D> points;
	std::vector<GLushort> triangles;

public:
	Mesh();
	Mesh(const QString& filename);

};

#endif // MESH_H
