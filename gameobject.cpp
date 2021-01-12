#include "gameobject.h"
#include "gameComponent.h"
#include "BoundingBox.h"

GameObject::GameObject(){

    enfants = std::vector<GameObject*>();
    components = std::vector<GameComponent*>();
    transform = Transform();
    localTransform = Transform();
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

void GameObject::removeEnfant(GameObject *enfant){
    std::vector<GameObject*>::iterator it = std::find(enfants.begin(),enfants.end(),enfant);

    if(it != enfants.end()){
        enfants.erase(it);
    }
}

//////////////////////////////////////////
QVector3D GameObject::getPos(){
    return position;
}
void GameObject::setPos(float x,float y,float z){
    position.setX(x);
    position.setY(y);
    position.setZ(z);

}
