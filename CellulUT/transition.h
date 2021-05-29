#ifndef CELLULUT_TRANSITION_H
#define CELLULUT_TRANSITION_H
#include <sdtio.h>

namespace TRANSITION{
    class Transition{
        private Configuration composante1;
        private Etat composante2;
    
	public void chargerTransition(Configuration config, Etat etat) {
		composante1 = config;
		composante2 = etat;
	}
	public void creerTransition() {
	    Configuration newConfiguration =   ;
		Etat newEtat=  ;
		composante1 = newConfiguration;
		composante2 = newEtat;	
	}
	public void sauvegarderTransition() {
	    chargerConfiguration(compasante1)
	}


    };
#endif //CELLULUT_TRANSITION_H
