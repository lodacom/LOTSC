// LOTSC.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Graphes.h"
#include "Aretes.h"
#include "Sommets.h"

using namespace std;

int main( int argc, const char* argv[] )
{
	cout << "Hello World!!" << endl;
	Graphes* g=new Graphes();
	Sommets* s1=new Sommets();
	Sommets* s2=new Sommets();
	Aretes* a=new Aretes(g,s1,s2);
	g->addArete(a);
	cout << g->toString() << endl;
	char* entree="";
	cin >> entree;
	return 0;
}

