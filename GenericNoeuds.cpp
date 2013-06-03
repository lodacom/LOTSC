//
//  GenericNoeuds.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 12/05/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "GenericNoeuds.h"
#include "GenericLiens.h"

GenericNoeuds::GenericNoeuds():GenericSommets<GenericReseaux,GenericNoeuds,GenericLiens>(){}

/*GenericNoeuds::GenericNoeuds(GenericReseaux* p_graphe):GenericSommets(p_graphe){
    
}*/

void GenericNoeuds::createArete(GenericNoeuds * p_somm2){
    GenericLiens* a=new GenericLiens();
	a->setSommets(this,p_somm2);
	addArete(a);
	p_somm2->addArete(a);
}

void GenericNoeuds::addArete(GenericLiens * p_aret){
    GenericSommets::addArete(p_aret);
}

GenericNoeuds::~GenericNoeuds(){}