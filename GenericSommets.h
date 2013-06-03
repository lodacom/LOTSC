//
//  GenericSommets.h
//  LOTSC
//
//  Created by Olivier Duplouy on 27/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"
#include "GenericAretes.h"
using namespace std;

#ifndef __LOTSC__GenericSommets__
#define __LOTSC__GenericSommets__

template <class G,class S,class A>
class GenericSommets {
public:
    string nom_sommet;
	G* sommet_dans;
	set<A*> aret_incidents;
    typename set<A*>::iterator itAS;
	static int num;
    //.......................................
    GenericSommets();
    GenericSommets(G*);
    void addArete(A*);
	void addArete(A*,S*);
    virtual void createArete(S*);
    G* getSommet_dans();
    void setSommet_dans(G*);
	string toString();
	virtual ~GenericSommets();
};
//.............................................................................................................................
template <class G,class S,class A>
int GenericSommets<G, S, A>::num;

template <class G,class S,class A>
void GenericSommets<G,S,A>::createArete(S*){
    
}

template <class G,class S,class A>
GenericSommets<G,S,A>::GenericSommets() {
    GenericSommets::num++;
    stringstream s;
    s << "S" << num;
	nom_sommet=s.str();
    sommet_dans=NULL;
	aret_incidents=set<A*>();
}

template <class G,class S,class A>
GenericSommets<G,S,A>::GenericSommets(G* p_sommet_dans){
    num++;
	stringstream s;
    s << "S" << num;
	nom_sommet=s.str();
    setSommet_dans(p_sommet_dans);
	aret_incidents=set<A*>();
}

template <class G,class S,class A>
string GenericSommets<G,S,A>::toString(){
	return nom_sommet;
}

template <class G,class S,class A>
void GenericSommets<G,S,A>::addArete(A* p_arete){
	aret_incidents.insert(p_arete);
}

template <class G,class S,class A>
void GenericSommets<G,S,A>::addArete(A* p_arete,S* p_somm2){
	p_somm2->addArete(p_arete);
	p_arete->setSommets(this,p_somm2);
	addArete(p_arete);
}

template <class G,class S,class A>
void GenericSommets<G,S,A>::setSommet_dans(G* p_sommet_dans){
	sommet_dans=p_sommet_dans;
}

template <class G,class S,class A>
G* GenericSommets<G,S,A>::getSommet_dans() {
	return sommet_dans;
}

template <class G,class S,class A>
GenericSommets<G,S,A>::~GenericSommets() {
    // TODO Auto-generated destructor stub
}

#endif /* defined(__LOTSC__GenericSommets__) */
