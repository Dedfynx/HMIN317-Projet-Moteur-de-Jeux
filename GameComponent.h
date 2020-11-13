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

#include "Transformation.h"

class GameComponent{
protected:
	GameComponent();
	~GameComponent();
public:

    void virtual input(Transformation transformation);

    void virtual update(Transformation transformation);

    void virtual render(Transformation transformation,QOpenGLShaderProgram *program, QMatrix4x4 projection, QMatrix4x4 matrix);
};

#endif // GAMECOMPONENT_H
