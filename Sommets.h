/*
 * Sommets.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include "stdafx.h"

class Graphes;
class Aretes;

using namespace std;

#ifndef SOMMETS_H_
#define SOMMETS_H_

class Sommets {
public:
    string nom_sommet;
	Graphes* sommet_dans;
	vector<Aretes*> aret_incidents;
	static int num;
//.......................................
	Sommets();
    Sommets(Graphes*);
    void addArete(Aretes*);
	void addArete(Aretes*,Sommets*);
	void createArete(Sommets*);
    Graphes* getSommet_dans();
    void setSommet_dans(Graphes*);
	string toString();
	virtual ~Sommets();
};

#endif /* SOMMETS_H_ */
