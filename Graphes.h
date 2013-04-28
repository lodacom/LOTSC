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
	vector<Sommets*> sommets;
	vector<Aretes*> aretes;
	static int num;
//.......................................................
	Graphes();
	Graphes(string,vector<Sommets*>,vector<Aretes*>);
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
	int rechercheSommet(Sommets*);
	int rechercheArete(Aretes*);
    bool isAlreadyAdded(Aretes*);
    bool isAlreadyAdded(Sommets*);
    string sommetLinkedTo(Sommets*);
};

#endif /* GRAPHES_H_ */
