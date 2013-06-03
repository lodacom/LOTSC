//
//  GenericNoeuds.h
//  LOTSC
//
//  Created by Olivier Duplouy on 12/05/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//
#include "GenericSommets.h"
#include "GenericReseaux.h"
//#include "Decorator.h"

#ifndef __LOTSC__GenericNoeuds__
#define __LOTSC__GenericNoeuds__


class GenericNoeuds:public GenericSommets<GenericReseaux,GenericNoeuds,GenericLiens>{
public:
    GenericNoeuds();
    //GenericNoeuds(GenericReseaux*);
    void createArete(GenericNoeuds*);
    void addArete(GenericLiens*);
    virtual ~GenericNoeuds();
};

#endif /* defined(__LOTSC__GenericNoeuds__) */
