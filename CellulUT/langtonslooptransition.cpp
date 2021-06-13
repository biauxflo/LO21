#include "langtonslooptransition.h"
#include <map>
using namespace std;
/*ETAT_NP::Etat &LangtonsLoopTransition::creerTransition(std::vector<ETAT_NP::Etat *> etats, ETAT_NP::Etat &etat, std::vector<CELLULE_NP::Cellule *> voisines, const unsigned int nbVoisines)
{
    CELLULE_NP::Cellule* v= voisines[3];
    voisines[3] = voisines[2];
    voisines[2] = v;
    std::map<std::vector<int>, int>::iterator it = regleLangton.begin();
    
    int count = 0;
    while(it != regleLangton.end()){
        while(count != 4){
            if(etat.getIndice() == (int)it->first.begin() && voisines[0]->getEtat().getIndice() == (int)it->first.begin()+1 && voisines[1]->getEtat().getIndice() == (int)it->first.begin()+2 && voisines[2]->getEtat().getIndice() == (int)it->first.begin()+3 && voisines[3]->getEtat().getIndice() == (int)it->first.begin()+4){
                etat = *etats[it->second];
                voisines[0]->setEtat(*etats[it->second]);
                voisines[1]->setEtat(*etats[it->second]);
                voisines[2]->setEtat(*etats[it->second]);
                voisines[3]->setEtat(*etats[it->second]);
                break;
            }
            count++;
            std::rotate(voisines[0], voisines[1], voisines[3]);
        }
        it++;
    }
    return etat;
}*/
