/*
 * Aretes.cpp
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include "stdafx.h"
#include "Aretes.h"
#include "Graphes.h"
#include "Sommets.h"


Aretes::Aretes(){
    num++;
	nom_arete="A"+num;
	arete_dans=NULL;
    somm1=NULL;
    somm2=NULL;
}
    
Aretes::Aretes(string p_nom_arete,Graphes* p_arete_dans){
    nom_arete=p_nom_arete;
    arete_dans=p_arete_dans;
	somm1=NULL;
	somm2=NULL;
}
    
void Aretes::setSommets(Sommets* p_somm1,Sommets* p_somm2){
    somm1=p_somm1;
    somm2=p_somm2;
}

void Aretes::setSommets(Sommets* p_somm){
	if (somm1==NULL){
		somm1=p_somm;
	}else{
		somm2=p_somm;
	}
}

Graphes* Aretes::getArete_dans() {
    return arete_dans;
}
    
void Aretes::setArete_dans(Graphes* arete_dans) {
	arete_dans = arete_dans;
}

string Aretes::toString(){
	return nom_arete;
}

Aretes::~Aretes() {
    // TODO Auto-generated destructor stub
}

