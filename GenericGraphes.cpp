//
//  GenericGraphes.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include "GenericGraphes.h"


template <class G,class S,class A>
GenericGraphes<G, S, A>::GenericGraphes(){
    GenericGraphes::num++;
    stringstream s;
    s << "G" << num;
	nom_graphe=s.str();
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
		for (int i=0;i<sommets.size();i++){
			ret+=sommets.at(i)->toString()+"\n";
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
        for (int i=0;i<aretes.size();i++){
            ret+=aretes.at(i)->toString()+"\n";
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
		for (int i=0;i<sommets.size();i++){
			ret+=sommets.at(i)->toString()+" est relié à:\n"+sommetLinkedTo(sommets.at(i));
		}
	}
    return ret;
}

template <class G,class S,class A>
string GenericGraphes<G, S, A>::sommetLinkedTo(S p_sommet){
    string ret="";
    for (int i=0;i<p_sommet->aret_incidents.size();i++){
        if (p_sommet->aret_incidents.at(i)->somm1->nom_sommet!=p_sommet->nom_sommet){
            ret+=p_sommet->aret_incidents.at(i)->somm1->toString()+"\n";
        }else{
            ret+=p_sommet->aret_incidents.at(i)->somm2->toString()+"\n";
        }
    }
    return ret;
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addArete(A p_arete){
	if (p_arete->getArete_dans()==NULL){
		p_arete->setArete_dans(this);
	}
    if (!isAlreadyAdded(p_arete)){
        aretes.push_back(p_arete);
        if (!isAlreadyAdded(p_arete->somm1)){
            sommets.push_back(p_arete->somm1);
        }
        if (!isAlreadyAdded(p_arete->somm2)){
            sommets.push_back(p_arete->somm2);
        }
    }
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addArete(A p_arete,S p_somm1,S p_somm2){
	if (p_arete->getArete_dans()==NULL){
        p_arete->setArete_dans(this);
    }
    p_somm1->setSommet_dans(this);
	p_somm2->setSommet_dans(this);
	p_somm1->addArete(p_arete);
	p_somm2->addArete(p_arete);
    p_arete->setSommets(p_somm1, p_somm2);
    //on ajoute l'arête dans le graphe
    aretes.push_back(p_arete);
    //on ajoute les sommets dans le graphe
    if (!isAlreadyAdded(p_arete->somm1)){
        sommets.push_back(p_somm1);
    }
    if (!isAlreadyAdded(p_arete->somm2)){
        sommets.push_back(p_somm2);
    }
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addSommet(S p_sommets,A p_aret) {
    if (p_sommets->getSommet_dans()==NULL){
        p_sommets->setSommet_dans(this);
    }
    p_sommets->addArete(p_aret);
	sommets.push_back(p_sommets);
}

template <class G,class S,class A>
void GenericGraphes<G, S, A>::addSommet(S p_sommets) {
	if (p_sommets->getSommet_dans()==NULL){
        p_sommets->setSommet_dans(this);
    }
    sommets.push_back(p_sommets);
}

template <class G,class S,class A>
A GenericGraphes<G, S, A>::deleteArete(A p_arete){
	int rech=rechercheArete(p_arete);
	if (rech!=-1){
		aretes.erase(aretes.begin()+rech);
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
S GenericGraphes<G, S, A>::deleteSommet(S p_sommet){
	int rech=rechercheSommet(p_sommet);
	if (rech!=-1){
		sommets.erase(sommets.begin()+rech);
		p_sommet->setSommet_dans(NULL);
		//le sommet ne référence plus le graphe
		//il faut maintenant supprimer toutes les aretes incidentes
		//du graphe
		typename vector<A>::iterator i = p_sommet->aret_incidents.begin();
		while (i!=p_sommet->aret_incidents.end()){
			deleteArete(*i);
            i++;
		}
		return p_sommet;
	}else{
		return NULL;
	}
}

template <class G,class S,class A>
int GenericGraphes<G, S, A>::rechercheArete(A p_arete){
	int i=0;
	while (i<aretes.size() && strcmp(aretes.at(i)->nom_arete.c_str(),p_arete->nom_arete.c_str())!=0){
		i++;
	}
	if (i<aretes.size()){
		return i;
	}else{
		return -1;
	}
}

template <class G,class S,class A>
int GenericGraphes<G, S, A>::rechercheSommet(S p_sommet){
	int i=0;
	while (i<sommets.size() && strcmp(sommets.at(i)->nom_sommet.c_str(),p_sommet->nom_sommet.c_str())!=0){
		i++;
	}
	if (i<sommets.size()){
		return i;
	}else{
		return -1;
	}
}

template <class G,class S,class A>
bool GenericGraphes<G, S, A>::isAlreadyAdded(A p_arete){
    int i=0;
    while (i<aretes.size() && aretes.at(i)->nom_arete!=p_arete->nom_arete){
        i++;
    }
    return (i<aretes.size());
}

template <class G,class S,class A>
bool GenericGraphes<G, S, A>::isAlreadyAdded(S p_sommet){
    int i=0;
    while (i<sommets.size() && sommets.at(i)->nom_sommet!=p_sommet->nom_sommet){
        i++;
    }
    return (i<sommets.size());
}

template <class G,class S,class A>
GenericGraphes<G, S, A>::~GenericGraphes() {
    // TODO Auto-generated destructor stub
}