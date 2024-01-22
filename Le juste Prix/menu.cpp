#include "menu.h"

#include <iostream>

using namespace std;

ChoixMenu demanderChoixMenu(){
    char saisieChoix;
    cin >> saisieChoix;

    if(saisieChoix == static_cast<char>(ChoixMenu::JOUER) || static_cast<char>(ChoixMenu::JOUER_FACILE) || static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        return static_cast<ChoixMenu>(saisieChoix);
    }else{
        return ChoixMenu::INCORRECT;
    }
}


void affciherMenu(){
    cout << static_cast<char>(ChoixMenu::JOUER) << " : pour jouer" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_FACILE) << " : pour jouer (facile)" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) << " : pour jouer 3 parties" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << " : pour quitter" << endl;
}

