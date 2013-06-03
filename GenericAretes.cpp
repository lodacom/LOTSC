//
//  GenericAretes.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 27/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
template <class G,class S,class A>
GenericAretes<G,S,A>::GenericAretes(){
    GenericAretes::num++;
    stringstream s;
    s << "A" << num;
	nom_arete=s.str();
	arete_dans=NULL;
    somm1=NULL;
    somm2=NULL;
}

template <class G,class S,class A>
GenericAretes<G,S,A>::GenericAretes(G* p_arete_dans,S* p_somm1,S* p_somm2){
    num++;
	stringstream s;
    s << "A" << num;
	nom_arete=s.str();
    arete_dans=p_arete_dans;
	somm1=p_somm1;
	somm2=p_somm2;
    somm1->setSommet_dans(p_arete_dans);
    somm2->setSommet_dans(p_arete_dans);
    somm1->addArete(this, somm2);
}

template <class G,class S,class A>
void GenericAretes<G,S,A>::setSommets(S* p_somm1,S* p_somm2){
    somm1=p_somm1;
    somm2=p_somm2;
}

template <class G,class S,class A>
void GenericAretes<G,S,A>::setSommets(S* p_somm){
	if (somm1==NULL){
		somm1=p_somm;
	}else{
		somm2=p_somm;
	}
}

template <class G,class S,class A>
G* GenericAretes<G,S,A>::getArete_dans() {
    return arete_dans;
}

template <class G,class S,class A>
void GenericAretes<G,S,A>::setArete_dans(G* arete_dans) {
	arete_dans = arete_dans;
}

template <class G,class S,class A>
string GenericAretes<G,S,A>::toString(){
	return nom_arete;
}

template <class G,class S,class A>
GenericAretes<G,S,A>::~GenericAretes<G, S, A>() {
    // TODO Auto-generated destructor stub
}

