#include "transform.h"

Transform::Transform()
{

}
void Transform::update(QMatrix4x4 m){
    matriceTransform = m;
}
void Transform::scale(QVector3D s){
    matriceTransform.scale(s);
}
void Transform::translate(QVector3D t){
    matriceTransform.translate(t);
}
void Transform::rotate(QQuaternion r){
    matriceTransform.rotate(r);
}
QMatrix4x4 Transform::getMatrice(){
    return Transform::matriceTransform;
}
