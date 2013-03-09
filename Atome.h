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

#ifndef __LOTS__Atome__
#define __LOTS__Atome__
namespace projet {
    
    class Atome:Sommets {
    public:
        Atome(string);
        Atome(string,Graphes);
        void addArete(Liaisons);
        Molecules getSommet_dans();
        void setSommet_dans(Molecules);
        virtual ~Atome();
    };
    
}


#endif /* defined(__LOTS__Atome__) */
