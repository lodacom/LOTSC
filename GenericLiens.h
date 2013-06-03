//
//  GenericLiens.h
//  LOTSC
//
//  Created by Olivier Duplouy on 12/05/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "GenericAretes.h"
#include "GenericReseaux.h"
#include "GenericNoeuds.h"
//#include "Decorator.h"

#ifndef __LOTSC__GenericLiens__
#define __LOTSC__GenericLiens__

class GenericLiens:public GenericAretes<GenericReseaux,GenericNoeuds,GenericLiens>{
public:
    GenericLiens();
    //GenericLiens(GenericReseaux*,GenericNoeuds*,GenericNoeuds*);
    void setSommets(GenericNoeuds*,GenericNoeuds*);
    virtual ~GenericLiens();
};

#endif /* defined(__LOTSC__GenericLiens__) */
