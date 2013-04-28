//
//  Liaisons.h
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "stdafx.h"
#include "Aretes.h"
#include "Molecules.h"

#ifndef __LOTS__Liaisons__
#define __LOTS__Liaisons__
    
class Liaisons: public Aretes {
public:
	Liaisons();
    Liaisons(Molecules*,Atomes*,Atomes*);
    void setSommets(Atomes*,Atomes*);
    void setSommets(Sommets*,Sommets*);
	virtual ~Liaisons();
};
    


#endif /* defined(__LOTS__Liaisons__) */
