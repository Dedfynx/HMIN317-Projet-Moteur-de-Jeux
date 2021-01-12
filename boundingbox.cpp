#include "boundingbox.h"

BoundingBox::BoundingBox()
{
}

BoundingBox::BoundingBox(float x, float y, float z){
	sizeX=x;
	sizeY=y;
	sizeZ=z;
}

void BoundingBox::changeBoundingBox(float x, float y, float z){
	sizeX=x;
	sizeY=y;
	sizeZ=z;
}