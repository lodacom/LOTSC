/*
 * Graphes.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include <iostream>
#include <string>
#include <vector>

#include "Aretes.h"
#include "Sommets.h"

using namespace std;

#ifndef GRAPHES_H_
#define GRAPHES_H_

namespace projet {

class Graphes {
public:
	string nom_graphe;
	vector<Sommets> sommets;
	vector<Aretes> aretes;
	static int num;
public:
	Graphes();
	Graphes(string,set<Sommets>,set<Aretes>);
	string listeSommets();
	string listeAretes();
	string toString();
	void createSommet();
	void createArete(Sommets,Sommets);
	void addArete(Aretes);
	void addArete(Aretes,Sommets,Sommets);
	void addSommet(Sommets,Aretes);
	void addSommet(Sommets);
	Aretes deleteArete(Aretes);
	Sommets deleteSommet(Sommets);
	virtual ~Graphes();
};

} /* namespace projet */
#endif /* GRAPHES_H_ */
