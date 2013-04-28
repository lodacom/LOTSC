//
//  GenericAretes.h
//  LOTSC
//
//  Created by Olivier Duplouy on 27/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"

using namespace std;

#ifndef __LOTSC__GenericAretes__
#define __LOTSC__GenericAretes__

template <class G,class S,class A>
class GenericAretes {
public:
    string nom_arete;
	G arete_dans;
	S somm1;
	S somm2;
	static int num;
    //..................................
    GenericAretes();
    GenericAretes(G,S,S);
    void setSommets(S,S);
	void setSommets(S);
    G getArete_dans();
	void setArete_dans(G);
	string toString();
	virtual ~GenericAretes();
};
#endif /* defined(__LOTSC__GenericAretes__) */
