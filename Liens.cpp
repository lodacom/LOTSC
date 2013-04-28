//
//  Liens.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "Liens.h"
#include "Sommets.h"
#include "Noeuds.h"

Liens::Liens():Aretes(){}

Liens::Liens(Reseaux* p_graphe,Noeuds* p_somm1,Noeuds* p_somm2):Aretes(p_graphe,p_somm1,p_somm2){
}

void Liens::setSommets(Noeuds * p_somm1, Noeuds * p_somm2){
    Aretes::setSommets(dynamic_cast<Sommets*>(p_somm1), dynamic_cast<Sommets*>(p_somm2));
}

void Liens::setSommets(Sommets * p_somm1, Sommets * p_somm2){
    string typeS1=typeid(p_somm1).name();
    string typeS2=typeid(p_somm2).name();
    if (typeS1.find(("Sommets") &&
                    typeS2.find("Sommets"))){
        Aretes::setSommets(dynamic_cast<Sommets*>(p_somm1), dynamic_cast<Sommets*>(p_somm2));
    }
}

Liens::~Liens(){}
