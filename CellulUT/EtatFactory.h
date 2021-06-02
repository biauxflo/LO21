ifndef ETATFACTORY_H
#define ETATFACTORY_H

#include "GenericEtatFactory.h"

class EtatFactory : public GenericEtatFactory{

public:
    Etat makeEtat() override();
};

#endif // ETATFACTORY_H
