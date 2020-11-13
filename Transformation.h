#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector3D>
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>

class Transformation{
public:
	QMatrix4x4 m;
	
	//QVector3D translation;
	//QVector3D rotation;
	//QVector3D scale;

	//float angle;

public:

	Transformation();

	Transformation(QVector3D t, QQuaternion r, QVector3D s);

	Transformation(QMatrix4x4 m, QVector3D t, QQuaternion r, QVector3D s);

	update(QMatrix4x4 m);

	translate(QVector3D v);

	rotate(QQuaternion r);

	scale(QVector3D s);

	//QMatrix4x4 applyTransformation(QMatrix4x4 m);

	//QVector3D applyToPoint(QVector3D p);

	//QVector3D applyToVector(QVector3D v);
};

#endif // TRANSFORMATION_H
