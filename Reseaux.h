//
//  Reseaux.h
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"
#include "Graphes.h"
class Noeuds;
class Liens;

using namespace std;

#ifndef __LOTSC__Reseaux__
#define __LOTSC__Reseaux__

class Reseaux: public Graphes{
public:

    //................................................
	Reseaux();
    string toString();
	void createSommet();
	void createArete(Sommets*,Sommets*);
	void createArete(Noeuds*,Noeuds*);
    void addArete(Aretes*,Sommets*,Sommets*);
	void addArete(Liens*,Noeuds*,Noeuds*);
	void addSommet(Sommets*,Aretes*);
	void addSommet(Noeuds*);
    void addSommet(Sommets*);
	Aretes* deleteArete(Aretes*);
    Liens* deleteArete(Liens*);
    Sommets* deleteSommet(Sommets*);
    Noeuds* deleteSommet(Noeuds*);
    virtual ~Reseaux();
};

#endif /* defined(__LOTSC__Reseaux__) */
