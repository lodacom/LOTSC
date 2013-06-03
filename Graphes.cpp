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

string Graphes::toString(){
	return "Le graphe "+nom_graphe+" est composé des sommets:\n"
		+listeSommets()+"et des arêtes:\n"+listeAretes();
}

string Graphes::descriptionGraphe(){
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

string Graphes::sommetLinkedTo(Sommets * p_sommet){
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

string Graphes::listeSommets(){
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

string Graphes::listeAretes(){
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

void Graphes::createSommet(){
	Sommets* s=new Sommets();
	addSommet(s);
}

void Graphes::createArete(Sommets* p_somm1,Sommets* p_somm2){
	Aretes* a=new Aretes();
	addArete(a,p_somm1,p_somm2);
}

void Graphes::addArete(Aretes* p_arete){
	if (p_arete->getArete_dans()==NULL ||
        aretes.find(p_arete)==aretes.end()){
		p_arete->setArete_dans(this);
        
        aretes.insert(p_arete);
        sommets.insert(p_arete->somm1);
        sommets.insert(p_arete->somm2);
	}
}

void Graphes::addArete(Aretes* p_arete,Sommets* p_somm1,Sommets* p_somm2){
	if (p_arete->getArete_dans()==NULL ||
        aretes.find(p_arete)==aretes.end()){
        p_arete->setArete_dans(this);
        
        p_somm1->setSommet_dans(this);
        p_somm2->setSommet_dans(this);
        p_somm1->addArete(p_arete);
        p_somm2->addArete(p_arete);
        p_arete->setSommets(p_somm1, p_somm2);
        //on ajoute l'arête dans le graphe
        aretes.insert(p_arete);
        //on ajoute les sommets dans le graphe
        sommets.insert(p_somm1);
        sommets.insert(p_somm2);
    }
}

void Graphes::addSommet(Sommets* p_sommets,Aretes* p_aret) {
    if (p_sommets->getSommet_dans()==NULL ||
        sommets.find(p_sommets)==sommets.end()){
        p_sommets->setSommet_dans(this);
        
        p_sommets->addArete(p_aret);
        sommets.insert(p_sommets);
    }
}
    
void Graphes::addSommet(Sommets* p_sommets) {
	if (p_sommets->getSommet_dans()==NULL ||
        sommets.find(p_sommets)==sommets.end()){
        p_sommets->setSommet_dans(this);
        
        sommets.insert(p_sommets);
    }
}
    
Aretes* Graphes::deleteArete(Aretes* p_arete){
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

Sommets* Graphes::deleteSommet(Sommets* p_sommet){
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

Graphes::~Graphes() {
    // TODO Auto-generated destructor stub
}
