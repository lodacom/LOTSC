//
//  Noeuds.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "Noeuds.h"
#include "Liens.h"
#include "ChimereException.h"

Noeuds::Noeuds():Sommets(){}

Noeuds::Noeuds(Reseaux* p_graphe):Sommets(p_graphe){}

void Noeuds::createArete(Sommets * p_somm2){
    Liens* l=new Liens();
    addArete(l);
    string typeS2=typeid(p_somm2).name();
    if (typeS2.find("Atomes")){
        l->setSommets(this, p_somm2);
        p_somm2->addArete(l);
    }else{
        throw new ChimereException();
    }
}

void Noeuds::createArete(Noeuds* p_somm2){
    Liens* l=new Liens();
    addArete(l);
    l->setSommets(this, p_somm2);
    p_somm2->addArete(l);
}

void Noeuds::addArete(Liens * p_aret){
    Graphes g;
    g.addArete(p_aret);
}

void Noeuds::addArete(Aretes * p_aret){
    string typeA=typeid(p_aret).name();
    if (typeA.find("Liens")){
        addArete(dynamic_cast<Liens*>(p_aret));
    }else{
        throw new ChimereException();
    }
}

Noeuds::~Noeuds(){}