/*
 * Graphes.cpp
 *
 *  Created on: 18 févr. 2013
 *      Author: Lolo
 */

#include "Graphes.h"

namespace projet {

    Graphes::Graphes(string p_nom) {
        // TODO Auto-generated constructor stub
        nom_graphe=p_nom;
    }
    
    Graphes::Graphes(string p_nom,set<Sommets> p_sommets,set<Aretes> p_aretes){
        nom_graphe=p_nom;
        sommets=p_sommets;
        aretes=p_aretes;
    }
    
    void Graphes::addArete(Aretes p_arete,Sommets p_somm1,Sommets p_somm2){
        if (p_arete.getArete_dans()==null){
            p_arete.setArete_dans(this);
        }
        p_arete.setSommets(p_somm1, p_somm2);
        //on ajoute l'arête dans le graphe
        aretes.insert(p_arete);
        //il faut maintenant ajouter les sommets de l'arête dans le graphe
        addSommet(p_somm1,p_arete);
        addSommet(p_somm2,p_arete);
    }
    
    void addSommet(Sommets p_sommets,Aretes p_aret) throws ChimereException{
        if (p_sommets.getSommet_dans()==null){
            p_sommets.setSommet_dans(this);
        }
        p_sommets.addArete(p_aret);
        sommets.add(p_sommets);
    }
    
    void addSommet(Sommets p_sommets) throws ChimereException{
        if (p_sommets.getSommet_dans()==null){
            p_sommets.setSommet_dans(this);
        }
        sommets.add(p_sommets);
    }
    
    Aretes deleteArete(Aretes p_arete){
		if (aretes.erase(p_arete)){
			//l'arête ne référence plus le graphe
			p_arete.setArete_dans(null);
			//l'arête ne référence plus ses deux sommets
			p_arete.setSommets(null, null);
			return p_arete;
		}else{
			return null;
		}
	}
    
    Sommets deleteSommet(Sommets p_sommet){
		if (sommets.erase(p_sommet)){
			p_sommet.setSommet_dans(null);
			//le sommet ne référence plus le graphe
			//il faut maintenant supprimer toutes les aretes incidentes
			//du graphe
			iterator<Aretes> i = p_sommet.aret_incidents.begin();
			while (i!=p_sommet.aret_incidents.end()){
				deleteArete(*i);
                i++;
			}
			return p_sommet;
		}else{
			return null;
		}
	}
    
    Graphes::~Graphes() {
        // TODO Auto-generated destructor stub
    }

} /* namespace projet */
