//
//  Molecules.h
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "Graphes.h"
class Atomes;
class Liaisons;

using namespace std;

#ifndef __LOTS__Molecules__
#define __LOTS__Molecules__
    
class Molecules: public Graphes {
public:
	vector<Atomes*> sommets;
	vector<Liaisons*> aretes;
//................................................
	Molecules();
	Molecules(string,vector<Sommets*>,vector<Aretes*>);
    string toString();
	void createSommet();
	void createArete(Sommets*,Sommets*);
	void createArete(Atomes*,Atomes*);
    void addArete(Aretes*,Sommets*,Sommets*);
	void addArete(Liaisons*,Atomes*,Atomes*);
	void addSommet(Sommets*,Aretes*);
	void addSommet(Atomes*);
    void addSommet(Sommets*);
	Aretes* deleteArete(Aretes*);
    Liaisons* deleteArete(Liaisons*);
    Sommets* deleteSommet(Sommets*);
    Atomes* deleteSommet(Atomes*);
	virtual ~Molecules();
};
    

#endif /* defined(__LOTS__Molecules__) */
