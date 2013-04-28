//
//  Noeuds.h
//  LOTSC
//
//  Created by Olivier Duplouy on 26/04/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"
#include "Sommets.h"
#include "Reseaux.h"

#ifndef __LOTSC__Noeuds__
#define __LOTSC__Noeuds__

class Noeuds:public Sommets{
public:
    Noeuds();
    Noeuds(Reseaux*);
    void createArete(Sommets*);
    void createArete(Noeuds*);
    void addArete(Liens*);
    void addArete(Aretes*);
    virtual ~Noeuds();
};

#endif /* defined(__LOTSC__Noeuds__) */
