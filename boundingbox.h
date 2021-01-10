#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H


class BoundingBox
{
public:
    BoundingBox();
    BoundingBox(float x, float y, float z);

    ChangeBoundingBox(float x, float y, float z);

    float SizeX;
    float SizeY;
    float SizeZ;
};

#endif // BOUNDINGBOX_H
