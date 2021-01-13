#ifndef IAENNEMIS_H
#define IAENNEMIS_H


class iaEnnemis
{
public:
    iaEnnemis();
    bool isInPatrouille();
    void setPatrouille(bool b);
    float getCpt();
    void setCpt(float f);
    float getNbPas();

    float getDirection();
    void changeDir();

private:
    bool inPatrouille;
    float cpt;
    const float nbPas = 30.0;
    float direction;
};

#endif // IAENNEMIS_H
