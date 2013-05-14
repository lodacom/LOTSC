//
//  Liaisons.cpp
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "stdafx.h"
#include "Liaisons.h"
#include "Sommets.h"
#include "Atomes.h"

Liaisons::Liaisons():Aretes(){}

Liaisons::Liaisons(Molecules* p_graphe,Atomes* p_somm1,Atomes* p_somm2):Aretes(p_graphe,p_somm1,p_somm2){
}

void Liaisons::setSommets(Atomes * p_somm1, Atomes * p_somm2){
    Aretes::setSommets(dynamic_cast<Sommets*>(p_somm1), dynamic_cast<Sommets*>(p_somm2));
}

void Liaisons::setSommets(Sommets * p_somm1, Sommets * p_somm2){
    string typeS1=typeid(*p_somm1).name();
    string typeS2=typeid(*p_somm2).name();
    if (typeS1.find("Sommets")==1 &&
        typeS2.find("Sommets")==1){
        Aretes::setSommets(dynamic_cast<Sommets*>(p_somm1), dynamic_cast<Sommets*>(p_somm2));
    }
}

Liaisons::~Liaisons(){}