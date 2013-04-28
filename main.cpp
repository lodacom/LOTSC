//
//  main.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 22/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

// LOTSC.cpp†: dÈfinit le point d'entrÈe pour l'application console.
//

#include "stdafx.h"
#include "Graphes.h"
#include "Aretes.h"
#include "Sommets.h"
#include "Molecules.h"
#include "Liaisons.h"
#include "Atomes.h"

using namespace std;

int main( int argc, const char* argv[] )
{
	Graphes* g=new Graphes();
	Sommets* s1=new Sommets();
	Sommets* s2=new Sommets();
    Sommets* s3=new Sommets();
	Aretes* a1=new Aretes(g,s1,s2);
    Aretes* a2=new Aretes(g,s2,s3);
	g->addArete(a1);
    g->addArete(a2);
	cout << g->toString() << endl;
    cout << g->descriptionGraphe() << endl;
    Molecules* m=new Molecules();
    s1=new Atomes();
    s2=new Atomes();
    a1=new Liaisons();
    m->addArete(a1, s1, s2);
    
	return 0;
}
