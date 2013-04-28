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
#include "ChimereException.h"

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

void Molecules::createArete(Sommets * p_somm1, Sommets * p_somm2){
    Liaisons* l=new Liaisons();
    string typeS1=typeid(p_somm1).name();
    string typeS2=typeid(p_somm2).name();
    if (typeS1.find("Atomes") && typeS2.find("Atomes")){
        addArete(l,p_somm1, p_somm2);
    }else{
        throw new ChimereException();
    }
}

void Molecules::addArete(Liaisons* p_aret,Atomes* p_somm1,Atomes* p_somm2){
	Graphes::addArete(p_aret,p_somm1,p_somm2);
}

void Molecules::addArete(Aretes* p_aret,Sommets* p_somm1,Sommets* p_somm2){
    string typeArete=typeid(p_aret).name();
    string typeS1=typeid(p_somm1).name();
    string typeS2=typeid(p_somm2).name();
    if (typeArete.find("Liaisons") &&
        typeS1.find("Atomes") &&
        typeS2.find("Atomes")){
        Graphes::addArete(dynamic_cast<Aretes*>(p_aret),dynamic_cast<Sommets*>(p_somm1), dynamic_cast<Sommets*>(p_somm2));
    }else{
        throw new ChimereException();
    }
}

void Molecules::addSommet(Atomes* p_somm){
    Graphes::addSommet(p_somm);
}

void Molecules::addSommet(Sommets* p_somm){
    string typeS=typeid(p_somm).name();
    if (typeS.find("Atomes")){
        Graphes::addSommet(dynamic_cast<Sommets*>(p_somm));
    }else{
        throw new ChimereException();
    }
}

Aretes* Molecules::deleteArete(Aretes * p_aret){
    string typeA=typeid(p_aret).name();
    if (typeA.find("Liaisons")){
        return Graphes::deleteArete(dynamic_cast<Liaisons*>(p_aret));
    }else{
        return NULL;
    }
}

Liaisons* Molecules::deleteArete(Liaisons* p_arete){
    return dynamic_cast<Liaisons*>(Graphes::deleteArete(p_arete));
}

Atomes* Molecules::deleteSommet(Atomes * p_somm){
    return dynamic_cast<Atomes*>(Graphes::deleteSommet(p_somm));
}

Sommets* Molecules::deleteSommet(Sommets* p_somm){
    string typeS=typeid(p_somm).name();
    if (typeS.find("Atomes")){
        return Graphes::deleteSommet(dynamic_cast<Sommets*>(p_somm));
    }else{
        return NULL;
    }
}

Molecules::~Molecules(){}