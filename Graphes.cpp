/*
 * Graphes.cpp
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include "stdafx.h"
#include "Graphes.h"
#include "Sommets.h"
#include "Aretes.h"

int Graphes::num;

Graphes::Graphes() {
    Graphes::num++;
    stringstream s;
    s << "G" << num;
	nom_graphe=s.str();
}
    
Graphes::Graphes(string p_nom,vector<Sommets*> p_sommets,vector<Aretes*> p_aretes){
    nom_graphe=p_nom;
    sommets=p_sommets;
    aretes=p_aretes;
}

string Graphes::toString(){
	return "Le graphe "+nom_graphe+" est composé des sommets:\n"
		+listeSommets()+"et des arêtes:\n"+listeAretes();
}

string Graphes::descriptionGraphe(){
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

string Graphes::sommetLinkedTo(Sommets * p_sommet){
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

string Graphes::listeSommets(){
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

string Graphes::listeAretes(){
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

void Graphes::createSommet(){
	Sommets* s=new Sommets();
	addSommet(s);
}

void Graphes::createArete(Sommets* p_somm1,Sommets* p_somm2){
	Aretes* a=new Aretes();
	addArete(a,p_somm1,p_somm2);
}

void Graphes::addArete(Aretes* p_arete){
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

void Graphes::addArete(Aretes* p_arete,Sommets* p_somm1,Sommets* p_somm2){
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

void Graphes::addSommet(Sommets* p_sommets,Aretes* p_aret) {
    if (p_sommets->getSommet_dans()==NULL){
        p_sommets->setSommet_dans(this);
    }
    p_sommets->addArete(p_aret);
	sommets.push_back(p_sommets);
}
    
void Graphes::addSommet(Sommets* p_sommets) {
	if (p_sommets->getSommet_dans()==NULL){
        p_sommets->setSommet_dans(this);
    }
    sommets.push_back(p_sommets);
}
    
Aretes* Graphes::deleteArete(Aretes* p_arete){
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
 
int Graphes::rechercheArete(Aretes* p_arete){
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

Sommets* Graphes::deleteSommet(Sommets* p_sommet){
	int rech=rechercheSommet(p_sommet);
	if (rech!=-1){
		sommets.erase(sommets.begin()+rech);
		p_sommet->setSommet_dans(NULL);
		//le sommet ne référence plus le graphe
		//il faut maintenant supprimer toutes les aretes incidentes
		//du graphe
		vector<Aretes*>::iterator i = p_sommet->aret_incidents.begin();
		while (i!=p_sommet->aret_incidents.end()){
			deleteArete(*i);
            i++;
		}
		return p_sommet;
	}else{
		return NULL;
	}
}
 
int Graphes::rechercheSommet(Sommets* p_sommet){
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

bool Graphes::isAlreadyAdded(Aretes * p_arete){
    int i=0;
    while (i<aretes.size() && aretes.at(i)->nom_arete!=p_arete->nom_arete){
        i++;
    }
    return (i<aretes.size());
}

bool Graphes::isAlreadyAdded(Sommets * p_sommet){
    int i=0;
    while (i<sommets.size() && sommets.at(i)->nom_sommet!=p_sommet->nom_sommet){
        i++;
    }
    return (i<sommets.size());
}

Graphes::~Graphes() {
    // TODO Auto-generated destructor stub
}
