#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QVector3D>
#include "BasicIO.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>
#include <QFile>
#include <QString>

#include "Mesh.h"

using namespace std;

Mesh::Mesh(const QString& filename){
	//OFFIO::open(filename,points,triangles);

	QFile qFile(filename);
	//qDebug(filename.toLatin1());
    if (!qFile.open(QIODevice::ReadOnly | QIODevice::Text))
       	assert(false);

    QString line = qFile.readLine();
    line = line.chopped(1);

    assert(line == "OFF");

    line = qFile.readLine();
    line = line.chopped(1);
    QStringList fields = line.split(" ");

    int vsize = fields[0].toInt();
    int isize = fields[1].toInt();

    for (int i = 0; i < vsize; ++i)
    {
        line = qFile.readLine();
        line = line.chopped(1);
        fields = line.split(" ");
        float x, y, z;
        x = fields[0].toFloat();
        y = fields[1].toFloat();
        z = fields[2].toFloat();
        QVector3D v = QVector3D(x, y, z);
        points.push_back(v);
    }

    for (int i = 0; i < isize; ++i)
    {
        line = qFile.readLine();
        line = line.chopped(1);
        fields = line.split(" ");
        triangles.push_back(fields[0].toInt());
        triangles.push_back(fields[1].toInt());
        triangles.push_back(fields[2].toInt());
    }

    qFile.close();
}

Mesh::Mesh(){

}