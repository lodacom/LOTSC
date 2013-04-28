//
//  Liens.h
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"
#include "Atomes.h"
#include "Reseaux.h"

#ifndef __LOTSC__Liens__
#define __LOTSC__Liens__

class Liens:public Aretes{
public:
	Liens();
    Liens(Reseaux*,Noeuds*,Noeuds*);
    void setSommets(Noeuds*,Noeuds*);
    void setSommets(Sommets*,Sommets*);
	virtual ~Liens();
};

#endif /* defined(__LOTSC__Liens__) */
