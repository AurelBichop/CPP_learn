#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <iostream>
#include "constante.h"

inline void demanderProposition(int& proposition){
    std::cin >> proposition;
}

void jouerTroisParties();
void jouerPartie(int leJustePrix,int max = BORNE_MAX);


#endif // JEU_H_INCLUDED
