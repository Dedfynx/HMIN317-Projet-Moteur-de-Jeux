#include "iaennemis.h"

iaEnnemis::iaEnnemis()
{
    inPatrouille = true;
    cpt = 0.0;
    direction = 1.0;
}

bool iaEnnemis::isInPatrouille(){
    return inPatrouille;
}

void iaEnnemis::setPatrouille(bool b){
    inPatrouille = b;
}

float iaEnnemis::getCpt(){
    return cpt;
}

void iaEnnemis::setCpt(float f){
    cpt = f;
}

float iaEnnemis::getNbPas(){
    return nbPas;
}

float iaEnnemis::getDirection(){
    return direction;
}

void iaEnnemis::changeDir(){
    direction = -direction;
}




