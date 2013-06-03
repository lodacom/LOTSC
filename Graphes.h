/*
 * Graphes.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include "stdafx.h"

class Sommets;
class Aretes;

using namespace std;

#ifndef GRAPHES_H_
#define GRAPHES_H_

class Graphes {
public:
	string nom_graphe;
	set<Sommets*> sommets;
	set<Aretes*> aretes;
	static int num;
//.......................................................
	Graphes();
	string toString();
    string descriptionGraphe();
	void createSommet();
	void createArete(Sommets*,Sommets*);
	void addArete(Aretes*);
	void addArete(Aretes*,Sommets*,Sommets*);
	void addSommet(Sommets*,Aretes*);
	void addSommet(Sommets*);
	Aretes* deleteArete(Aretes*);
	Sommets* deleteSommet(Sommets*);
	virtual ~Graphes();
protected:
	string listeSommets();
	string listeAretes();
private:
    set<Sommets*>::iterator itS;
    set<Aretes*>::iterator itA;
    string sommetLinkedTo(Sommets*);
};

#endif /* GRAPHES_H_ */
