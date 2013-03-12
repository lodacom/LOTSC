//
//  Molecules.h
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include <iostream>
#include <string>
#include <set>

#include "Graphes.h"
#include "Liaisons.h"

using namespace std;

#ifndef __LOTS__Molecules__
#define __LOTS__Molecules__

namespace projet {
    
    class Molecules:Graphes {
    public:
        string nom_graphe;
        set<Atomes> sommets;
        set<Liaisons> aretes;
    public:
        Graphes(string);
        Graphes(string,set<Sommets>,set<Aretes>);
        string listeSommets();
        string listeAretes();
        string toString();
        void addArete(Aretes,Sommets,Sommets);
        void addSommet(Sommets,Aretes);
        Aretes deleteArete(Aretes);
        Sommets deleteSommet(Sommets);
        virtual ~Graphes();
    };
    
}

#endif /* defined(__LOTS__Molecules__) */
