//
//  GenericGraphes.h
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"

using namespace std;

#ifndef __LOTSC__GenericGraphes__
#define __LOTSC__GenericGraphes__

template <class G,class S,class A>
class GenericGraphes {
public:
    string nom_graphe;
    static int num;
    vector<S> sommets;
    vector<A> aretes;
    //...................................
    GenericGraphes();
    string toString();
    string descriptionGraphe();
    virtual void createSommet();
    virtual void createArete(S,S);
	void addArete(A);
	void addArete(A,S,S);
	void addSommet(S,A);
	void addSommet(S);
	A deleteArete(A);
	S deleteSommet(S);
	virtual ~GenericGraphes();
protected:
	string listeSommets();
	string listeAretes();
private:
	int rechercheSommet(S);
	int rechercheArete(A);
    bool isAlreadyAdded(A);
    bool isAlreadyAdded(S);
    string sommetLinkedTo(S);
};

#endif /* defined(__LOTSC__GenericGraphes__) */
