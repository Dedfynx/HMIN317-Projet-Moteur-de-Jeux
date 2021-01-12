#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include "transform.h"
#include "gameComponent.h"
#include "BoundingBox.h"

class GameObject
{
private:
    std::vector<GameObject*> enfants;
    std::vector<GameComponent*> components;

    //temporaire
    QVector3D position;

public:
    GameObject();
    void update();
    void render(QOpenGLShaderProgram *program,QMatrix4x4 proj, QMatrix4x4 view);

    void addEnfant(GameObject* enfant);
    void addComponent(GameComponent* c);
    void removeEnfant(GameObject* enfant);

    Transform transform;
    Transform localTransform;

    BoundingBox BB;

    QVector3D getPos();
    void setPos(float x,float y,float z);

};



#endif // GAMEOBJECT_H
