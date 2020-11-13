#include <iostream>
#include "stdio.h"
#include <vector>
#include <QMatrix4x4>
using namespace std;

#include "Transformation.h"
#include "GameComponent.h"
#include "GameObject.h"

GameObject::GameObject(){
	childrens = std::vector<GameObject*>();
	components = std::vector<GameComponent*>();
	transformation = Transformation();
}

void GameObject::addChildren(GameObject* o){
	childrens.push_back(o);
}

void GameObject::addComponent(GameComponent* c){
	components.push_back(c);
}

void GameObject::setTransformation(Transformation t){
	transformation=t;
}

Transformation GameObject::getTransformation(){
	return transformation;
}

void GameObject::input(){
	for(GameComponent* component : components){
		component->input(transformation);
		}

	for(GameObject* child : childrens){
		child->input();
	}
}

void GameObject::update(){
	for(GameComponent* component : components){
		component->update(transformation);
	}

	for(GameObject* child : childrens){
		child->update();
	}
}

void GameObject::render(QOpenGLShaderProgram *program,QMatrix4x4 projection, QMatrix4x4 matrix){
	for(GameComponent* component : components){
		component->render(transformation,program,projection,matrix);
}

	for(GameObject* child : childrens){
		child->render(program,projection,matrix);
	}
}


