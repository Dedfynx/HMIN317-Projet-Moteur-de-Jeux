#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "stdio.h"
#include <vector>
#include <QMatrix4x4>
using namespace std;

#include "Transformation.h"
#include "GameComponent.h"

class GameObject{
	private:

	std::vector<GameObject*> childrens;
	std::vector<GameComponent*> components;
public:
	Transformation transformation;

	public:

	GameObject();

	void addChildren(GameObject* o);

	void addComponent(GameComponent* c);

	void setTransformation(Transformation t);

	void input();

	void update();

	void render(QOpenGLShaderProgram *program,QMatrix4x4 projection, QMatrix4x4 matrix);

	Transformation getTransformation();

};

#endif // GAMEOBJECT_H
