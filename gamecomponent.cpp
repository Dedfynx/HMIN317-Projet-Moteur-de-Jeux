#include <iostream>
#include "stdio.h"
#include <vector>
using namespace std;
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include "Transform.h"
#include "GameComponent.h"

GameComponent::GameComponent(){
}
GameComponent::~GameComponent(){
}


void GameComponent::input(){
	perror("Must not happen !");
}

void GameComponent::update(){
	perror("Must not happen !");
}

void GameComponent::render(QOpenGLShaderProgram *program,QMatrix4x4 mvp){
	perror("Must not happen !");
}