#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QMatrix4x4>

class Transform
{
private :
    QMatrix4x4 matriceTransform;

public:
    Transform();
    void update(QMatrix4x4 m);
    void scale(QVector3D s);
    void translate(QVector3D t);
    void rotate(QQuaternion r);
    QMatrix4x4 getMatrice();
};

#endif // TRANSFORM_H
