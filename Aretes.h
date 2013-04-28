/*
 * Aretes.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include "stdafx.h"

class Sommets;
class Graphes;

using namespace std;

#ifndef ARETES_H_
#define ARETES_H_

class Aretes {
public:
    string nom_arete;
	Graphes* arete_dans;
	Sommets* somm1;
	Sommets* somm2;
	static int num;
//.............................................
	Aretes();
	Aretes(Graphes*,Sommets*,Sommets*);
    void setSommets(Sommets*,Sommets*);
	void setSommets(Sommets*);
    Graphes* getArete_dans();
	void setArete_dans(Graphes*);
	string toString();
	virtual ~Aretes();
};

#endif /* ARETES_H_ */
