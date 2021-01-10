#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include <iostream>
#include "stdio.h"
#include <vector>
using namespace std;
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include "Transform.h"

class GameComponent{
protected:
	GameComponent();
	~GameComponent();
public:

    void virtual input();

    void virtual update();

    void virtual render();
};

#endif // GAMECOMPONENT_H
