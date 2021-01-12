#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "GameComponent.h"


class BoundingBox{
public:
    BoundingBox();
    BoundingBox(float x, float y, float z);

    void changeBoundingBox(float x, float y, float z);

    float sizeX;
    float sizeY;
    float sizeZ;
};

#endif // BOUNDINGBOX_H
