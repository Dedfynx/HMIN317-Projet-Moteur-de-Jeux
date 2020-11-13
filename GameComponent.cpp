#include <iostream>
#include "stdio.h"
#include <vector>
using namespace std;
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include "Transformation.h"
#include "GameComponent.h"

GameComponent::GameComponent(){
}
GameComponent::~GameComponent(){
}


void GameComponent::input(Transformation transformation){
	perror("Must not happen !");
}

void GameComponent::update(Transformation transformation){
	perror("Must not happen !");
}

void GameComponent::render(Transformation transformation,QOpenGLShaderProgram *program, QMatrix4x4 projection, QMatrix4x4 matrix){
	perror("Must not happen !");
}