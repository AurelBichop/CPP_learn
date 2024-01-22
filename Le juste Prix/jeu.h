#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <array>
#include <iostream>
#include "constante.h"

using TableauDeScores = std::array<int,NOMBRE_SCORES>;

inline void demanderProposition(int& proposition){
    std::cin >> proposition;
}

int jouerPartie(int leJustePrix,int max = BORNE_MAX);
void afficherScores(TableauDeScores& scores);

#endif // JEU_H_INCLUDED
