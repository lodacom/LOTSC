//
//  GenericLiens.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 12/05/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "GenericLiens.h"

GenericLiens::GenericLiens():GenericAretes<GenericReseaux, GenericNoeuds, GenericLiens>(){}

/*GenericLiens::GenericLiens(GenericReseaux* p_graphe,GenericNoeuds* p_somm1,GenericNoeuds* p_somm2):GenericAretes(p_graphe,p_somm1,p_somm2){
    
}*/

void GenericLiens::setSommets(GenericNoeuds * p_somm1, GenericNoeuds * p_somm2){
    GenericAretes::setSommets(p_somm1, p_somm2);
}

GenericLiens::~GenericLiens(){}