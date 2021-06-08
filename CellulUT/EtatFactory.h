#ifndef ETATFACTORY_H
#define ETATFACTORY_H

#include "GenericEtatFactory.h"

class EtatFactory : public GenericEtatFactory{

public:
    ETAT_NP::Etat makeEtat() override();
};

#endif // ETATFACTORY_H
