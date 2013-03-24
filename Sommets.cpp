/*
 * Sommets.cpp
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include "Sommets.h"

Sommets::Sommets() {
    num++;
	nom_sommet="S"+num;
    sommet_dans=NULL;
}
    
Sommets::Sommets(string p_nom_sommet,Graphes* p_sommet_dans){
    nom_sommet=p_nom_sommet;
    setSommet_dans(p_sommet_dans);
}
 
void Sommets::setSommet_dans(Graphes* p_sommet_dans){
	sommet_dans=p_sommet_dans;
}

Graphes* Sommets::getSommet_dans() {
	return sommet_dans;
}

Sommets::~Sommets() {
    // TODO Auto-generated destructor stub
}
