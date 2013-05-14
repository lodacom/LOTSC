//
//  GenericSommets.h
//  LOTSC
//
//  Created by Olivier Duplouy on 27/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"

using namespace std;

#ifndef __LOTSC__GenericSommets__
#define __LOTSC__GenericSommets__

template <class G,class S,class A>
class GenericSommets {
public:
    string nom_sommet;
	G sommet_dans;
	vector<A> aret_incidents;
	static int num;
    //.......................................
    GenericSommets();
    GenericSommets(G);
    void addArete(A);
	void addArete(A,S);
    virtual void createArete(S);
    G getSommet_dans();
    void setSommet_dans(G);
	string toString();
	virtual ~GenericSommets();
};

#endif /* defined(__LOTSC__GenericSommets__) */
