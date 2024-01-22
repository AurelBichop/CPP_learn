#include "menu.h"

#include <iostream>

using namespace std;

ChoixMenu demanderChoixMenu(){
    char saisieChoix;
    cin >> saisieChoix;

    if(saisieChoix == static_cast<char>(ChoixMenu::JOUER) || static_cast<char>(ChoixMenu::AFFICHER_SCORES) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        return static_cast<ChoixMenu>(saisieChoix);
    }else{
        return ChoixMenu::INCORRECT;
    }
}


void affciherMenu(){
    cout << static_cast<char>(ChoixMenu::JOUER) << " : pour jouer" << endl;
    cout << static_cast<char>(ChoixMenu::AFFICHER_SCORES) << " : pour Afficher les scores" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << " : pour quitter" << endl;
}

