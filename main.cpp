//
//  main.cpp
//  LOTSC
//
//  Created by Olivier Duplouy on 22/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
//

#include "stdafx.h"
#include "Graphes.h"
#include "Aretes.h"
#include "Sommets.h"
#include "Molecules.h"
#include "Liaisons.h"
#include "Atomes.h"
#include "GenericGraphes.h"
#include "GenericSommets.h"
#include "GenericAretes.h"
#include "ChimereException.h"
#include "GenericReseaux.h"
#include "GenericNoeuds.h"
#include "GenericLiens.h"
using namespace std;

int main( int argc, const char* argv[] )
{
	Graphes* g=new Graphes();
	Sommets* s1=new Sommets();
	Sommets* s2=new Sommets();
    Sommets* s3=new Sommets();
	Aretes* a1=new Aretes();
    Aretes* a2=new Aretes();
    Aretes* a21=new Aretes();
	g->addArete(a1,s1,s2);
    g->addArete(a2,s2,s3);
    g->addArete(a21,s1,s3);
	cout << g->toString() << endl;
    cout << g->descriptionGraphe() << endl;
    
    Molecules* m=new Molecules();
    Sommets* s4=new Atomes();
    Sommets* s5=new Atomes();
    Aretes* a3=new Liaisons();
    try {
        m->addArete(a3, s4, s5);
    } catch (ChimereException ce) {
        cout << ce.what() << endl;
    }
    cout << "......................................................" << endl;
    cout << m->toString() << endl;
    cout << m->descriptionGraphe() << endl;
    
    GenericReseaux* gr=new GenericReseaux();
    GenericNoeuds* gn=new GenericNoeuds();
    GenericNoeuds* gn2=new GenericNoeuds();
    GenericLiens* gl=new GenericLiens();
    
    gr->addArete(gl, gn, gn2);
    cout << "......................................................" << endl;
    cout << gr->toString() << endl;
    cout << gr->descriptionGraphe() << endl;
	return 0;
}
