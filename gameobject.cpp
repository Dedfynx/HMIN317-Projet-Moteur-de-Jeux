#include "gameobject.h"

GameObject::GameObject()
{
    position.resize(3);
}

void GameObject::update(){

    for(unsigned int i = 0;i<enfants.size();i++){
        enfants[i].transform.update(transform.getMatrice());
        enfants[i].update();
    }

}
void GameObject::render(){

    for(unsigned int i = 0;i<enfants.size();i++){
        enfants[i].render();
    }

}

void  GameObject::addEnfant(GameObject enfant){
    enfants.push_back(enfant);
}


//////////////////////////////////////////
std::vector<float> GameObject::getPos(){
    return position;
}
void GameObject::setPos(float x,float y,float z){
    position.at(0) = x;
    position.at(1) = y;
    position.at(2) = z;

}
