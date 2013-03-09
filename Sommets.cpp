/*
 * Sommets.cpp
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include "Sommets.h"

namespace projet {

    Sommets::Sommets(string p_nom_sommet) {
        nom_sommet=p_nom_sommet;
        sommet_dans=NULL;
    }
    
    Sommets::Sommets(string p_nom_sommet,Graphes p_sommet_dans){
        nom_sommet=p_nom_sommet;
        setSommet_dans(p_sommet_dans);
    }
    
    Sommets::~Sommets() {
        // TODO Auto-generated destructor stub
    }

} /* namespace projet */
