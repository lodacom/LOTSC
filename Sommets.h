/*
 * Sommets.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include <iostream>
#include <string>

#include "stdafx.h"

using namespace std;

#ifndef SOMMETS_H_
#define SOMMETS_H_

class Sommets {
public:
    string nom_sommet;
	Graphes* sommet_dans;
	vector<Aretes*> aret_incidents;
	static int num;
public:
	Sommets();
    Sommets(string,Graphes*);
    void addArete(Aretes*);
    Graphes* getSommet_dans();
    void setSommet_dans(Graphes*);
	string toString();
	virtual ~Sommets();
};

#endif /* SOMMETS_H_ */
