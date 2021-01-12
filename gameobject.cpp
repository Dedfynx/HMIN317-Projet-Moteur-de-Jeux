#include "gameobject.h"
#include "gameComponent.h"
#include "BoundingBox.h"

GameObject::GameObject(){

    enfants = std::vector<GameObject*>();
    components = std::vector<GameComponent*>();
    transform = Transform();
    localTransform = Transform();

    position.resize(3);
}

void GameObject::update(){
    for(GameObject* enfant : enfants){
        enfant->transform.update(transform.getMatrice() * enfant->localTransform.getMatrice());
        enfant->update();
    }

    for(GameComponent* component : components){
        component->update();
    }
}

void GameObject::render(QOpenGLShaderProgram *program, QMatrix4x4 proj, QMatrix4x4 view){
    for(GameObject* enfant : enfants){
        enfant->render(program,proj,view);
    }

    QMatrix4x4 mvp=proj * view * transform.getMatrice();
    for(GameComponent* component : components){
        component->render(program,mvp);
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
