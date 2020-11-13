/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwidget.h"
#include "GameObject.h"
#include "GameComponent.h"
#include "MeshRenderer.h"
#include "Transformation.h"

#include <QMouseEvent>
#include <QKeyEvent>

#include <math.h>

MainWidget::MainWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    geometries(0),
    textureCube(0),
    textureGrass(0),
    textureRocks(0),
    textureSnowrocks(0),
    heightmap(nullptr),
    angularSpeed(0)
{
    viewOrbital.rotate(-45.0,1,0,0);
    viewOrbital.translate(0,0,10);

    view.rotate(-45.0,1,0,0);
}

MainWidget::~MainWidget()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();
    delete textureCube;
    delete textureSnowrocks;
    delete textureRocks;
    delete textureGrass;
    delete geometries;
    doneCurrent();
}

//! [0]
void MainWidget::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
}

void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;

    // Rotation axis is perpendicular to the mouse position difference
    // vector
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

    // Accelerate angular speed relative to the length of the mouse sweep
    qreal acc = diff.length() / 100.0;

    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    // Increase angular speed
    angularSpeed += acc;
}
//! [0]

//! [1]
void MainWidget::timerEvent(QTimerEvent *)
{
    // Decrease angular speed (friction)
    angularSpeed *= 0.99;

    //update orbital view rotation
    viewOrbital.rotate(1,0,0,1);


    // Stop rotation when speed goes below threshold
    if (angularSpeed < 0.01) {
        angularSpeed = 0.0;
    } else {
        // Update rotation
        //rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;
        

        // Request an update
   
    }

    rotation=QQuaternion::fromAxisAndAngle(QVector3D(1.0,1.0,1.0),1.0) * rotation;

    update();
}
//! [1]

void MainWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    initShaders();
    initTextures();

//! [2]
    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);
//! [2]

    geometries = new GeometryEngine;

    // Use QBasicTimer because its faster than QTimer
    timer.start(12, this);

    ///////////////////scene graph ////////////////////////////////

    GameComponent* sphere_MeshRenderer1 = new MeshRenderer(":/sphere.off");
    GameComponent* sphere_MeshRenderer2 = new MeshRenderer(":/sphere.off");
    GameComponent* sphere_MeshRenderer3 = new MeshRenderer(":/sphere.off");

    camera = new GameObject();
    Transformation t_camera;
    t_camera.translate(QVector3D(-8.0, -8.0, -30.0));
    camera->setTransformation(t_camera);

    soleil = new GameObject();
    QQuaternion rotationSoleil = QQuaternion::fromAxisAndAngle(QVector3D(1.0,1.0,1.0), 20) * rotation;
    Transformation t_soleil(QVector3D(0.0,0.0,-15.0),rotationSoleil,QVector3D(1.0,1.0,1.0));
    soleil->setTransformation(t_soleil);
    soleil->addComponent(sphere_MeshRenderer1);

    root.addChildren(soleil);

    terre = new GameObject();
    QQuaternion rotationTerre = QQuaternion::fromAxisAndAngle(QVector3D(1.0,1.0,1.0), 20) * rotation;
    Transformation t_terre(soleil->getTransformation().m,QVector3D(5.0,0.0,0.0),rotationTerre,QVector3D(0.5,0.5,0.5));
    terre->setTransformation(t_terre);
    terre->addComponent(sphere_MeshRenderer2);

    soleil->addChildren(terre);

    lune = new GameObject();
    QQuaternion rotationLune = QQuaternion::fromAxisAndAngle(QVector3D(1.0,1.0,1.0), 20) * rotation;
    Transformation t_lune(terre->getTransformation().m, QVector3D(-5.0,0.0,0.0),rotationLune,QVector3D(0.5,0.5,0.5));
    lune->setTransformation(t_lune);
    lune->addComponent(sphere_MeshRenderer3);

    terre->addChildren(lune);
    

    ////////////////////////////////////////////////////////////////
}

//! [3]
void MainWidget::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}
//! [3]

//! [4]
void MainWidget::initTextures()
{
        // Load cube.png image
    textureCube = new QOpenGLTexture(QImage(":/cube.png").mirrored());
        // Set nearest filtering mode for texture minification
    textureCube->setMinificationFilter(QOpenGLTexture::Nearest);

    // Set bilinear filtering mode for texture magnification
    textureCube->setMagnificationFilter(QOpenGLTexture::Linear);

    // Wrap texture coordinates by repeating
    // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
    textureCube->setWrapMode(QOpenGLTexture::Repeat);


    //heightmap
    heightmap = new QOpenGLTexture(QImage(":/heightmap-1024x1024.png").mirrored());
    heightmap->setMinificationFilter(QOpenGLTexture::Nearest);
    heightmap->setMagnificationFilter(QOpenGLTexture::Linear);
    heightmap->setWrapMode(QOpenGLTexture::Repeat);
    

    //load grass image
    textureGrass = new QOpenGLTexture(QImage(":/grass.png").mirrored());
    textureGrass->setMinificationFilter(QOpenGLTexture::Nearest);
    textureGrass->setMagnificationFilter(QOpenGLTexture::Linear);
    textureGrass->setWrapMode(QOpenGLTexture::Repeat);

    //load rocks image
    textureRocks = new QOpenGLTexture(QImage(":/rock.png").mirrored());
    textureRocks->setMinificationFilter(QOpenGLTexture::Nearest);
    textureRocks->setMagnificationFilter(QOpenGLTexture::Linear);
    textureRocks->setWrapMode(QOpenGLTexture::Repeat);


    //load snowrocks image
    textureSnowrocks = new QOpenGLTexture(QImage(":/snowrocks.png").mirrored());
    textureSnowrocks->setMinificationFilter(QOpenGLTexture::Nearest);
    textureSnowrocks->setMagnificationFilter(QOpenGLTexture::Linear);
    textureSnowrocks->setWrapMode(QOpenGLTexture::Repeat);


}
//! [4]

//! [5]
void MainWidget::resizeGL(int w, int h)
{
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 200.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
}
//! [5]

void MainWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //textureCube->bind();
    //textureSnowrocks->bind();
    //textureRocks->bind(); 
    heightmap->bind();
    //textureGrass->bind();

//! [6]
    // Calculate model view transformation
    QMatrix4x4 matrix; //camera
    matrix.translate(-8.0, -8.0, -30.0);
    //matrix.rotate(rotation);


    if(isorbitalView){
        // Set modelview-projection matrix
        program.setUniformValue("mvp_matrix", projection * matrix * viewOrbital);
    }
    else{
        program.setUniformValue("mvp_matrix", projection * matrix * view);
    }

//! [6]

    // Use texture unit 0 which contains cube.png
    program.setUniformValue("texture", 0);

    // Draw cube geometry
    //geometries->drawCubeGeometry(&program);

    //draw plane surface
    //geometries->drawPlaneSurfaceGeometry(&program);

    soleil->transformation.update(root.transformation.m);
    QQuaternion rotationSoleil = QQuaternion::fromAxisAndAngle(QVector3D(1.0,1.0,1.0), 20) * rotation;
    soleil->transformation.translate(QVector3D(0.0,0.0,-15.0));
    soleil->transformation.rotate(rotationSoleil);
    soleil->transformation.scale(QVector3D(1.0,1.0,1.0));

    terre->transformation.update(soleil->transformation.m);
    QQuaternion rotationTerre = QQuaternion::fromAxisAndAngle(QVector3D(1.0,1.0,1.0), 20) * rotation;
    terre->transformation.translate(QVector3D(5.0,0.0,0.0));
    terre->transformation.rotate(rotationTerre);
    terre->transformation.scale(QVector3D(0.5,0.5,0.5));

    lune->transformation.update(terre->transformation.m);
    QQuaternion rotationLune = QQuaternion::fromAxisAndAngle(QVector3D(1.0,1.0,1.0), 20) * rotation;
    lune->transformation.translate(QVector3D(-5.0,0.0,0.0));
    lune->transformation.rotate(rotationLune);
    lune->transformation.scale(QVector3D(0.5,0.5,0.5));


    root.render(&program,projection,matrix);
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    float translate_size=0.5;
    float rotate_size=5.0;

    if(event->key() == Qt::Key_Z){
        view.translate(0.0,-translate_size,0.0); update();
    }
    if(event->key() == Qt::Key_S){
        view.translate(0.0,translate_size,0.0); update();
    }
    if(event->key() == Qt::Key_D){
        view.translate(-translate_size,0.0,0.0); update();
    }
    if(event->key() == Qt::Key_Q){
        view.translate(translate_size,0.0,0.0); update();
    }
    if(event->key() == Qt::Key_Up){
        view.translate(0.0,0.0,translate_size); update();
    }
    if(event->key() == Qt::Key_Down){
        view.translate(0.0,0.0,-translate_size); update();
    }

    if(event->key() == Qt::Key_A){
        view.rotate(-rotate_size,0,0,1); update();
    }
    if(event->key() == Qt::Key_E){
        view.rotate(rotate_size,0,0,1); update();
    }
    if(event->key() == Qt::Key_C){
        if(isorbitalView){
            isorbitalView=false; update();
        }
        else{
            isorbitalView=true;
            update();
        }
    }
}
