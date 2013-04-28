//
//  Atome.cpp
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "stdafx.h"
#include "Atomes.h"
#include "Sommets.h"
#include "ChimereException.h"

Atomes::Atomes():Sommets(){}

Atomes::Atomes(Molecules* p_graphe):Sommets(p_graphe){}

void Atomes::createArete(Sommets * p_somm2){
    Liaisons* l=new Liaisons();
    addArete(l);
    string typeS2=typeid(p_somm2).name();
    if (typeS2.find("Atomes")){
        l->setSommets(this, p_somm2);
        p_somm2->addArete(l);
    }else{
        throw new ChimereException();
    }
}

void Atomes::createArete(Atomes* p_somm2){
    Liaisons* l=new Liaisons();
    addArete(l);
    l->setSommets(this, p_somm2);
    p_somm2->addArete(l);
}

void Atomes::addArete(Liaisons * p_aret){
    Graphes g;
    g.addArete(p_aret);
}

void Atomes::addArete(Aretes * p_aret){
    string typeA=typeid(p_aret).name();
    if (typeA.find("Liaisons")){
        addArete(dynamic_cast<Liaisons*>(p_aret));
    }else{
        throw new ChimereException();
    }
}

Atomes::~Atomes(){}