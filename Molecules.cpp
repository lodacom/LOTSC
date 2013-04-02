//
//  Molecules.cpp
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "stdafx.h"
#include "Molecules.h"
#include "Atomes.h"
#include "Liaisons.h"

Molecules::Molecules():Graphes(){}

Molecules::Molecules(string p_nom,vector<Sommets*> p_sommets,vector<Aretes*> p_aretes):Graphes(p_nom,p_sommets,p_aretes){}

string Molecules::toString(){
	return "La molécule "+Graphes::nom_graphe+" est composé des atomes:"+
		Graphes::listeSommets()+"et des liaisons: "+Graphes::listeAretes();	
}

void Molecules::createSommet(){
	Atomes* a=new Atomes();
	addSommet(a);
}

void Molecules::createArete(Atomes* p_somm1,Atomes* p_somm2){
	Liaisons* l=new Liaisons();
	addArete(l,p_somm1,p_somm2);
}

void Molecules::addArete(Liaisons* p_aret,Atomes* p_somm1,Atomes* p_somm2){
	Graphes::addArete(p_aret,p_somm1,p_somm2);
}

void Molecules::addArete(Aretes* p_aret,Sommets* p_somm1,Sommets* p_somm2){
	cout << typeid(p_aret).name();
}

void Molecules::addSommet(Atomes* p_somm){
}

Molecules::~Molecules(){}