/*
 * Sommets.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include <iostream>
#include <string>
#include <set>

using namespace std;

#ifndef SOMMETS_H_
#define SOMMETS_H_

namespace projet {

class Sommets {
public:
    string nom_sommet;
	Graphes sommet_dans;
	set<Aretes> aret_incidents;
public:
	Sommets(string);
    Sommets(string,Graphes);
    void addArete(Aretes);
    Graphes getSommet_dans();
    void setSommet_dans(Graphes);
	string toString();
	virtual ~Sommets();
};

} /* namespace projet */
#endif /* SOMMETS_H_ */
