#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector3D>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>

#include "Transformation.h"

using namespace std;

Transformation::Transformation(){
}

Transformation::Transformation(QVector3D t, QQuaternion r, QVector3D s){
	m.translate(t);
	m.rotate(r);
	m.scale(s);
}

Transformation::Transformation(QMatrix4x4 m, QVector3D t, QQuaternion r, QVector3D s){
	this->m=m;
	this->m.translate(t);
	this->m.rotate(r);
	this->m.scale(s);
}

Transformation::update(QMatrix4x4 m){
	this->m=m;
}

Transformation::translate(QVector3D v){
	m.translate(v);
}

Transformation::scale(QVector3D s){
	m.scale(s);
}

Transformation::rotate(QQuaternion r){
	m.rotate(r);
}

/*
QMatrix4x4 Transformation::applyTransformation(QMatrix4x4 m){
	m.translate(translation);
	m.rotate(angle,rotation);
	angle+=1.0;

	m.scale(scale);

	return m;
}
*/

/*
QVector3D Transformation::applyToPoint(QVector3D p){
	return m * p;
}

QVector3D Transformation::applyToVector(QVector3D v){
	return m * v;
}
*/