/*
 * Sommets.cpp
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include "stdafx.h"
#include "Sommets.h"
#include "Aretes.h"

Sommets::Sommets() {
    num++;
	nom_sommet="S"+num;
    sommet_dans=NULL;
	aret_incidents=vector<Aretes*>();
}
    
Sommets::Sommets(Graphes* p_sommet_dans){
    num++;
	nom_sommet="S"+num;
    setSommet_dans(p_sommet_dans);
	aret_incidents=vector<Aretes*>();
}

string Sommets::toString(){
	return nom_sommet;
}

void Sommets::addArete(Aretes* p_arete){
	aret_incidents.push_back(p_arete);
}

void Sommets::addArete(Aretes* p_arete,Sommets* p_somm2){
	p_somm2->addArete(p_arete);
	p_arete->setSommets(this,p_somm2);
	addArete(p_arete);
}

void Sommets::createArete(Sommets* p_somm2){
	Aretes* a=new Aretes();
	a->setSommets(this,p_somm2);
	addArete(a);
	p_somm2->addArete(a);
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
