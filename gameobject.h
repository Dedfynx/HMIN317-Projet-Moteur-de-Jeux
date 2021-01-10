#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include "transform.h"
#include "gameComponent.h"

class GameObject
{
private:
    std::vector<GameObject*> enfants;
    std::vector<GameComponent*> components;

    //temporaire
    std::vector<float> position;

public:
    GameObject();
    void update();
    void render();

    void addEnfant(GameObject* enfant);
    void addComponent(GameComponent* c);

    Transform transform;

    std::vector<float> getPos();
    void setPos(float x,float y,float z);

};



#endif // GAMEOBJECT_H
