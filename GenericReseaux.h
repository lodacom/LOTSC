//
//  GenericReseaux.h
//  LOTSC
//
//  Created by Olivier Duplouy on 12/05/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"
#include "GenericGraphes.h"
class GenericNoeuds;
class GenericLiens;
using namespace std;

#ifndef __LOTSC__GenericReseaux__
#define __LOTSC__GenericReseaux__

class GenericReseaux: public GenericGraphes<GenericReseaux,GenericNoeuds,GenericLiens>{
public:
	vector<GenericNoeuds*> sommets;
	vector<GenericLiens*> aretes;
    //................................................
	GenericReseaux();
    string toString();
	void createSommet();
	void createArete(GenericNoeuds*,GenericNoeuds*);
	void addArete(GenericLiens*,GenericNoeuds*,GenericNoeuds*);
	void addSommet(GenericNoeuds*);
    GenericLiens* deleteArete(GenericLiens*);
    GenericNoeuds* deleteSommet(GenericNoeuds*);
    virtual ~GenericReseaux();
};

#endif /* defined(__LOTSC__GenericReseaux__) */
