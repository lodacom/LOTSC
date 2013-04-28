//
//  Atome.h
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"
#include "Sommets.h"
#include "Liaisons.h"
#include "Molecules.h"

using namespace std;

#ifndef __LOTS__Atome__
#define __LOTS__Atome__
    
class Atomes: public Sommets {
public:
    Atomes();
    Atomes(Molecules*);
    void createArete(Sommets*);
    void createArete(Atomes*);
    void addArete(Liaisons*);
    void addArete(Aretes*);
    virtual ~Atomes();
};
    

#endif /* defined(__LOTS__Atome__) */
