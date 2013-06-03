//
//  Reseaux.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "Reseaux.h"
#include "Noeuds.h"
#include "Liens.h"
#include "ChimereException.h"

Reseaux::Reseaux():Graphes(){}

string Reseaux::toString(){
	return "Le réseau "+Graphes::nom_graphe+" est composé des noeuds:"+
    Graphes::listeSommets()+"et des liens: "+Graphes::listeAretes();
}

void Reseaux::createSommet(){
	Noeuds* a=new Noeuds();
	addSommet(a);
}

void Reseaux::createArete(Noeuds* p_somm1,Noeuds* p_somm2){
	Liens* l=new Liens();
	addArete(l,p_somm1,p_somm2);
}

void Reseaux::createArete(Sommets * p_somm1, Sommets * p_somm2){
    Liens* l=new Liens();
    string typeS1=typeid(*p_somm1).name();
    string typeS2=typeid(*p_somm2).name();
    if (typeS1.find("Noeuds")==1 && typeS2.find("Noeuds")==1){
        addArete(l,p_somm1, p_somm2);
    }else{
        throw new ChimereException();
    }
}

void Reseaux::addArete(Liens* p_aret,Noeuds* p_somm1,Noeuds* p_somm2){
	Graphes::addArete(p_aret,p_somm1,p_somm2);
}

void Reseaux::addArete(Aretes* p_aret,Sommets* p_somm1,Sommets* p_somm2){
    string typeArete=typeid(*p_aret).name();
    string typeS1=typeid(*p_somm1).name();
    string typeS2=typeid(*p_somm2).name();
    if (typeArete.find("Liens")==1 &&
        typeS1.find("Noeuds")==1 &&
        typeS2.find("Noeuds")==1){
        Graphes::addArete(dynamic_cast<Aretes*>(p_aret),dynamic_cast<Sommets*>(p_somm1), dynamic_cast<Sommets*>(p_somm2));
    }else{
        throw new ChimereException();
    }
}

void Reseaux::addSommet(Noeuds* p_somm){
    Graphes::addSommet(p_somm);
}

void Reseaux::addSommet(Sommets* p_somm){
    string typeS=typeid(*p_somm).name();
    if (typeS.find("Noeuds")==1){
        Graphes::addSommet(dynamic_cast<Sommets*>(p_somm));
    }else{
        throw new ChimereException();
    }
}

Aretes* Reseaux::deleteArete(Aretes * p_aret){
    string typeA=typeid(*p_aret).name();
    if (typeA.find("Liens")==1){
        return Graphes::deleteArete(dynamic_cast<Liens*>(p_aret));
    }else{
        return NULL;
    }
}

Liens* Reseaux::deleteArete(Liens* p_arete){
    return dynamic_cast<Liens*>(Graphes::deleteArete(p_arete));
}

Noeuds* Reseaux::deleteSommet(Noeuds * p_somm){
    return dynamic_cast<Noeuds*>(Graphes::deleteSommet(p_somm));
}

Sommets* Reseaux::deleteSommet(Sommets* p_somm){
    string typeS=typeid(*p_somm).name();
    if (typeS.find("Noeuds")==1){
        return Graphes::deleteSommet(dynamic_cast<Sommets*>(p_somm));
    }else{
        return NULL;
    }
}

Reseaux::~Reseaux(){}