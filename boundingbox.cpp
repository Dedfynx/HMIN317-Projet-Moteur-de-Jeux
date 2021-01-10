#include "boundingbox.h"

BoundingBox::BoundingBox()
{
}

BoundingBox::BoundingBox(float x, float y, float z){
	sizeX=x;
	sizeY=y;
	sizeZ=z;
}

BoundingBox::ChangeBoundingBox(float x, float y, float z){
	sizeX=x;
	sizeY=y;
	sizeZ=z;
}
