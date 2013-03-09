/*
 * Aretes.cpp
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include "Aretes.h"

namespace projet {

    Aretes::Aretes(string p_nom_arete) {
        nom_arete=p_nom_arete;
        arete_dans=NULL;
        somm1=NULL;
        somm2=NULL;
    }
    
    Aretes::Aretes(String p_nom_arete,Graphes p_arete_dans){
        nom_arete=p_nom_arete;
        arete_dans=p_arete_dans;
        somm1=null;
        somm2=null;
    }
    
    void Aretes::setSommets(Sommets p_somm1,Sommets p_somm2){
        somm1=p_somm1;
        somm2=p_somm2;
    }
	
    Graphes Aretes::getArete_dans() {
        return arete_dans;
    }
    
    void Aretes::setArete_dans(Graphes arete_dans) {
		arete_dans = arete_dans;
    }
    
    Aretes::~Aretes() {
        // TODO Auto-generated destructor stub
    }

} /* namespace projet */
