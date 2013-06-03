//
//  GenericReseaux.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 12/05/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "GenericReseaux.h"
#include "GenericLiens.h"

GenericReseaux::GenericReseaux():GenericGraphes<GenericReseaux,GenericNoeuds,GenericLiens>(){}

string GenericReseaux::toString(){
    return "Le reseau generique "+GenericGraphes::nom_graphe+" est compose des noeuds generiques:"+
    GenericGraphes::listeSommets()+"et des liens generiques: "+GenericGraphes::listeAretes();
}

void GenericReseaux::createSommet(){
    GenericNoeuds* a=new GenericNoeuds();
	addSommet(a);
}

void GenericReseaux::createArete(GenericNoeuds * p_somm1, GenericNoeuds * p_somm2){
    GenericLiens* l=new GenericLiens();
	addArete(l,p_somm1,p_somm2);
}

void GenericReseaux::addArete(GenericLiens * p_arete, GenericNoeuds * p_somm1, GenericNoeuds * p_somm2){
    GenericGraphes::addArete(p_arete, p_somm1, p_somm2);
}

void GenericReseaux::addSommet(GenericNoeuds * p_somm){
    GenericGraphes::addSommet(p_somm);
}

GenericLiens* GenericReseaux::deleteArete(GenericLiens * p_aret){
    return GenericGraphes::deleteArete(p_aret);
}

GenericNoeuds* GenericReseaux::deleteSommet(GenericNoeuds * p_somm){
    return GenericGraphes::deleteSommet(p_somm);
}

GenericReseaux::~GenericReseaux(){}