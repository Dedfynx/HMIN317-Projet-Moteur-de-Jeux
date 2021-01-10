#include "gameobject.h"
#include "gameComponent.h"

GameObject::GameObject(){

    enfants = std::vector<GameObject*>();
    components = std::vector<GameComponent*>();
    transform = Transform();

    position.resize(3);
}

void GameObject::update(){
    for(GameObject* enfant : enfants){
        enfant->transform.update(transform.getMatrice());
        enfant->update();
    }

    for(GameComponent* component : components){
        component->update();
    }
}

void GameObject::render(){
    for(GameObject* enfant : enfants){
        enfant->render();
    }

    for(GameComponent* component : components){
        component->render();
    }
}

void  GameObject::addEnfant(GameObject* enfant){
    enfants.push_back(enfant);
}

void GameObject::addComponent(GameComponent* c){
    components.push_back(c);
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
