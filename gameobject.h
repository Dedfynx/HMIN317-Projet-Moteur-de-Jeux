#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include "transform.h"

class GameObject
{
private:
    std::vector<GameObject> enfants;

    //temporaire
    std::vector<float> position;

public:
    GameObject();
    void update();
    void render();
    void addEnfant(GameObject enfant);
    Transform transform;

    std::vector<float> getPos();
    void setPos(float x,float y,float z);

};



#endif // GAMEOBJECT_H
