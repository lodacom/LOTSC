//
//  Atome.h
//  LOTS
//
//  Created by Olivier Duplouy on 05/03/13.
//  Copyright (c) 2013 Lolo. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

#include "Sommets.h"
#include "Graphes.h"
#include "Molecules.h"
#include "Liaisons.h"

using namespace std;

#ifndef __LOTS__Atome__
#define __LOTS__Atome__
namespace projet {
    
    class Atomes:Sommets {
    public:
        Atomes(string);
        Atomes(string,Graphes);
        void addArete(Liaisons);
        Molecules getSommet_dans();
        void setSommet_dans(Molecules);
        virtual ~Atomes();
    };
    
}


#endif /* defined(__LOTS__Atome__) */
