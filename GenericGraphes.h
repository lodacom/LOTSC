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
    set<S*> sommets;
    set<A*> aretes;
    //...................................
    GenericGraphes();
    string toString();
    string descriptionGraphe();
    virtual void createSommet();
    virtual void createArete(S*,S*);
	void addArete(A*);
	void addArete(A*,S*,S*);
	void addSommet(S*,A*);
	void addSommet(S*);
	A* deleteArete(A*);
	S* deleteSommet(S*);
	virtual ~GenericGraphes();
protected:
	string listeSommets();
	string listeAretes();
private:
    typename set<S*>::iterator itS;
    typename set<A*>::iterator itA;
    string sommetLinkedTo(S*);
};
//.............................................................................................................................
template <class G,class S,class A>
int GenericGraphes<G, S, A>::num;

template <class G,class S,class A>
GenericGraphes<G, S, A>::GenericGraphes(){
    GenericGraphes::num++;
    stringstream s;
    s << "G" << num;
	nom_graphe=s.str();
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::createSommet(){
    
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::createArete(S * p_somm1, S * p_somm2){
    
}

template <class G,class S,class A>
string GenericGraphes<G, S, A>::toString(){
	return "Le graphe "+nom_graphe+" est composé des sommets:\n"
    +listeSommets()+"et des arêtes:\n"+listeAretes();
}

template <class G,class S,class A>
string GenericGraphes<G, S, A>::listeSommets(){
    string ret="";
	if (sommets.size()==0){
		return "aucun sommet";
	}else{
		for (itS=sommets.begin(); itS!=sommets.end();itS++){
			ret+=itS.operator*()->toString()+"\n";
		}
		return ret;
	}
}

template <class G,class S,class A>
string GenericGraphes<G, S, A>::listeAretes(){
    string ret="";
    if (aretes.size()==0){
        return "aucune arêtes";
    }else{
        for (itA=aretes.begin(); itA!=aretes.end();itA++){
            ret+=itA.operator*()->toString()+"\n";
        }
        return ret;
    }
}

template <class G,class S,class A>
string GenericGraphes<G, S, A>::descriptionGraphe(){
    string ret="";
	if (sommets.size()==0){
		return "Le graphe est vide";
	}else{
		for (itS=sommets.begin(); itS!=sommets.end();itS++){
			ret+=itS.operator*()->toString()+" est relié à:\n"+sommetLinkedTo(*itS);
		}
	}
    return ret;
}

template <class G,class S,class A>
string GenericGraphes<G, S, A>::sommetLinkedTo(S* p_sommet){
    string ret="";
    for (p_sommet->itAS=p_sommet->aret_incidents.begin(); p_sommet->itAS!=p_sommet->aret_incidents.end();p_sommet->itAS++){
        if (p_sommet->itAS.operator*()->somm1->nom_sommet!=p_sommet->nom_sommet){
            ret+=p_sommet->itAS.operator*()->somm1->toString()+"\n";
        }else{
            ret+=p_sommet->itAS.operator*()->somm2->toString()+"\n";
        }
    }
    return ret;
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addArete(A* p_arete){
	if (p_arete->getArete_dans()==NULL){
		p_arete->setArete_dans(dynamic_cast<G*>(this));
	}
    aretes.insert(p_arete);
    sommets.insert(p_arete->somm1);
    sommets.insert(p_arete->somm2);
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addArete(A* p_arete,S* p_somm1,S* p_somm2){
	if (p_arete->getArete_dans()==NULL){
        p_arete->setArete_dans(dynamic_cast<G*>(this));
    }
    p_somm1->setSommet_dans(dynamic_cast<G*>(this));
	p_somm2->setSommet_dans(dynamic_cast<G*>(this));
	p_somm1->addArete(p_arete);
	p_somm2->addArete(p_arete);
    p_arete->setSommets(p_somm1, p_somm2);
    //on ajoute l'arête dans le graphe
    aretes.insert(p_arete);
    //on ajoute les sommets dans le graphe
    sommets.insert(p_somm1);
    sommets.insert(p_somm2);
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addSommet(S* p_sommets,A* p_aret) {
    if (p_sommets->getSommet_dans()==NULL){
        p_sommets->setSommet_dans(this);
    }
    p_sommets->addArete(p_aret);
	sommets.insert(p_sommets);
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addSommet(S* p_sommets) {
	if (p_sommets->getSommet_dans()==NULL){
        p_sommets->setSommet_dans(dynamic_cast<G*>(this));
    }
    sommets.insert(p_sommets);
}

template <class G,class S,class A>
A* GenericGraphes<G, S, A>::deleteArete(A* p_arete){
	if (aretes.erase(p_arete)==1){
		//l'arête ne référence plus le graphe
		p_arete->setArete_dans(NULL);
		//l'arête ne référence plus ses deux sommets
		p_arete->setSommets(NULL, NULL);
		return p_arete;
	}else{
		return NULL;
	}
}

template <class G,class S,class A>
S* GenericGraphes<G, S, A>::deleteSommet(S* p_sommet){
	if (sommets.erase(p_sommet)==1){
		p_sommet->setSommet_dans(NULL);
		//le sommet ne référence plus le graphe
		//il faut maintenant supprimer toutes les aretes incidentes
		//du graphe
		while (p_sommet->itAS!=p_sommet->aret_incidents.end()){
			deleteArete(*p_sommet->itAS);
            p_sommet->itAS++;
		}
		return p_sommet;
	}else{
		return NULL;
	}
}

template <class G,class S,class A>
GenericGraphes<G, S, A>::~GenericGraphes() {
    // TODO Auto-generated destructor stub
}
#endif /* defined(__LOTSC__GenericGraphes__) */
