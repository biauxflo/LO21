#ifndef GENERICETATFACTORY_H
#define GENERICETATFACTORY_H

#include "Etat.h"

class GenericEtatFactory{
public:
    virtual ETAT_NP::Etat makeEtat() = 0;
};

#endif // GENERICETATFACTORY_H
