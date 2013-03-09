/*
 * Graphes.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include <iostream>
#include <string>
#include <set>

#include "Aretes.h"
#include "Sommets.h"

using namespace std;

#ifndef GRAPHES_H_
#define GRAPHES_H_

namespace projet {

class Graphes {
public:
	string nom_graphe;
	set<Sommets> sommets;
	set<Aretes> aretes;
public:
	Graphes(string);
	Graphes(string,set<Sommets>,set<Aretes>);
	string listeSommets();
	string listeAretes();
	string toString();
	void addArete(Aretes,Sommets,Sommets);
	void addSommet(Sommets,Aretes);
	Aretes deleteArete(Aretes);
	Sommets deleteSommet(Sommets);
	virtual ~Graphes();
};

} /* namespace projet */
#endif /* GRAPHES_H_ */
