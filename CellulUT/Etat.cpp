#include "Etat.h"

void ETAT_NP::Etat::setIndice(int ind)
{
    indice = ind;
}
void ETAT_NP::Etat::setLabel(std::string lab)
{
    label = lab;
}

void ETAT_NP::Etat::augmenterIndice(){
    indice++;
}
