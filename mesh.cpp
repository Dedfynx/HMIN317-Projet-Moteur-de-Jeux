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


//maillage récupéré depuis un fichier
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
        ;
        VertexData p ={QVector3D(x, y, z), QVector2D(0.0f, 0.0f)};
        points.push_back(p);
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

//création du maillage d'une boite
Mesh::Mesh(float sizeX,float sizeY,float sizeZ){

	// Vertex data for face 0
	//face avant

    points.push_back({ QVector3D(0.0,0.0,0.0), QVector2D(0.0f, 0.0f)}); // v0
    points.push_back({ QVector3D(0.0,0.0,sizeZ), QVector2D(1.0f, 0.0f)}); // v1
    points.push_back({ QVector3D(sizeX,0.0,sizeZ), QVector2D(1.0f, 1.0f)});  // v2
    points.push_back({ QVector3D(sizeX,0.0,0.0), QVector2D(0.0, 1.0f)}); // v3

    triangles.push_back(0);
	triangles.push_back(1);
	triangles.push_back(2);
	triangles.push_back(2);
	triangles.push_back(3);
	triangles.push_back(0);


    // Vertex data for face 1
	//face arriere

    points.push_back({ QVector3D(sizeX,-sizeY,0.0), QVector2D( 0.0f, 0.0f)}); // v4
    points.push_back({ QVector3D(sizeX,-sizeY,sizeZ), QVector2D(1.0f, 0.0f)}); // v5
    points.push_back({ QVector3D(0.0,-sizeY,sizeZ), QVector2D(1.0f, 1.0f)});  // v6
    points.push_back({ QVector3D(0.0,-sizeY,0.0), QVector2D(0.0f, 1.0f)}); // v7

	triangles.push_back(4);
	triangles.push_back(5);
	triangles.push_back(6);
	triangles.push_back(6);
	triangles.push_back(7);
	triangles.push_back(4);


    // Vertex data for face 2
	//face gauche

    points.push_back({ QVector3D(0.0,0.0,0.0), QVector2D(0.0f, 0.0f)}); // v8
    points.push_back({ QVector3D(0.0,-sizeY,0.0), QVector2D(1.0f, 0.0f)});  // v9
    points.push_back({ QVector3D(0.0,-sizeY,sizeZ), QVector2D(1.0f, 1.0f)}); // v10
    points.push_back({ QVector3D(0.0,0.0,sizeZ), QVector2D(0.0f, 1.0f)});  // v11

	triangles.push_back(8);
	triangles.push_back(9);
	triangles.push_back(10);
	triangles.push_back(10);
	triangles.push_back(11);
	triangles.push_back(8);

     // Vertex data for face 3
	 //face droite

    points.push_back({ QVector3D(sizeX,0.0,0.0), QVector2D(0.0f, 0.0f)}); // v12
    points.push_back({ QVector3D(sizeX,0.0,sizeZ), QVector2D(1.0f, 0.0f)});  // v13
    points.push_back({ QVector3D(sizeX,-sizeY,sizeZ), QVector2D(1.0f, 1.0f)}); // v14
    points.push_back({ QVector3D(sizeX,-sizeY,0.0), QVector2D(0.0f, 1.0f)});  // v15

	triangles.push_back(12);
	triangles.push_back(13);
	triangles.push_back(14);
	triangles.push_back(14);
	triangles.push_back(15);
	triangles.push_back(12);

    // Vertex data for face 4
	//face dessus

    points.push_back({ QVector3D(0.0,0.0,sizeZ), QVector2D(0.0f, 0.0f)}); // v16
    points.push_back({ QVector3D(0.0,-sizeY,sizeZ), QVector2D(1.0f, 0.0f)}); // v17
    points.push_back({ QVector3D(sizeX,-sizeY,sizeZ), QVector2D(1.0f, 1.0f)}); // v18
    points.push_back({ QVector3D(sizeX,0.0,sizeZ), QVector2D(0.0f, 1.0f)}); // v19

	triangles.push_back(16);
	triangles.push_back(17);
	triangles.push_back(18);
	triangles.push_back(18);
	triangles.push_back(19);
	triangles.push_back(16);

    // Vertex data for face 5
	//face dessous
    points.push_back({ QVector3D(0.0,0.0,0.0), QVector2D(0.0f, 0.0f)}); // v20
    points.push_back({ QVector3D(sizeX,0.0,0.0), QVector2D(1.0f, 0.0f)}); // v21
    points.push_back({ QVector3D(sizeX,-sizeY,0.0), QVector2D(1.0f, 1.0f)}); // v22
    points.push_back({ QVector3D(0.0,-sizeY,0.0), QVector2D(0.0f, 1.0f)}); // v23

	triangles.push_back(20);
	triangles.push_back(21);
	triangles.push_back(22);
	triangles.push_back(22);
	triangles.push_back(23);
	triangles.push_back(20);

}

//création maillage plan
Mesh::Mesh(float sizeX,float sizeY){

	points.push_back({ QVector3D(0.0,0.0,0.0), QVector2D(0.0f, 0.0f)}); // v0
    points.push_back({ QVector3D(0.0,-sizeY,0.0), QVector2D(1.0f, 0.0f)}); // v1
    points.push_back({ QVector3D(sizeX,-sizeY,0.0), QVector2D(1.0f, 1.0f)});  // v2
    points.push_back({ QVector3D(sizeX,0.0,0.0), QVector2D(0.0, 1.0f)}); // v3

    triangles.push_back(0);
    triangles.push_back(1);
    triangles.push_back(2);
    triangles.push_back(2);
    triangles.push_back(3);
    triangles.push_back(0);
}
