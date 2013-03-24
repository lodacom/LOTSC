/*
 * Aretes.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include <iostream>
#include <string>

#include "stdafx.h"

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
    Aretes(string,Graphes*);
    void setSommets(Sommets*,Sommets*);
    Graphes* getArete_dans();
	void setArete_dans(Graphes*);
	string toString();
	virtual ~Aretes();
};

#endif /* ARETES_H_ */
