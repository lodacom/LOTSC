/*
 * Aretes.h
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */
#include <iostream>
#include <string>

#include "Sommets.h"

using namespace std;

#ifndef ARETES_H_
#define ARETES_H_

namespace projet {

class Aretes {
public:
    string nom_arete;
	Graphes arete_dans;
	Sommets somm1;
	Sommets somm2;
public:
	Aretes(string);
    Aretes(string,Graphes);
    void setSommets(Sommets,Sommets);
    Graphes getArete_dans();
	void setArete_dans(Graphes);
	virtual ~Aretes();
};

} /* namespace projet */
#endif /* ARETES_H_ */
